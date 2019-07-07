#include "confsetup.h"
#include "ui_confsetup.h"
#include "confentry.h"
#include <QDebug>
#include <QDir>
#include <QSignalMapper>
#include <QTextStream>
#include <QFile>
#include <QScroller>
enum
{
    E_ID,
    E_NAME,
    E_TYPE,
    E_UNITS
};
confsetup::confsetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confsetup)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:black;"
                        "color:white"
                        );

    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet("color: rgb(0, 167, 250);;"
                                   "alternate-background-color: rgb(50, 50, 50);"
                                   "background-color: black;"
                                   "gridline-color: none;"
                                   "border-style: none;"
                                   "QHeaderView::section:vertical{"
                                   "border-left: none;"
                                   "}"
                                   "QHeaderView::section:horizontal{"
                                   "border-top: none;"
                                   "}"
                                   );
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section:horizontal{"
                                                     "background-color: rgb(100, 100, 100);"
                                                     "}");

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    //Scroll
    QScroller *scroller = QScroller::scroller(ui->tableWidget);
    ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

    QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
    QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    properties.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    //Scrolling Gesture
    scroller->grabGesture(ui->tableWidget,QScroller::LeftMouseButtonGesture);

    ui->ButtonBox->setEnabled(false);
    ui->tableWidget->verticalHeader()->hide();
    updateDirList();

    this->move(parent->pos());
    this->show();
}

confsetup::~confsetup()
{
    delete ui;
}

void confsetup::on_add_pushButton_clicked()
{
    confentry dialog;
    dialog.setModal(true);
    dialog.move(this->pos());
    if(dialog.exec() == QDialog::Accepted)
    {
        QStringList values;
        int i = 0;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        values = dialog.get_AllValues();
        for(i = 0; i < values.length(); i++)
        {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(values.at(i)));
        }
    }
}

void confsetup::on_edit_pushButton_clicked()
{
    confentry dialog;
    QStringList values;
    int i = 0;
    dialog.move(this->pos());
    dialog.setModal(true);

    for(i = 0; i < ui->tableWidget->columnCount(); i++)
    {
        if(NULL == ui->tableWidget->item(ui->tableWidget->currentRow(),i))
        {
            values.append("");
        }
        else
        {
            values.append(ui->tableWidget->item(ui->tableWidget->currentRow(),i)->text());
        }
    }

    dialog.set_Values(values);

    if(dialog.exec() == QDialog::Accepted)
    {
        QStringList values;
        values = dialog.get_AllValues();
        for(i = 0; i < values.length(); i++)
        {
            ui->tableWidget->setItem(ui->tableWidget->currentRow(), i, new QTableWidgetItem(values.at(i)));
        }
    }
}

void confsetup::on_remove_pushButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void confsetup::dir_RadioButtonChanged(int opt)
{
    qDebug() << "Option " << opt;
    actual_dir_number = opt;
    ui->ButtonBox->setEnabled(true);
    updateTableFromFile(opt);
}

void confsetup::updateDirList()
{
    int i = 0;
    QRadioButton *choice;
    QSignalMapper *out_choiceMapper = new QSignalMapper(this);


    /* Check Config folder exist, else create*/
    if(false == QDir("conf").exists())
    {
        QDir().mkdir("conf");
    }
    else
    {
        /* Folder exist, check configurations */
        if(QDir().cd("conf"))
        {
            list_dir = QDir("conf").entryList(QDir::Dirs | QDir::NoDotAndDotDot);

            for(i = 0; i < list_dir.length(); i++)
            {
                choice = new QRadioButton(list_dir.at(i));
                ui->DirLayout->addWidget(choice);
                connect(choice, SIGNAL(clicked(bool)), out_choiceMapper, SLOT(map()));
                out_choiceMapper->setMapping(choice, i);
            }

            // Connect all radiobutons to mapper
            connect(out_choiceMapper, SIGNAL(mapped(int)), this, SLOT(dir_RadioButtonChanged(int)));
        }
    }
}

void confsetup::updateTableFromFile(int dir)
{
    QString module_name = "./conf/"+ list_dir.at(dir) + "/conf.csv";
    QStringList values;
    QFile file(module_name);
    int col = 0;

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        // Discard First Line
        stream.readLine();

        while(!stream.atEnd())
        {
            values = stream.readLine().split(",");

            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            for(col = 0; col < values.length(); col++)
            {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, col, new QTableWidgetItem(values.at(col)));
            }
        }

    }
    qDebug() << "File Close";
    file.close();

}

void confsetup::on_save_changes_pushButton_clicked()
{
    QString module_name = "./conf/"+ list_dir.at(actual_dir_number) + "/conf.csv";
    QFile file(module_name);
    int row = 0, col = 0;

    qDebug() << module_name;
    if(file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream stream(&file);
        qDebug() << "file and stream";

        // Add column names
        for(col = 0; col < ui->tableWidget->columnCount(); col++)
        {
            stream << ui->tableWidget->horizontalHeaderItem(col)->text();
            if((col+1) == ui->tableWidget->columnCount())
            {
                stream << "\n";
            }
            else
            {
                stream << ",";
            }
        }

        for(row = 0; row < ui->tableWidget->rowCount(); row++)
        {
            for(col = 0; col < ui->tableWidget->columnCount(); col++)
            {
                stream << ui->tableWidget->item(row,col)->text();
                if((col+1) == ui->tableWidget->columnCount())
                {
                    stream << "\n";
                }
                else
                {
                    stream << ",";
                }
            }
        }
    }
    qDebug() << "File Close";
    file.close();
}

void confsetup::on_closeButton_clicked()
{
    this->close();
}

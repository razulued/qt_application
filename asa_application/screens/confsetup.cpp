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
    ui->tableWidget_2->setAlternatingRowColors(true);
    ui->tableWidget_2->setStyleSheet(ui->tableWidget->styleSheet());
    ui->tableWidget_2->horizontalHeader()->setStyleSheet(ui->tableWidget->horizontalHeader()->styleSheet());
    ui->tableWidget_3->setAlternatingRowColors(true);
    ui->tableWidget_3->setStyleSheet(ui->tableWidget->styleSheet());
    ui->tableWidget_3->horizontalHeader()->setStyleSheet(ui->tableWidget->horizontalHeader()->styleSheet());

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    //Scroll
    setScrollers();

    ui->ButtonBox->setEnabled(false);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget_2->verticalHeader()->hide();
    ui->tableWidget_3->verticalHeader()->hide();

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
        ui->tableWidget->setColumnWidth(0,50);
        ui->tableWidget->resizeRowsToContents();
    }
    file.close();

    module_name = "./conf/"+ list_dir.at(dir) + "/calibration.csv";
    file.setFileName(module_name);
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);
    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        // Discard First Line
        stream.readLine();

        while(!stream.atEnd())
        {
            values = stream.readLine().split(",");

            ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
            for(col = 0; col < values.length(); col++)
            {
                ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1, col, new QTableWidgetItem(values.at(col)));
            }
        }
        ui->tableWidget_2->setColumnWidth(0,50);
        ui->tableWidget_2->setColumnWidth(1,135);
        ui->tableWidget_2->setColumnWidth(2,135);
        ui->tableWidget_2->resizeRowsToContents();
    }
    file.close();

    module_name = "./conf/"+ list_dir.at(dir) + "/alarms.csv";
    file.setFileName(module_name);
    ui->tableWidget_3->clearContents();
    ui->tableWidget_3->setRowCount(0);
    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        // Discard First Line
        stream.readLine();

        while(!stream.atEnd())
        {
            values = stream.readLine().split(",");

            ui->tableWidget_3->insertRow(ui->tableWidget_3->rowCount());
            for(col = 0; col < values.length(); col++)
            {
                ui->tableWidget_3->setItem(ui->tableWidget_3->rowCount()-1, col, new QTableWidgetItem(values.at(col)));
            }
        }
        ui->tableWidget_3->setColumnWidth(0,50);
        ui->tableWidget_3->setColumnWidth(1,135);
        ui->tableWidget_3->setColumnWidth(2,135);
        ui->tableWidget_3->resizeRowsToContents();
    }
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

void confsetup::on_closeButton_2_clicked()
{
    //save and close
    if(!list_dir.isEmpty())
    {
        on_save_changes_pushButton_clicked();
        on_save_changes_pushButton_2_clicked();
        on_save_changes_pushButton_3_clicked();
    }
    this->close();
}

void confsetup::on_save_changes_pushButton_2_clicked()
{

}

void confsetup::on_save_changes_pushButton_3_clicked()
{

}

void confsetup::setScrollers()
{
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

    QScroller *scroller_2 = QScroller::scroller(ui->tableWidget_2);
    ui->tableWidget_2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableWidget_2->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScrollerProperties properties_2 = QScroller::scroller(scroller_2)->scrollerProperties();
    QVariant overshootPolicy_2 = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties_2.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy_2);
    scroller_2->setScrollerProperties(properties_2);
    properties_2.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy_2);
    scroller_2->setScrollerProperties(properties_2);
    //Scrolling Gesture
    scroller_2->grabGesture(ui->tableWidget_2,QScroller::LeftMouseButtonGesture);

    QScroller *scroller_3 = QScroller::scroller(ui->tableWidget_3);
    ui->tableWidget_3->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableWidget_3->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScrollerProperties properties_3 = QScroller::scroller(scroller_3)->scrollerProperties();
    QVariant overshootPolicy_3 = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties_3.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy_3);
    scroller_3->setScrollerProperties(properties_3);
    properties_3.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy_3);
    scroller_3->setScrollerProperties(properties_3);
    //Scrolling Gesture
    scroller_3->grabGesture(ui->tableWidget_3,QScroller::LeftMouseButtonGesture);
}

#include "analisys_full_table.h"
#include "ui_analisys_full_table.h"
#include "clickeablelabel.h"

analisys_full_table::analisys_full_table(QList<QList<float> > master_data, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::analisys_full_table)
{
    ui->setupUi(this);

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,120);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    this->move(parent->pos());


//    ui->tableWidget->setRowCount(11);

    for(int i = 0; i < master_data.length(); i++)
    {
        for(int j = 0; j < master_data.at(0).length(); j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(master_data.at(i).at(j))));
        }
    }

    ui->tableWidget->setColumnWidth(0, 55);
    ui->tableWidget->setColumnWidth(1, 55);
    ui->tableWidget->setColumnWidth(2, 55);
    ui->tableWidget->setColumnWidth(3, 55);
    ui->tableWidget->setColumnWidth(4, 55);
    ui->tableWidget->setColumnWidth(5, 55);
    ui->tableWidget->setColumnWidth(6, 55);
    ui->tableWidget->setColumnWidth(7, 55);
    ui->tableWidget->setColumnWidth(8, 55);
    ui->tableWidget->setColumnWidth(9, 55);
    ui->tableWidget->setColumnWidth(10, 55);


    this->show();
}

analisys_full_table::~analisys_full_table()
{
    delete ui;
}

void analisys_full_table::background_clicked()
{
    this->close();
}

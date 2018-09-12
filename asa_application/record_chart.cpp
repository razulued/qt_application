#include "record_chart.h"
#include "ui_record_chart.h"

record_chart::record_chart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::record_chart)
{
    ui->setupUi(this);
}

record_chart::~record_chart()
{
    delete ui;
}

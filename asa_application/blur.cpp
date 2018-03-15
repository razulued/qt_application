#include "blur.h"
#include "ui_blur.h"

blur::blur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blur)
{
    ui->setupUi(this);
}

blur::~blur()
{
    delete ui;
}

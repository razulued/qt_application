#include "mainmenu.h"
#include "ui_mainmenu.h"

mainmenu::mainmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

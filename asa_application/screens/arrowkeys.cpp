#include "arrowkeys.h"
#include "ui_arrowkeys.h"
#include "clickeablelabel.h"

#define INC (10)
arrowkeys::arrowkeys(QWidget *frame, QWidget *main_window) :
    ui(new Ui::arrowkeys)
{
    ui->setupUi(this);

    frame_to_move = frame;

    this->setObjectName("MyArrows");
    this->setStyleSheet("#MyArrows{background-color: black;"
                        "border: none;}");

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,120);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    this->move(main_window->pos());
    this->show();

}

arrowkeys::~arrowkeys()
{
    delete ui;
}

void arrowkeys::background_clicked()
{
    this->close();
}

void arrowkeys::on_key_up_clicked()
{
    frame_to_move->move(frame_to_move->x(), frame_to_move->y() - INC);
}

void arrowkeys::on_key_down_clicked()
{
    frame_to_move->move(frame_to_move->x(), frame_to_move->y() + INC);
}

void arrowkeys::on_key_left_clicked()
{
    frame_to_move->move(frame_to_move->x() - INC, frame_to_move->y());
}

void arrowkeys::on_key_rigth_clicked()
{
    frame_to_move->move(frame_to_move->x() + INC, frame_to_move->y());
}

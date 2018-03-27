#include "mod_4_clorador.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"

mod_4_clorador::mod_4_clorador(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    original_pos = parent->pos();
//    parent_label->setStyleSheet("background-image: url(:/reactor/images/2_Reactor/reactor.png); ");

    load_new_gif(CLORADOR_GIF_STATE_MOV);

    this->show();
}

mod_4_clorador::~mod_4_clorador()
{
}

void mod_4_clorador::load_new_gif(uint state)
{
    QMovie *mv;

    switch (state)
    {
    case CLORADOR_GIF_STATE_NONE:
        mv = new QMovie(":/clorador/images/4_Clorador/chlorination_empty.png");
        break;
    case CLORADOR_GIF_STATE_MOV:
        mv = new QMovie(":/clorador/images/4_Clorador/chlorination_mov.gif");
        parent_label->setGeometry(original_pos.x()-2, original_pos.y()-1, parent_label->width(), parent_label->height());
        break;
    case CLORADOR_GIF_STATE_QUIET:
        mv = new QMovie(":/clorador/images/4_Clorador/chlorination_quiet.png");
//        parent_label->setGeometry(original_pos.x()-7, original_pos.y()-2, parent_label->width(), parent_label->height());
        break;
    default:
        mv = new QMovie(":/clorador/images/4_Clorador/chlorination_empty.png");
        break;
    }

    parent_label->setAttribute(Qt::WA_NoSystemBackground);
    mv->start();
    parent_label->setMovie(mv);

}

void mod_4_clorador::check_update_animation()
{
    uint reactor_motores = 0;

    reactor_motores |= getParamValue(92).toInt();
    reactor_motores |= getParamValue(102).toInt();
    reactor_motores |= getParamValue(112).toInt();

    if(reactor_motores > 0)
    {
        load_new_gif(CLORADOR_GIF_STATE_MOV);
    }
    else
    {
        load_new_gif(CLORADOR_GIF_STATE_QUIET);
    }
}

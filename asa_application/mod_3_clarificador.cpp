#include "mod_3_clarificador.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"

mod_3_clarificador::mod_3_clarificador(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    original_pos = parent->pos();
//    parent_label->setStyleSheet("background-image: url(:/reactor/images/2_Reactor/reactor.png); ");

    load_new_gif(CLARIFICADOR_GIF_STATE_FULL_MOV);

    this->show();
}

mod_3_clarificador::~mod_3_clarificador()
{
}

void mod_3_clarificador::load_new_gif(uint state)
{
    QMovie *mv;

    switch (state)
    {
    case CLARIFICADOR_GIF_STATE_NONE:
        mv = new QMovie(":/clarificador/images/3_Clarificador/clarifier.png");
        break;
    case CLARIFICADOR_GIF_STATE_FULL_MOV:
        mv = new QMovie(":/clarificador/images/3_Clarificador/clarifier_full_mov.gif");
        parent_label->setGeometry(original_pos.x()-7, original_pos.y()-2, parent_label->width(), parent_label->height());
        break;
    case CLARIFICADOR_GIF_STATE_FULL_QUIET:
        mv = new QMovie(":/clarificador/images/3_Clarificador/clarifier_full_quiet.png");
        parent_label->setGeometry(original_pos.x()-7, original_pos.y()-2, parent_label->width(), parent_label->height());
        break;
    default:
        mv = new QMovie(":/clarificador/images/3_Clarificador/clarifier.png");
        break;
    }

    parent_label->setAttribute(Qt::WA_NoSystemBackground);
    mv->start();
    parent_label->setMovie(mv);

}

void mod_3_clarificador::check_update_animation()
{
    uint reactor_motores = 0;

    reactor_motores |= getParamValue(92).toInt();
    reactor_motores |= getParamValue(102).toInt();
    reactor_motores |= getParamValue(112).toInt();

    if(reactor_motores > 0)
    {
        load_new_gif(CLARIFICADOR_GIF_STATE_FULL_MOV);
    }
    else
    {
        load_new_gif(CLARIFICADOR_GIF_STATE_FULL_QUIET);
    }
}
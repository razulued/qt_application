#include "mod_3_clarificador.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"
#include <QDebug>

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

    if(last_state != state)
    {
        switch (state)
        {
        case CLARIFICADOR_GIF_STATE_NONE:
            mv = new QMovie(":/gifs/3 Clarificador/screen800x600/gifs/3 Clarificador/clarifier vacio.png");
            break;
        case CLARIFICADOR_GIF_STATE_FULL_MOV:
            mv = new QMovie(":/gifs/3 Clarificador/screen800x600/gifs/3 Clarificador/clarifier mov.gif");
//            parent_label->setGeometry(original_pos.x()-7, original_pos.y()-2, parent_label->width(), parent_label->height());
            break;
        case CLARIFICADOR_GIF_STATE_FULL_QUIET:
            mv = new QMovie(":/gifs/3 Clarificador/screen800x600/gifs/3 Clarificador/clarifier quiet.png");
//            parent_label->setGeometry(original_pos.x()-7, original_pos.y()-2, parent_label->width(), parent_label->height());
            break;
        default:
            mv = new QMovie(":/clarificador/images/3_Clarificador/clarifier.png");
            break;
        }

        parent_label->setAttribute(Qt::WA_NoSystemBackground);
        mv->setCacheMode(QMovie::CacheAll);
        mv->start();
        parent_label->setMovie(mv);

        last_state = state;
        update_window();
    }

}

void mod_3_clarificador::check_update_animation()
{
    uint reactor_motores = 0;

    if(1 == getParamValue(0x4000).toInt())
    {
        reactor_motores |=1;
    }
    if(1 == getParamValue(0x4010).toInt())
    {
        reactor_motores |=1;
    }
    if(1 == getParamValue(0x4020).toInt())
    {
        reactor_motores |=1;
    }
    if(1 == getParamValue(0x4030).toInt())
    {
        reactor_motores |=1;
    }

    if(reactor_motores & 0x01)
    {
        load_new_gif(CLARIFICADOR_GIF_STATE_FULL_MOV);
    }
    else
    {
        load_new_gif(CLARIFICADOR_GIF_STATE_FULL_QUIET);
    }
}

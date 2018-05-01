#include "mod_2_reactor.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"
#include <QDebug>
mod_2_reactor::mod_2_reactor(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    original_pos = parent->pos();
//    parent_label->setStyleSheet("background-image: url(:/reactor/images/2_Reactor/reactor.png); ");

    load_new_gif(REACTOR_GIF_STATE_HI_MOV);

    this->show();
}

mod_2_reactor::~mod_2_reactor()
{
}

void mod_2_reactor::load_new_gif(uint state)
{
    QMovie *mv;

    if(last_state != state)
    {
        switch (state)
        {
        case REACTOR_GIF_STATE_NONE:
            mv = new QMovie(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reactor vacio.png");
            break;
        case REACTOR_GIF_STATE_HI_QUIET:
            mv = new QMovie(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac hi quiet water 03.png");
//            parent_label->setGeometry(original_pos.x()-2, original_pos.y()-1, parent_label->width(), parent_label->height());
            break;
        case REACTOR_GIF_STATE_HI_MOV:
            mv = new QMovie(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac hi mov water 03.gif");
//            parent_label->setGeometry(original_pos.x()+10, original_pos.y()+3, parent_label->width(), parent_label->height());
            break;
        case REACTOR_GIF_STATE_MED_QUIET:
            mv = new QMovie(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac med quiet water 02.png");
            break;
        case REACTOR_GIF_STATE_MED_MOV:
//            parent_label->setGeometry(original_pos.x()+7, original_pos.y()+15, parent_label->width(), parent_label->height());
            mv = new QMovie(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac med mov water 02.fw.gif");
            break;
        case REACTOR_GIF_STATE_LOW_QUIET:
            mv = new QMovie(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac low quiet water 01.png");
            //No position change
            break;
        case REACTOR_GIF_STATE_LOW_MOV:
            mv = new QMovie(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac low mov water 01.gif");
//            parent_label->setGeometry(original_pos.x(), original_pos.y()+20, parent_label->width(), parent_label->height());
            break;
        default:
            mv = new QMovie(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reactor vacio.png");
            break;
        }

        parent_label->setAttribute(Qt::WA_NoSystemBackground);
        mv->start();
        parent_label->setMovie(mv);

        last_state = state;
        update_window();
    }

}

void mod_2_reactor::check_update_animation()
{
    uint reactor_motores = 0;

    reactor_motores |= getParamValue(0x4000).toInt();
    reactor_motores |= getParamValue(0x4010).toInt();
    reactor_motores |= getParamValue(0x4020).toInt();
    reactor_motores |= getParamValue(0x4030).toInt();

    if(reactor_motores > 0)
    {
        load_new_gif(REACTOR_GIF_STATE_HI_MOV);
    }
    else
    {
        load_new_gif(REACTOR_GIF_STATE_HI_QUIET);
    }
}

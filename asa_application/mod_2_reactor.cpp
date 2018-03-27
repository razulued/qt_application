#include "mod_2_reactor.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"

mod_2_reactor::mod_2_reactor(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    original_pos = parent->pos();
//    parent_label->setStyleSheet("background-image: url(:/reactor/images/2_Reactor/reactor.png); ");

    load_new_gif(REACTOR_GIF_STATE_HI_QUIET);

    this->show();
}

mod_2_reactor::~mod_2_reactor()
{
}

void mod_2_reactor::load_new_gif(uint state)
{
    QMovie *mv;

    switch (state)
    {
    case REACTOR_GIF_STATE_NONE:
        mv = new QMovie(":/reactor/images/2_Reactor/reactor.png");
        break;
    case REACTOR_GIF_STATE_HI_QUIET:
        mv = new QMovie(":/reactor/images/2_Reactor/reac_hi_quiet_water.png");
        parent_label->setGeometry(original_pos.x()-2, original_pos.y()-1, parent_label->width(), parent_label->height());
        break;
    case REACTOR_GIF_STATE_HI_MOV:
        mv = new QMovie(":/reactor/images/2_Reactor/reac_hi_mov_water.gif");
        parent_label->setGeometry(original_pos.x()+10, original_pos.y()+3, parent_label->width(), parent_label->height());
        break;
    case REACTOR_GIF_STATE_MED_QUIET:
        mv = new QMovie(":/reactor/images/2_Reactor/reac_med_quiet_water_02.png");
        break;
    case REACTOR_GIF_STATE_MED_MOV:
        parent_label->setGeometry(original_pos.x()+7, original_pos.y()+15, parent_label->width(), parent_label->height());
        mv = new QMovie(":/reactor/images/2_Reactor/reac_med_mov_water_02.gif");
        break;
    case REACTOR_GIF_STATE_LOW_QUIET:
        mv = new QMovie(":/reactor/images/2_Reactor/reac_low_quiet_water_01.png");
        //No position change
        break;
    case REACTOR_GIF_STATE_LOW_MOV:
        mv = new QMovie(":/reactor/images/2_Reactor/reac_low_mov_water_01.gif");
        parent_label->setGeometry(original_pos.x(), original_pos.y()+20, parent_label->width(), parent_label->height());
        break;
    default:
        mv = new QMovie(":/reactor/images/2_Reactor/reactor.png");
        break;
    }

    parent_label->setAttribute(Qt::WA_NoSystemBackground);
    mv->start();
    parent_label->setMovie(mv);

}

void mod_2_reactor::check_update_animation()
{
    uint reactor_motores = 0;

    reactor_motores |= getParamValue(92).toInt();
    reactor_motores |= getParamValue(102).toInt();
    reactor_motores |= getParamValue(112).toInt();

    if(reactor_motores > 0)
    {
        load_new_gif(REACTOR_GIF_STATE_HI_MOV);
    }
    else
    {
        load_new_gif(REACTOR_GIF_STATE_HI_QUIET);
    }
}

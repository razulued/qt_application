#include "mod_5_digestor.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"

mod_5_digestor::mod_5_digestor(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    original_pos = parent->pos();
//    parent_label->setStyleSheet("background-image: url(:/reactor/images/2_Reactor/reactor.png); ");

    load_new_gif(DIGESTOR_GIF_STATE_HI_MOV);

    this->show();
}

mod_5_digestor::~mod_5_digestor()
{
}

void mod_5_digestor::load_new_gif(uint state)
{
    QMovie *mv;

    if(last_state != state)
    {
        switch (state)
        {
        case DIGESTOR_GIF_STATE_NONE:
            mv = new QMovie(":/gifs/5 Digestor/screen800x600/gifs/5 Digestor/digester empty.png");
            break;
        case DIGESTOR_GIF_STATE_HI_QUIET:
            mv = new QMovie(":/gifs/5 Digestor/screen800x600/gifs/5 Digestor/03 digester hi quiet.png");
            break;
        case DIGESTOR_GIF_STATE_HI_MOV:
            mv = new QMovie(":/gifs/5 Digestor/screen800x600/gifs/5 Digestor/03 digester hi mov water.gif");
            break;
        case DIGESTOR_GIF_STATE_MED_QUIET:
            mv = new QMovie(":/gifs/5 Digestor/screen800x600/gifs/5 Digestor/02 digester med quiet.png");
            break;
        case DIGESTOR_GIF_STATE_MED_MOV:
            mv = new QMovie("::/gifs/5 Digestor/screen800x600/gifs/5 Digestor/02 digester med mov water.gif");
            break;
        case DIGESTOR_GIF_STATE_LOW_QUIET:
            mv = new QMovie(":/gifs/5 Digestor/screen800x600/gifs/5 Digestor/01 digester low quiet.png");
            //No position change
            break;
        case DIGESTOR_GIF_STATE_LOW_MOV:
            mv = new QMovie(":/gifs/5 Digestor/screen800x600/gifs/5 Digestor/01 digester low mov water.gif");
            break;
        default:
            mv = new QMovie(":/gifs/5 Digestor/screen800x600/gifs/5 Digestor/03 digester hi quiet.png");
            break;
        }

        parent_label->setAttribute(Qt::WA_NoSystemBackground);
        mv->start();
        parent_label->setMovie(mv);

        last_state = state;
        update_window();
    }

}

void mod_5_digestor::check_update_animation()
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
        load_new_gif(DIGESTOR_GIF_STATE_HI_MOV);
    }
    else
    {
        load_new_gif(DIGESTOR_GIF_STATE_HI_QUIET);
    }
}

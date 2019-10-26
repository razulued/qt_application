#include "mod_1_regulador.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"
#include <QDebug>

mod_1_regulador::mod_1_regulador(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    //parent_label->setStyleSheet("background-image: url(:/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo vacio.png); ");

    load_new_gif(REGULADOR_GIF_STATE_NONE);

    this->show();
}

mod_1_regulador::~mod_1_regulador()
{
}

void mod_1_regulador::load_new_gif(uint state)
{
    QMovie *mv;

    if(last_state != state)
    {
        switch (state)
        {
        case REGULADOR_GIF_STATE_NONE:
            mv = new QMovie(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo vacio.png");
            break;
        case REGULADOR_GIF_STATE_HI_QUIET:
            mv = new QMovie(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo hi quiet water.png");
            break;
        case REGULADOR_GIF_STATE_HI_MOV:
            mv = new QMovie(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo hi mov water_.gif");
            break;
        case REGULADOR_GIF_STATE_MED_QUIET:
            mv = new QMovie(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo med quiet water_.png");
            break;
        case REGULADOR_GIF_STATE_MED_MOV:
            mv = new QMovie(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo med mov water.gif");
            break;
        case REGULADOR_GIF_STATE_LOW_QUIET:
            mv = new QMovie(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo low quiet water_.png");
            break;
        case REGULADOR_GIF_STATE_LOW_MOV:
            mv = new QMovie(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo low mov water.gif");
            break;
        default:
            mv = new QMovie(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo vacio.png");
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

void mod_1_regulador::check_update_animation()
{
    uint carcamo_motores = 0;
    float carcamo_nivel = 0;

    if(1 == getParamValue(0x3800).toInt())
    {
        carcamo_motores |=1;
    }
    if(1 == getParamValue(0x3810).toInt())
    {
        carcamo_motores |=1;
    }

    carcamo_nivel = getParamValue(0x3A01).toFloat();

    if(carcamo_motores & 0x01)
    {
        // One or more motors are ON
        if(carcamo_nivel < 0.5)
        {
            load_new_gif(REGULADOR_GIF_STATE_NONE);
        }
        else if(carcamo_nivel < 1)
        {
            load_new_gif(REGULADOR_GIF_STATE_LOW_MOV);
        }
        else if(carcamo_nivel < 3)
        {
            load_new_gif(REGULADOR_GIF_STATE_MED_MOV);
        }
        else
        {
            load_new_gif(REGULADOR_GIF_STATE_HI_MOV);
        }
    }
    else
    {
        // One or more motors are ON
        if(carcamo_nivel < 0.5)
        {
            load_new_gif(REGULADOR_GIF_STATE_NONE);
        }
        else if(carcamo_nivel < 1)
        {
            load_new_gif(REGULADOR_GIF_STATE_LOW_QUIET);
        }
        else if(carcamo_nivel < 3)
        {
            load_new_gif(REGULADOR_GIF_STATE_MED_QUIET);
        }
        else
        {
            load_new_gif(REGULADOR_GIF_STATE_HI_QUIET);
        }
    }
}

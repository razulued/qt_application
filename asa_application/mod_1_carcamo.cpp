#include "mod_1_carcamo.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"
#include <QDebug>

mod_1_carcamo::mod_1_carcamo(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    parent_label->setStyleSheet("background-image: url(:/carcamo/images/1_Carcamo/carcamo_vacio.png); ");

    load_new_gif(CARCAMO_GIF_STATE_NONE);

    this->show();
}

mod_1_carcamo::~mod_1_carcamo()
{
}

void mod_1_carcamo::load_new_gif(uint state)
{
    QMovie *mv;

    switch (state)
    {
    case CARCAMO_GIF_STATE_NONE:
        mv = new QMovie(":/carcamo/images/1_Carcamo/carcamo_vacio.png");
        break;
    case CARCAMO_GIF_STATE_HI_QUIET:
        mv = new QMovie(":/carcamo/images/1_Carcamo/carcamo_hi_quiet_water.png");
        break;
    case CARCAMO_GIF_STATE_HI_MOV:
        mv = new QMovie(":/carcamo/images/1_Carcamo/carcamo_hi_mov_water.gif");
        break;
    case CARCAMO_GIF_STATE_MED_QUIET:
        mv = new QMovie(":/carcamo/images/1_Carcamo/carcamo_med_quiet water.png");
        break;
    case CARCAMO_GIF_STATE_MED_MOV:
        mv = new QMovie(":/carcamo/images/1_Carcamo/carcamo_med_mov water.gif");
        break;
    case CARCAMO_GIF_STATE_LOW_QUIET:
        mv = new QMovie(":/carcamo/images/1_Carcamo/carcamo_low_quiet_water.png");
        break;
    case CARCAMO_GIF_STATE_LOW_MOV:
        mv = new QMovie(":/carcamo/images/1_Carcamo/carcamo_low_mov_water.gif");
        break;
    default:
        mv = new QMovie(":/carcamo/images/1_Carcamo/carcamo_vacio.png");
        break;
    }

    parent_label->setAttribute(Qt::WA_NoSystemBackground);
    mv->start();
    parent_label->setMovie(mv);

}

void mod_1_carcamo::check_update_animation()
{
    uint carcamo_motores = 0;
    uint carcamo_nivel = 0;

    carcamo_motores |= getParamValue(44).toInt();
    carcamo_motores |= getParamValue(54).toInt();

    carcamo_nivel = getParamValue(40).toInt();

    if(carcamo_motores)
    {
        // One or more motors are ON
        if(carcamo_nivel < 10)
        {
            load_new_gif(CARCAMO_GIF_STATE_NONE);
        }
        else if(carcamo_nivel < 30)
        {
            load_new_gif(CARCAMO_GIF_STATE_LOW_MOV);
        }
        else if(carcamo_nivel < 60)
        {
            load_new_gif(CARCAMO_GIF_STATE_MED_MOV);
        }
        else
        {
            load_new_gif(CARCAMO_GIF_STATE_HI_MOV);
        }
    }
    else
    {
        // One or more motors are ON
        if(carcamo_nivel < 10)
        {
            load_new_gif(CARCAMO_GIF_STATE_NONE);
        }
        else if(carcamo_nivel < 30)
        {
            load_new_gif(CARCAMO_GIF_STATE_LOW_QUIET);
        }
        else if(carcamo_nivel < 60)
        {
            load_new_gif(CARCAMO_GIF_STATE_MED_QUIET);
        }
        else
        {
            load_new_gif(CARCAMO_GIF_STATE_HI_QUIET);
        }
    }
}

#include "mod_flechas.h"
#include <QMovie>
#include "parameters.h"
#include <QDebug>

mod_flechas::mod_flechas(arrow_type_t type, uint state, QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;
    arrow_type = type;
    original_pos = parent->pos();

    load_new_gif(arrow_type, state);

    last_state = state;

    this->show();
}


mod_flechas::~mod_flechas()
{

}


void mod_flechas::load_new_gif(arrow_type_t type, uint state)
{
    if(last_state != state)
    {
        switch(type)
        {
        case SLUDGE_1:
            if(ARRW_SLUDGE_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 01  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 01 quiet.png");
            }
            break;
        case SLUDGE_2:
            if(ARRW_SLUDGE_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 02  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 02 quiet.png");
            }
            break;
        case SLUDGE_3:
            if(ARRW_SLUDGE_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 03  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 03 quiet.png");
            }
            break;
        case SLUDGE_4:
            if(ARRW_SLUDGE_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 04  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 04 quiet.png");
            }
            break;
        case SLUDGE_RETURN:
            if(ARRW_SLUDGE_RETURN_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge return mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge return.png");
            }
            break;
        case WATER_FLOWN_1:
            if(ARRW_WATER_FLOWN_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow 01  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow 01 quiet.png");
            }
            break;
        case WATER_FLOWN_2:
            if(ARRW_WATER_FLOWN_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow 02  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow 02 quiet.png");
            }
            break;
        case WATER_FLOWN_3:
            if(ARRW_WATER_FLOWN_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow 03  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow 03 quiet.png");
            }
            break;
        case WATER_FLOWN_4:
            if(ARRW_WATER_FLOWN_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow 04  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow 04 quiet.png");
            }
            break;
        case AFLUENTE_1:
            if(ARRW_AFLUENTE_GIF_STATE_MOV == state)
            {
//                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow influent 01 mov.gif");
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge_flow_influent_01_mov_small.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png");
            }
            break;
        case AFLUENTE_2:
            if(ARRW_AFLUENTE_GIF_STATE_MOV == state)
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow influent 02  mov.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png");
            }
            break;
        case EFLUENTE_1:
            if(ARRW_EFLUENTE_GIF_STATE_MOV == state)
            {
//                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow effluent 02 mov.gif");
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water_flow_effluent_02_mov_small.gif");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png");
            }
            break;
        case BLOWER:
            if(1 == state)
            {
                mv = new QMovie(":/gifs/0 Equipos/screen800x600/gifs/0 Equipos/Blower Jet On.png");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Equipos/screen800x600/gifs/0 Equipos/Blower Jet off.png");
            }
            break;
        case CARCAMO_MOTOR:
            if(1 == state)
            {
                mv = new QMovie(":/gifs/0 Equipos/screen800x600/gifs/0 Equipos/pump on.png");
            }
            else
            {
                mv = new QMovie(":/gifs/0 Equipos/screen800x600/gifs/0 Equipos/pump off.png");
            }
            break;
        default:
            mv = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png");
            break;
        }

        parent_label->setAttribute(Qt::WA_NoSystemBackground);
        mv->start();
        parent_label->setMovie(mv);

        last_state = state;
        update_window();
    }
}

void mod_flechas::check_update_animation()
{
    if(AFLUENTE_1 == arrow_type)
    {
        uint caudal_in = getParamValue(0x3203).toInt();
        if(caudal_in > 0)
        {
            load_new_gif(arrow_type, ARRW_AFLUENTE_GIF_STATE_MOV);
        }
        else
        {
            load_new_gif(arrow_type, ARRW_AFLUENTE_GIF_STATE_QUIET);
        }
    }
    else if(EFLUENTE_1 == arrow_type)
    {
        uint caudal_out = getParamValue(0x6203).toInt();

        if(caudal_out > 0)
        {
            load_new_gif(arrow_type, ARRW_EFLUENTE_GIF_STATE_MOV);
        }
        else
        {
            load_new_gif(arrow_type, ARRW_EFLUENTE_GIF_STATE_QUIET);
        }
    }
    else if(SLUDGE_RETURN == arrow_type)
    {
        uint retorno_lodo = getParamValue(0x5201).toInt();

        if(retorno_lodo > 0)
        {
            load_new_gif(arrow_type, ARRW_SLUDGE_RETURN_GIF_STATE_MOV);
        }
        else
        {
            load_new_gif(arrow_type, ARRW_SLUDGE_RETURN_GIF_STATE_QUIET);
        }
    }
    else if(BLOWER == arrow_type)
    {
        uint reactor_motores = 0;
        reactor_motores |= getParamValue(0x4000).toInt();
        reactor_motores |= getParamValue(0x4010).toInt();
        reactor_motores |= getParamValue(0x4020).toInt();
        reactor_motores |= getParamValue(0x4030).toInt();

        if(reactor_motores > 0)
        {
            load_new_gif(arrow_type, 1);
        }
        else
        {
            load_new_gif(arrow_type, 0);
        }
    }
    else if(CARCAMO_MOTOR == arrow_type)
    {
        uint carcamo_motores = 0;
        carcamo_motores |= getParamValue(0x3000).toInt();
        carcamo_motores |= getParamValue(0x3010).toInt();
        if(carcamo_motores > 0)
        {
            load_new_gif(arrow_type, 1);
        }
        else
        {
            load_new_gif(arrow_type, 0);
        }
    }
}

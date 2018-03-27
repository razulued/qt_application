#include "mod_flechas.h"
#include <QMovie>
#include "parameters.h"

mod_flechas::mod_flechas(arrow_type_t type, uint state, QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;
    arrow_type = type;
    original_pos = parent->pos();

    load_new_gif(arrow_type, state);

    this->show();
}


mod_flechas::~mod_flechas()
{

}


void mod_flechas::load_new_gif(arrow_type_t type, uint state)
{
    QMovie *mv;

    switch(type)
    {
    case SLUDGE_1:
        if(ARRW_SLUDGE_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_01_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_01_quiet.png");
        }
        break;
    case SLUDGE_2:
        if(ARRW_SLUDGE_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_02_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_02_quiet.png");
        }
        break;
    case SLUDGE_3:
        if(ARRW_SLUDGE_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_03_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_03_quiet.png");
        }
        break;
    case SLUDGE_4:
        if(ARRW_SLUDGE_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_04_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_04_quiet.png");
        }
        break;
    case SLUDGE_RETURN:
        if(ARRW_SLUDGE_RETURN_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_return_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_return.png");
        }
        break;
    case WATER_FLOWN_1:
        if(ARRW_WATER_FLOWN_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_01_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_01_quiet.png");
        }
        break;
    case WATER_FLOWN_2:
        if(ARRW_WATER_FLOWN_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_02_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_02_quiet.png");
        }
        break;
    case WATER_FLOWN_3:
        if(ARRW_WATER_FLOWN_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_03_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_03_quiet.png");
        }
        break;
    case WATER_FLOWN_4:
        if(ARRW_WATER_FLOWN_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_04_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_04_quiet.png");
        }
        break;
    case AFLUENTE_1:
        if(ARRW_AFLUENTE_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_influent_01_mov_small.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/none.png");
        }
        break;
    case AFLUENTE_2:
        if(ARRW_AFLUENTE_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_influent_02_mov.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/none.png");
        }
        break;
    case EFLUENTE_1:
        if(ARRW_EFLUENTE_GIF_STATE_MOV == state)
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/water_flow_effluent_02_mov_small.gif");
        }
        else
        {
            mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/none.png");
        }
        break;
    case BLOWER:
        if(1 == state)
        {
            mv = new QMovie(":/equipos/images/0_Equipos/Blower_Jet_On.png");
        }
        else
        {
            mv = new QMovie(":/equipos/images/0_Equipos/Blower_Jet_off.png");
        }
        break;
    case CARCAMO_MOTOR:
        if(1 == state)
        {
            mv = new QMovie(":/equipos/images/0_Equipos/pump_on.png");
        }
        else
        {
            mv = new QMovie(":/equipos/images/0_Equipos/pump_off.png");
        }
        break;
    default:
        mv = new QMovie(":/flechas/images/0_Flechas_de_flujo/sludge_flow_01_quiet.png");
        break;
    }

    parent_label->setAttribute(Qt::WA_NoSystemBackground);
    mv->start();
    parent_label->setMovie(mv);
}

void mod_flechas::check_update_animation()
{
    if(AFLUENTE_1 == arrow_type)
    {
        uint caudal_in = getParamValue(43).toInt();

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
        uint caudal_out = getParamValue(162).toInt();

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
        uint retorno_lodo = getParamValue(145).toInt();

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
        uint retorno_lodo = getParamValue(92).toInt();

        if(retorno_lodo > 0)
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
        uint estado_motor = getParamValue(44).toInt();

        if(estado_motor > 0)
        {
            load_new_gif(arrow_type, 1);
        }
        else
        {
            load_new_gif(arrow_type, 0);
        }
    }
}

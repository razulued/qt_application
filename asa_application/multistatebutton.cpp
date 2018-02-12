#include "multistatebutton.h"

static multi_button_state_t parameter_state[TOTAL_TYPES_PARAM];
static QPushButton *button_link[TOTAL_TYPES_PARAM];
static parameters_t selected_parameter = PARAM_ELECTRIC;



static void setBorderImage(QString *img, QPushButton *btn);
static void setState(multi_button_state_t state, parameters_t parameter);

const multi_button_icons_t icon_path[TOTAL_TYPES_PARAM]=
{
    /*Electrical*/
    {   ":/iconos/images/Iconos/Clavija_azul.png",
        ":/iconos/images/Iconos/Clavija_blanco.png",
        ":/iconos/images/Iconos/Clavija_amarillo.png",
        ":/iconos/images/Iconos/Clavija_rojo.png",
    },
    /*Physical*/
    {
        ":/iconos/images/Iconos/Medidor_azul.png",
        ":/iconos/images/Iconos/Medidor_blanco.png",
        ":/iconos/images/Iconos/Medidor_amarillo.png",
        ":/iconos/images/Iconos/Medidor_rojo.png",
    },
    /*Chemical*/
    {
        ":/iconos/images/Iconos/Matraz_azul.png",
        ":/iconos/images/Iconos/Matraz_blanco.png",
        ":/iconos/images/Iconos/Matraz_amarillo.png",
        ":/iconos/images/Iconos/Matraz_rojo.png",
    },
};

void InitButtons(QPushButton *elec, QPushButton *fis, QPushButton *chem)
{
    button_link[PARAM_ELECTRIC] = elec;
    button_link[PARAM_PHYSHIC] = fis;
    button_link[PARAM_CHEMIC] = chem;

    UpdateButtons();
}

void UpdateButtons()
{
    //Electric
    int i = 0;

    for(i = 0; i < TOTAL_TYPES_PARAM; i++)
    {
        if(STATE_NORMAL == parameter_state[i])
        {
            setState(STATE_NORMAL, (parameters_t)i);
        }

        if(STATE_FAILED == parameter_state[i])
        {
            setState(STATE_FAILED, (parameters_t)i);
        }

        if(STATE_WARNING == parameter_state[i])
        {
            setState(STATE_WARNING, (parameters_t)i);
        }
    }
}

//background-image: url(:/iconos/images/Iconos/Medidor_azul.png);
//border: none;
//background-repeat: none;
//background-position: center;

static void setBorderImage(QString *img, QPushButton *btn)
{
    btn->setStyleSheet("background-image: url("+*img+");"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
}

static void setState(multi_button_state_t state, parameters_t parameter)
{
    QString *ico_ptr;

    switch(state)
    {
    case STATE_NORMAL:
        if(selected_parameter == parameter)
        {
            ico_ptr = (QString *)&icon_path[parameter].ico_pressed;
        }
        else
        {
            ico_ptr = (QString *)&icon_path[parameter].ico_normal;
        }
    break;

    case STATE_WARNING:
        ico_ptr = (QString *)&icon_path[parameter].ico_warning;
    break;

    case STATE_FAILED:
        ico_ptr = (QString *)&icon_path[parameter].ico_failed;
    break;

    default:

    break;
    }

    setBorderImage(ico_ptr, button_link[parameter]);
}



void SelectParemeter(parameters_t param)
{
    selected_parameter = param;
    UpdateButtons();
}

#include "multistatebutton.h"

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

MultiStateButton::MultiStateButton(multi_button_state_t init, paremeters_t param, QPushButton *parent) : QPushButton(parent)
{
    parameter = param;
    setState(init);
}

MultiStateButton::~MultiStateButton()
{

}

void MultiStateButton::setBorderImage(QString *img)
{
    this->setStyleSheet("border-image: url("+*img+");");
}

void MultiStateButton::setState(multi_button_state_t state)
{
    button_state = state;

    QString *ico_ptr;

    switch(state)
    {
    case STATE_NORMAL:
        ico_ptr = (QString *)&icon_path[parameter].ico_normal;
    break;

    case STATE_PRESSED:
        ico_ptr = (QString *)&icon_path[parameter].ico_pressed;
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

    setBorderImage(ico_ptr);
}

multi_button_state_t MultiStateButton::getState()
{
    return STATE_PRESSED;
}
 void MultiStateButton::setParam(paremeters_t param)
 {
     parameter = param;
 }

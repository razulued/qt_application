#ifndef MULTISTATEBUTTON_H
#define MULTISTATEBUTTON_H

#include <QObject>
#include <QPushButton>

typedef enum
{
    PARAM_ELECTRIC,
    PARAM_PHYSHIC,
    PARAM_CHEMIC,
    TOTAL_TYPES_PARAM
}parameters_t;

typedef enum
{
    STATE_NORMAL,
    STATE_WARNING,
    STATE_FAILED,
    NUMBER_OF_BUTTON_STATES
}multi_button_state_t;

typedef struct
{
    QString ico_normal;
    QString ico_pressed;
    QString ico_warning;
    QString ico_failed;
}multi_button_icons_t;

void InitButtons(QPushButton *elec, QPushButton *fis, QPushButton *chem);
void UpdateButtons();

void SelectParemeter(parameters_t param);
parameters_t GetParemeter();

#endif // MULTISTATEBUTTON_H

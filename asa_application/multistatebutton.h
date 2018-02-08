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
}paremeters_t;

typedef enum
{
    STATE_NORMAL,
    STATE_PRESSED,
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


class MultiStateButton : public QPushButton
{
    Q_OBJECT

public:
    MultiStateButton(multi_button_state_t init, paremeters_t param, QPushButton *parent = 0);
    ~MultiStateButton();
    multi_button_state_t getState();
    void setState(multi_button_state_t state);
    void setParam(paremeters_t param);

private:
    void setBorderImage(QString *img);
    multi_button_state_t button_state;
    paremeters_t parameter;

};

#endif // MULTISTATEBUTTON_H

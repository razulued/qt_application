#ifndef MOD_1_REGULADOR_H
#define MOD_1_REGULADOR_H

#include <QLabel>

enum
{
    REGULADOR_GIF_STATE_NONE,
    REGULADOR_GIF_STATE_HI_QUIET,
    REGULADOR_GIF_STATE_HI_MOV,
    REGULADOR_GIF_STATE_MED_QUIET,
    REGULADOR_GIF_STATE_MED_MOV,
    REGULADOR_GIF_STATE_LOW_QUIET,
    REGULADOR_GIF_STATE_LOW_MOV,
};

class mod_1_regulador : public QWidget
{
    Q_OBJECT

public:
    explicit mod_1_regulador(QLabel *parent = 0);
    void check_update_animation();
    ~mod_1_regulador();

private:
    void load_new_gif(uint state);

    QLabel *parent_label;
    uint last_state = 0xFF;

signals:
    void update_window();
};

#endif // MOD_1_CARCAMO_H

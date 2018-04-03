#ifndef MOD_1_CARCAMO_H
#define MOD_1_CARCAMO_H

#include <QLabel>

enum
{
    CARCAMO_GIF_STATE_NONE,
    CARCAMO_GIF_STATE_HI_QUIET,
    CARCAMO_GIF_STATE_HI_MOV,
    CARCAMO_GIF_STATE_MED_QUIET,
    CARCAMO_GIF_STATE_MED_MOV,
    CARCAMO_GIF_STATE_LOW_QUIET,
    CARCAMO_GIF_STATE_LOW_MOV,
};

class mod_1_carcamo : public QWidget
{
    Q_OBJECT

public:
    explicit mod_1_carcamo(QLabel *parent = 0);
    void check_update_animation();
    ~mod_1_carcamo();

private:
    void load_new_gif(uint state);

    QLabel *parent_label;
    uint last_state = 0xFF;

};

#endif // MOD_1_CARCAMO_H

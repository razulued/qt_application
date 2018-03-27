#ifndef MOD_2_REACTOR_H
#define MOD_2_REACTOR_H

#include <QLabel>
#include <QPoint>
enum
{
    REACTOR_GIF_STATE_NONE,
    REACTOR_GIF_STATE_HI_QUIET,
    REACTOR_GIF_STATE_HI_MOV,
    REACTOR_GIF_STATE_MED_QUIET,
    REACTOR_GIF_STATE_MED_MOV,
    REACTOR_GIF_STATE_LOW_QUIET,
    REACTOR_GIF_STATE_LOW_MOV,
};

class mod_2_reactor : public QWidget
{
    Q_OBJECT

public:
    explicit mod_2_reactor(QLabel *parent = 0);
    ~mod_2_reactor();
    void check_update_animation();

private:
    void load_new_gif(uint state);

    QLabel *parent_label;
    QPoint original_pos;
};

#endif // MOD_2_REACTOR_H

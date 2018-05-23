#ifndef MOD_5_DIGESTOR_H
#define MOD_5_DIGESTOR_H


#include <QLabel>
#include <QPoint>
enum
{
    DIGESTOR_GIF_STATE_NONE,
    DIGESTOR_GIF_STATE_HI_QUIET,
    DIGESTOR_GIF_STATE_HI_MOV,
    DIGESTOR_GIF_STATE_MED_QUIET,
    DIGESTOR_GIF_STATE_MED_MOV,
    DIGESTOR_GIF_STATE_LOW_QUIET,
    DIGESTOR_GIF_STATE_LOW_MOV
};

class mod_5_digestor : public QWidget
{
    Q_OBJECT

public:
    explicit mod_5_digestor(QLabel *parent = 0);
    ~mod_5_digestor();
    void check_update_animation();

private:
    void load_new_gif(uint state);

    QLabel *parent_label;
    QPoint original_pos;
    uint last_state = 0xFF;
signals:
    void update_window();
};

#endif // MOD_5_DIGESTOR_H

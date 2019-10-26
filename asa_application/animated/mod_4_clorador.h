#ifndef MOD_4_CLORADOR_H
#define MOD_4_CLORADOR_H


#include <QLabel>
#include <QPoint>
enum
{
    CLORADOR_GIF_STATE_NONE,
    CLORADOR_GIF_STATE_MOV,
    CLORADOR_GIF_STATE_QUIET
};

class mod_4_clorador : public QWidget
{
    Q_OBJECT

public:
    explicit mod_4_clorador(QLabel *parent = 0);
    ~mod_4_clorador();
    void check_update_animation();

private:
    void load_new_gif(uint state);

    QLabel *parent_label;
    QPoint original_pos;
    uint last_state = 0xFF;

signals:
    void update_window();
};

#endif // MOD_4_CLORADOR_H

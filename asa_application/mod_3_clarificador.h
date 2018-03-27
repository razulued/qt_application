#ifndef MOD_3_CLARIFICADOR_H
#define MOD_3_CLARIFICADOR_H

#include <QLabel>
#include <QPoint>
enum
{
    CLARIFICADOR_GIF_STATE_NONE,
    CLARIFICADOR_GIF_STATE_FULL_MOV,
    CLARIFICADOR_GIF_STATE_FULL_QUIET
};

class mod_3_clarificador : public QWidget
{
    Q_OBJECT

public:
    explicit mod_3_clarificador(QLabel *parent = 0);
    ~mod_3_clarificador();
    void check_update_animation();

private:
    void load_new_gif(uint state);

    QLabel *parent_label;
    QPoint original_pos;
};

#endif // MOD_3_CLARIFICADOR_H

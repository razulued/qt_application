#ifndef MOD_FLECHAS_H
#define MOD_FLECHAS_H
#include <QLabel>
#include <QPoint>

typedef enum
{
    SLUDGE_1,
    SLUDGE_2,
    SLUDGE_3,
    SLUDGE_4,
    SLUDGE_RETURN,
    WATER_FLOWN_1,
    WATER_FLOWN_2,
    WATER_FLOWN_3,
    WATER_FLOWN_4,
    AFLUENTE_1,
    AFLUENTE_2,
    EFLUENTE_1,
    BLOWER,
    CARCAMO_MOTOR,
}arrow_type_t;

enum
{
    ARRW_SLUDGE_GIF_STATE_QUIET,
    ARRW_SLUDGE_GIF_STATE_MOV,
};

enum
{
    ARRW_SLUDGE_RETURN_GIF_STATE_QUIET,
    ARRW_SLUDGE_RETURN_GIF_STATE_MOV,
};

enum
{
    ARRW_WATER_FLOWN_GIF_STATE_QUIET,
    ARRW_WATER_FLOWN_GIF_STATE_MOV,
};

enum
{
    ARRW_AFLUENTE_GIF_STATE_QUIET,
    ARRW_AFLUENTE_GIF_STATE_MOV,
};

enum
{
    ARRW_EFLUENTE_GIF_STATE_QUIET,
    ARRW_EFLUENTE_GIF_STATE_MOV,
};
class mod_flechas : public QWidget
{
    Q_OBJECT

public:
    mod_flechas(arrow_type_t type, uint state, QLabel *parent = 0);
    ~mod_flechas();
    void check_update_animation();

private:
    void load_new_gif(arrow_type_t type, uint state);

    arrow_type_t arrow_type;
    QLabel *parent_label;
    QPoint original_pos;
    uint last_state = 0xFF;
    QMovie *mv = NULL;

signals:
    void update_window();

};

#endif // MOD_FLECHAS_H

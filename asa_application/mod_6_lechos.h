#ifndef MOD_6_LECHOS_H
#define MOD_6_LECHOS_H

#include <QLabel>
#include <QPoint>
enum
{
    LECHOS_GIF_STATE_BED_1,
    LECHOS_GIF_STATE_BED_2,
    LECHOS_GIF_STATE_BED_3,
};

class mod_6_lechos : public QWidget
{
    Q_OBJECT

public:
    explicit mod_6_lechos(QLabel *parent = 0);
    ~mod_6_lechos();

private:
    void load_new_gif(uint state);

    QLabel *parent_label;
    QPoint original_pos;
};

#endif // MOD_6_LECHOS_H

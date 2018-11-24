#include "mod_6_lechos.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include <QDebug>

mod_6_lechos::mod_6_lechos(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    original_pos = parent->pos();
//    parent_label->setStyleSheet("background-image: url(:/reactor/images/2_Reactor/reactor.png); ");

    load_new_gif(LECHOS_GIF_STATE_BED_2);

    this->show();
}

mod_6_lechos::~mod_6_lechos()
{
}

void mod_6_lechos::load_new_gif(uint state)
{
    QMovie *mv;

    if(last_state != state)
    {
        switch (state)
        {
        case LECHOS_GIF_STATE_BED_1:
            mv = new QMovie(":/lechos/images/6_Lechos/sand_bed_01.png");
            break;
        case LECHOS_GIF_STATE_BED_2:
            mv = new QMovie(":/lechos/images/6_Lechos/sand_bed_02.png");
            break;
        case LECHOS_GIF_STATE_BED_3:
            mv = new QMovie(":/lechos/images/6_Lechos/sand_bed_03.png");
            break;
        default:
            mv = new QMovie(":/lechos/images/6_Lechos/sand_bed_01.png");
            break;
        }

        parent_label->setAttribute(Qt::WA_NoSystemBackground);
        mv->setCacheMode(QMovie::CacheAll);
        mv->start();
        parent_label->setMovie(mv);

        last_state = state;
    }

}

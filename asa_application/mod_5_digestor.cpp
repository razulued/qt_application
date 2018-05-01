#include "mod_5_digestor.h"
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include "parameters.h"

mod_5_digestor::mod_5_digestor(QLabel *parent) :
    QWidget(parent)
{
    parent_label = parent;

    original_pos = parent->pos();
//    parent_label->setStyleSheet("background-image: url(:/reactor/images/2_Reactor/reactor.png); ");

    load_new_gif(DIGESTOR_GIF_STATE_HI_MOV);

    this->show();
}

mod_5_digestor::~mod_5_digestor()
{
}

void mod_5_digestor::load_new_gif(uint state)
{
    QMovie *mv;

    if(last_state != state)
    {
        switch (state)
        {
        case DIGESTOR_GIF_STATE_NONE:
            mv = new QMovie(":/digestor/images/5_Digestor/digester_empty.png");
            break;
        case DIGESTOR_GIF_STATE_HI_QUIET:
            mv = new QMovie(":/digestor/images/5_Digestor/digester_hi_quiet.png");
    //        parent_label->setGeometry(original_pos.x()-2, original_pos.y()-1, parent_label->width(), parent_label->height());
            break;
        case DIGESTOR_GIF_STATE_HI_MOV:
            mv = new QMovie(":/digestor/images/5_Digestor/digester_hi_mov_water.gif");
    //        parent_label->setGeometry(original_pos.x()+10, original_pos.y()+3, parent_label->width(), parent_label->height());
            break;
        case DIGESTOR_GIF_STATE_MED_QUIET:
            mv = new QMovie(":/digestor/images/5_Digestor/digester_med_quiet.png");
            break;
        case DIGESTOR_GIF_STATE_MED_MOV:
            mv = new QMovie(":/digestor/images/5_Digestor/digester_med_mov_water.gif");
//            parent_label->setGeometry(original_pos.x(), original_pos.y()-8, parent_label->width(), parent_label->height());
            break;
        case DIGESTOR_GIF_STATE_LOW_QUIET:
            mv = new QMovie(":/digestor/images/5_Digestor/digester_low_quiet.png");
            //No position change
            break;
        case DIGESTOR_GIF_STATE_LOW_MOV:
            mv = new QMovie(":/digestor/images/5_Digestor/digester_low_mov_water.gif");
            parent_label->setGeometry(original_pos.x(), original_pos.y()-8, parent_label->width(), parent_label->height());
            break;
        default:
            mv = new QMovie(":/reactor/images/2_Reactor/reactor.png");
            break;
        }

        parent_label->setAttribute(Qt::WA_NoSystemBackground);
        mv->start();
        parent_label->setMovie(mv);

        last_state = state;
    }

}

void mod_5_digestor::check_update_animation()
{
    uint reactor_motores = 0;

    reactor_motores |= getParamValue(0x4000).toInt();
    reactor_motores |= getParamValue(0x4010).toInt();
    reactor_motores |= getParamValue(0x4020).toInt();
    reactor_motores |= getParamValue(0x4030).toInt();

    if(reactor_motores > 0)
    {
        load_new_gif(DIGESTOR_GIF_STATE_HI_MOV);
    }
    else
    {
        load_new_gif(DIGESTOR_GIF_STATE_HI_QUIET);
    }
}

#include "clickeablelabel.h"

clickeablelabel::clickeablelabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
}

clickeablelabel::~clickeablelabel()
{

}

void clickeablelabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

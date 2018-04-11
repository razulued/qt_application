#ifndef CLICKEABLELABEL_H
#define CLICKEABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class clickeablelabel : public QLabel{
    Q_OBJECT
public:
    explicit clickeablelabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~clickeablelabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKEABLELABEL_H

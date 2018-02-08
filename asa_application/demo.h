#ifndef DEMO_H
#define DEMO_H

#include <QObject>

class demo : public QObject
{
    Q_OBJECT
public:
    explicit demo(QObject *parent = 0);

signals:

public slots:
};

#endif // DEMO_H

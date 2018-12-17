#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include <QDate>
#include <QDateTime>
#include <QTime>

namespace Ui {
class calendar;
}

class calendar : public QDialog
{
    Q_OBJECT

public:
    explicit calendar(QDateTime datetime, uint periodo, QWidget *parent = 0);
    ~calendar();

private slots:
    void background_clicked();
    void on_push_aceptar_clicked();

    void on_push_cancelar_clicked();

    void on_closeButton_clicked();

private:
    Ui::calendar *ui;

signals:
    void send_calendar_date(uint hour, QDate date, QDateTime datetime);
    void send_calendar_datetime(QDateTime datetime);
};

#endif // CALENDAR_H

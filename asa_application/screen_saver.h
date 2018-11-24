#ifndef SCREEN_SAVER_H
#define SCREEN_SAVER_H

#include <QDialog>
#include <QTimer>
#include <QDateTime>

namespace Ui {
class screen_saver;
}

class screen_saver : public QDialog
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event);

public:
    explicit screen_saver(QWidget *parent = 0);
    ~screen_saver();

private slots:
    void TimerSlot();
private:
    Ui::screen_saver *ui;
    QTimer InactivityTimer;
    bool screen_saver_active;
    uint inactivity_counter;

    void run_back_ground_gif(bool state);
    QString get_moth(QDateTime time);
public slots:
    void receive_date_hour(QDateTime time);
    void pending_activities(uint act);
};

#endif // SCREEN_SAVER_H

#ifndef DATE_WIDGET_H
#define DATE_WIDGET_H

#include <QWidget>
#include <QDateTime>
namespace Ui {
class date_widget;
}

class date_widget : public QWidget
{
    Q_OBJECT

public:
    explicit date_widget(QWidget *parent = 0);
    ~date_widget();

public slots:
    void update_hour(QDateTime datetime);

private:
    Ui::date_widget *ui;
    QString get_month_string(QDateTime time);
};

#endif // DATE_WIDGET_H

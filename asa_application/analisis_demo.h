#ifndef ANALISIS_DEMO_H
#define ANALISIS_DEMO_H

#include <QDialog>

#include <QListWidget>
#include <QVBoxLayout>
#include <QList>

class QWidget;
class aleta_widget : public QWidget
{
    Q_OBJECT
public:
    explicit aleta_widget(QList<uint> id_list, QList<QString> names, QWidget *parent = 0);
    ~aleta_widget();

private:
    QWidget *parent_widget;
    QLayout *layout;
    QListWidget *list_widget;
    QList<uint> IDS;
    QList<QString> NAMES;
    bool show_aleta = false;
public slots:
    void update_data();
    void toogle_hide_show();
};

namespace Ui {
class analisis_demo;
}

class analisis_demo : public QDialog
{
    Q_OBJECT

public:
    explicit analisis_demo(QWidget *parent = 0);
    ~analisis_demo();
    void update_data();
private slots:
    void on_pushButton_clicked();

private:
    Ui::analisis_demo *ui;
    aleta_widget *aleta_1 = NULL;
    aleta_widget *aleta_2 = NULL;

signals:
    void update_donut_1(float value);
};


#endif // ANALISIS_DEMO_H

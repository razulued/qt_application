#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QPen>

namespace Ui {
class graphwindow;
}

class graphwindow : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindow(QWidget *parent = 0);
    ~graphwindow();

    void show_graph(uint element_type);
    void update_graph();

private slots:
    void on_top_menu_3_clicked();

private:
    Ui::graphwindow *ui;
    QPen pen;
    QPen pen2;
    QWidget *parent_window;
};

#endif // GRAPHWINDOW_H

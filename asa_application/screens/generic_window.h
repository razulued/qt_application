#ifndef GENERIC_WINDOW_H
#define GENERIC_WINDOW_H

#include <QDialog>
#include <QString>
#include "configuration/configuration.h"
#include <QMutex>

namespace Ui {
class generic_window;
}

class generic_window : public QDialog
{
    Q_OBJECT

public:
    explicit generic_window(QString name, QWidget *parent = 0);
    ~generic_window();
    void add_image(QString image_path, QSize size, QPoint pos, bool fit_to_geometry);

    void add_images_from_config(QString module);
    QPushButton* add_clickeable_module(QSize size, QPoint pos, QString text, QString color);
    void InitToolTips(QList<configuration_id> parameter_list);

private:
    QWidget *main_menu;
    Ui::generic_window *ui;
    bool display_parameters;
    void HideButtons(bool hide);
    QMutex subwindow_mutex;

signals:
    void update_tooltips();
    void force_tooltips(bool hide);

public slots:
    void new_data_comming();

private slots:
    void subwindow_closed();
    void handleMenuButton();
    void handleParametrosElectricosButton();
    void handleParametrosFisicosButton();
    void handleParametrosQuimicosButton();
    void on_top_main_menu_clicked();
    void on_top_menu_1_clicked();
    void on_top_menu_2_clicked();
    void on_top_menu_3_clicked();
    void on_top_menu_4_clicked();
    void on_asa_logo_clicked();
};

#endif // GENERIC_WINDOW_H

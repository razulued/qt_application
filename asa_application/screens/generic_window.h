#ifndef GENERIC_WINDOW_H
#define GENERIC_WINDOW_H

#include <QDialog>
#include <QString>
#include "configuration/configuration.h"

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

signals:
    void update_tooltips();

public slots:
    void new_data_comming();

private slots:
    void handleMenuButton();
    void handleParametrosElectricosButton();
    void handleParametrosFisicosButton();
    void handleParametrosQuimicosButton();
    void on_top_main_menu_clicked();
};

#endif // GENERIC_WINDOW_H

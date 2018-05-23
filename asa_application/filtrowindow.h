#ifndef FILTROWINDOW_H
#define FILTROWINDOW_H

#include <QDialog>
#include "multistatebutton.h"
#include "custom_tooltip.h"
#include "graphwindow.h"
#include "detailedwindow.h"

namespace Ui {
class filtrowindow;
}

class filtrowindow : public QDialog
{
    Q_OBJECT

public:
    explicit filtrowindow(bool active_params, parameters_t param, QString dia, QString hora, QString user, rutinas_mantenimiento *rutinas, QWidget *parent = 0);
    ~filtrowindow();
    void update_tooltips();
    void update_other(QString dia, QString hora, QString user);

public slots:
    void handleMenuButton();
    void handleParametrosElectricosButton();
    void handleParametrosFisicosButton();
    void handleParametrosQuimicosButton();
    void on_asa_logo_clicked();
private slots:
    void on_go_to_main_clicked();

    void on_modulo_1_clicked();

private:
    Ui::filtrowindow *ui;
    void HideButtons(bool hide);
    bool display_parameters = false;
    bool init_complete = false;

    void InitTooltips();

    custom_tooltip *tool_tip_filtro_electricos;
    custom_tooltip *tool_tip_filtro_fisicos;
    custom_tooltip *tool_tip_filtro_quimicos;

    graphwindow *graph = NULL;
    detailedwindow *detail_window = NULL;
    rutinas_mantenimiento *rutinas_ptr;
signals:
    void forward_param_buttons_state(bool active, parameters_t param);
};

#endif // FILTROWINDOW_H

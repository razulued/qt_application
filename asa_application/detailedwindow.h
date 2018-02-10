#ifndef DETAILEDWINDOW_H
#define DETAILEDWINDOW_H

#include <QDialog>

typedef enum
{
    ELEMENT_REGULADOR,
    ELEMENT_REACTOR,
    ELEMENT_CLARIFICADOR,
    ELEMENT_CLORADOR,
    ELEMENT_DIGESTOR,
    ELEMENT_DESHIDRATADOR
}detailed_elements_t;

namespace Ui {
class detailedwindow;
}

class detailedwindow : public QDialog
{
    Q_OBJECT

public:
    explicit detailedwindow(detailed_elements_t element, QWidget *parent = 0);
    ~detailedwindow();

private slots:
    void on_closeButton_clicked();

    void on_button_parametros_clicked();

    void on_button_evento_clicked();

    void on_button_descripcion_clicked();

    void on_button_visualizacion_clicked();

private:
    Ui::detailedwindow *ui;
};

#endif // DETAILEDWINDOW_H

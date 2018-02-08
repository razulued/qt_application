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

private:
    Ui::detailedwindow *ui;
};

#endif // DETAILEDWINDOW_H

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

namespace Ui {
class mainmenu;
}

class mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = 0);
    ~mainmenu();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H

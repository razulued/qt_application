#ifndef BLUR_H
#define BLUR_H

#include <QDialog>

namespace Ui {
class blur;
}

class blur : public QDialog
{
    Q_OBJECT

public:
    explicit blur(QWidget *parent = 0);
    ~blur();

private:
    Ui::blur *ui;
};

#endif // BLUR_H

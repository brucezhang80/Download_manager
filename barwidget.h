#ifndef BARWIDGET_H
#define BARWIDGET_H

#include <QWidget>

namespace Ui {
class barwidget;
}

class barwidget : public QWidget
{
    Q_OBJECT

public:
    explicit barwidget(QWidget *parent = 0);
    ~barwidget();

private:
    Ui::barwidget *ui;
};

#endif // BARWIDGET_H

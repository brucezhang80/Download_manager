#ifndef DOWNLOADITEM_H
#define DOWNLOADITEM_H

#include <QWidget>

namespace Ui {
class downloaditem;
}

class downloaditem : public QWidget
{
    Q_OBJECT

public:
    explicit downloaditem(QWidget *parent = 0);
    void setText(QString string);
    void setValue(int i);
    ~downloaditem();

private:
    Ui::downloaditem *ui;
};

#endif // DOWNLOADITEM_H

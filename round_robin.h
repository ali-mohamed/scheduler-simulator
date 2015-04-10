#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <QDialog>

namespace Ui {
class round_robin;
}

class round_robin : public QDialog
{
    Q_OBJECT

public:
    explicit round_robin(QWidget *parent = 0);
    ~round_robin();

private:
    Ui::round_robin *ui;
};

#endif // ROUND_ROBIN_H

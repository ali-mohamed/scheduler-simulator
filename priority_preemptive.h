#ifndef PRIORITY_PREEMPTIVE_H
#define PRIORITY_PREEMPTIVE_H

#include <QDialog>

namespace Ui {
class priority_preemptive;
}

class priority_preemptive : public QDialog
{
    Q_OBJECT

public:
    explicit priority_preemptive(QWidget *parent = 0);
    ~priority_preemptive();

private:
    Ui::priority_preemptive *ui;
};

#endif // PRIORITY_PREEMPTIVE_H

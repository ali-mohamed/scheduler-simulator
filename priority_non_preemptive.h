#ifndef PRIORITY_NON_PREEMPTIVE_H
#define PRIORITY_NON_PREEMPTIVE_H

#include <QDialog>

namespace Ui {
class priority_non_preemptive;
}

class priority_non_preemptive : public QDialog
{
    Q_OBJECT

public:
    explicit priority_non_preemptive(QWidget *parent = 0);
    ~priority_non_preemptive();

private:
    Ui::priority_non_preemptive *ui;
};

#endif // PRIORITY_NON_PREEMPTIVE_H

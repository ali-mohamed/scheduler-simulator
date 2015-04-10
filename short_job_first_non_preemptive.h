#ifndef SHORT_JOB_FIRST_NON_PREEMPTIVE_H
#define SHORT_JOB_FIRST_NON_PREEMPTIVE_H

#include <QDialog>

namespace Ui {
class short_job_first_non_preemptive;
}

class short_job_first_non_preemptive : public QDialog
{
    Q_OBJECT

public:
    explicit short_job_first_non_preemptive(QWidget *parent = 0);
    ~short_job_first_non_preemptive();

private:
    Ui::short_job_first_non_preemptive *ui;
};

#endif // SHORT_JOB_FIRST_NON_PREEMPTIVE_H

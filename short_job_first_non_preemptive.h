#ifndef SHORT_JOB_FIRST_NON_PREEMPTIVE_H
#define SHORT_JOB_FIRST_NON_PREEMPTIVE_H

#include <QDialog>
#include "process.h"
#include "process_description.h"

namespace Ui {
class short_job_first_non_preemptive;
}

class short_job_first_non_preemptive : public QDialog
{
    Q_OBJECT

public:
    explicit short_job_first_non_preemptive(QWidget *parent = 0);
    ~short_job_first_non_preemptive();
    void set_number_of_processes(int num) { number_of_processes = num; list.resize(num); }

private slots:
    void on_next_pushButton_clicked();

    void on_back_pushButton_clicked();

signals:
    void sendProcessDescription(QString text);
    void sendTimelineDescription(QString text);
    void sendAWT(QString text);

private:
    Ui::short_job_first_non_preemptive *ui;
    process_description *process_desc;
    int number_of_processes;
    QVector<process> list;
    void schedule_processess(QLinkedList<process> &timeline);
    void draw_timeline(const QLinkedList<process> &timeline);
};

#endif // SHORT_JOB_FIRST_NON_PREEMPTIVE_H

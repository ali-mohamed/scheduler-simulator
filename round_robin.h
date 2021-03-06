#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <QDialog>
#include "process.h"
#include "process_description.h"

namespace Ui {
class round_robin;
}

class round_robin : public QDialog
{
    Q_OBJECT

public:
    explicit round_robin(QWidget *parent = 0);
    ~round_robin();
    void set_number_of_processes(int num) { number_of_processes = num; list.resize(num); }
    void set_quantum(double q) { quantum = q; }

private slots:
    void on_next_pushButton_clicked();

    void on_back_pushButton_clicked();

signals:
    void sendProcessDescription(QString text);
    void sendTimelineDescription(QString text);
    void sendAWT(QString text);

private:
    Ui::round_robin *ui;
    process_description *process_desc;
    int number_of_processes;
    double quantum;
    QVector<process> list;
    void schedule_processess(QLinkedList<process> &timeline);
    void draw_timeline(const QLinkedList<process> &timeline);
};

#endif // ROUND_ROBIN_H

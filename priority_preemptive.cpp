#include "priority_preemptive.h"
#include "ui_priority_preemptive.h"
#include <QMessageBox>
#include "common_functions.h"

priority_preemptive::priority_preemptive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::priority_preemptive)
{
    ui->setupUi(this);
    ui->process_no_label->setVisible(false);
    process_desc = new process_description(this);
    connect(this,SIGNAL(sendProcessDescription(QString)),process_desc,SLOT(getProcessDescription(QString)));
    connect(this,SIGNAL(sendTimelineDescription(QString)),process_desc,SLOT(getTimelineDescription(QString)));
    connect(this,SIGNAL(sendAWT(QString)),process_desc,SLOT(getAWT(QString)));
    process_desc->show();
}

priority_preemptive::~priority_preemptive()
{
    delete ui;
}

void priority_preemptive::on_next_pushButton_clicked()
{
    int process_no = ui->process_no_label->text().toInt();
    double arrival_time = ui->arrival_time_doubleSpinBox->value();
    double burst_time = ui->burst_time_doubleSpinBox->value();
    int priority = ui->priority_spinBox->value();
    list[process_no-1].set_id(process_no);
    list[process_no-1].set_arrival_time(arrival_time);
    list[process_no-1].set_burst_time(burst_time);
    list[process_no-1].set_priority(priority);
    int next_process_no = (process_no % number_of_processes) + 1;
    QString next_process_no_label = QString("%1").arg(next_process_no);
    ui->process_no_label->setText(next_process_no_label);
    QString next_process_label = QString("Process #%1:").arg(next_process_no);
    ui->process_label->setText(next_process_label);
    ui->arrival_time_doubleSpinBox->setValue(list[next_process_no-1].get_arrival_time());
    ui->burst_time_doubleSpinBox->setValue(list[next_process_no-1].get_burst_time());
    ui->priority_spinBox->setValue(list[next_process_no-1].get_priority());
    QLinkedList<process> timeline;
    schedule_processess(timeline);
    draw_timeline(timeline);
    ui->burst_time_doubleSpinBox->setFocus();
}

void priority_preemptive::on_back_pushButton_clicked()
{
    int process_no = ui->process_no_label->text().toInt();
    int back_process_no = process_no - 1;
    if(back_process_no == 0){
        back_process_no = number_of_processes;
    }
    QString back_process_no_label = QString("%1").arg(back_process_no);
    ui->process_no_label->setText(back_process_no_label);
    QString back_process_label = QString("Process #%1:").arg(back_process_no);
    ui->process_label->setText(back_process_label);
    ui->arrival_time_doubleSpinBox->setValue(list[back_process_no-1].get_arrival_time());
    ui->burst_time_doubleSpinBox->setValue(list[back_process_no-1].get_burst_time());
    ui->priority_spinBox->setValue(list[back_process_no-1].get_priority());
    ui->burst_time_doubleSpinBox->setFocus();
}

void priority_preemptive::schedule_processess(QLinkedList<process> &timeline){
    QVector<process> processes = list;
    //Arrange processes according to arrival time
    qSort(processes.begin(), processes.end(), less_than_arrival_time_based);
    int i;
    double time;
    double time_elapsed;
    QVector<process> current_processes_running_now;
    QVector<double> arrival_time_stack = get_arrival_time_for_processes_list(processes);
    int arrival_time_stack_size = arrival_time_stack.size();
    int highest_prority_process_id;
    for(i = 0; i < (arrival_time_stack_size - 1); i++){
        time = arrival_time_stack[i];
        if (time == arrival_time_stack[i+1]){
            continue;
        } else {
            time_elapsed = arrival_time_stack[i+1] - time;
        }
        current_processes_running_now = get_current_processes_at_time(processes, time);
        highest_prority_process_id =
                get_highest_priority_process_id(current_processes_running_now);
        process current_process = processes.at(highest_prority_process_id);
        if (current_process.get_burst_time() != 0){
            process remaining_process = current_process;
            double burst_time = current_process.get_burst_time();
            if(burst_time > time_elapsed){
                current_process.set_burst_time(time_elapsed);
                remaining_process.set_burst_time(burst_time - time_elapsed);
                processes.append(remaining_process);
            }
            timeline.append(current_process);
        }
        processes.remove(highest_prority_process_id);
        qSort(processes.begin(), processes.end(), less_than_arrival_time_based);
    }
    while(!(processes.isEmpty())){
        highest_prority_process_id = get_highest_priority_process_id(processes);
        process current_process = processes.at(highest_prority_process_id);
        if (current_process.get_burst_time() != 0){
            timeline.append(current_process);
        }
        processes.remove(highest_prority_process_id);
    }
}

void priority_preemptive::draw_timeline(const QLinkedList<process> &timeline){
    QString timeline_description = timeline_drawer(timeline, list);
    emit sendTimelineDescription(timeline_description);
    QString process_describe = "";
    for(int i = 0; i < number_of_processes; i++){
        process current_process = list.at(i);
        if(current_process.get_burst_time() != 0){
            process_describe += QString("P%1: Arrival Time: %2, Burst Time:%3, Priority: %4\n")
                    .arg(current_process.get_id()).arg(current_process.get_arrival_time())
                    .arg(current_process.get_burst_time()).arg(current_process.get_priority());
        }
    }
    emit sendProcessDescription(process_describe);
}

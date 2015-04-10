#include "short_job_first_non_preemptive.h"
#include "ui_short_job_first_non_preemptive.h"
#include <QMessageBox>
#include "common_functions.h"

short_job_first_non_preemptive::short_job_first_non_preemptive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::short_job_first_non_preemptive)
{
    ui->setupUi(this);
    ui->process_no_label->setVisible(false);
    process_desc = new process_description(this);
    connect(this,SIGNAL(sendProcessDescription(QString)),process_desc,SLOT(getProcessDescription(QString)));
    connect(this,SIGNAL(sendTimelineDescription(QString)),process_desc,SLOT(getTimelineDescription(QString)));
    connect(this,SIGNAL(sendAWT(QString)),process_desc,SLOT(getAWT(QString)));
    process_desc->show();
}

short_job_first_non_preemptive::~short_job_first_non_preemptive()
{
    delete ui;
}

void short_job_first_non_preemptive::on_next_pushButton_clicked()
{
    int process_no = ui->process_no_label->text().toInt();
    double arrival_time = ui->arrival_time_doubleSpinBox->value();
    double burst_time = ui->burst_time_doubleSpinBox->value();
    list[process_no-1].set_id(process_no);
    list[process_no-1].set_arrival_time(arrival_time);
    list[process_no-1].set_burst_time(burst_time);
    int next_process_no = (process_no % number_of_processes) + 1;
    QString next_process_no_label = QString("%1").arg(next_process_no);
    ui->process_no_label->setText(next_process_no_label);
    QString next_process_label = QString("Process #%1:").arg(next_process_no);
    ui->process_label->setText(next_process_label);
    ui->arrival_time_doubleSpinBox->setValue(list[next_process_no-1].get_arrival_time());
    ui->burst_time_doubleSpinBox->setValue(list[next_process_no-1].get_burst_time());
    QLinkedList<process> timeline;
    schedule_processess(timeline);
    draw_timeline(timeline);
    ui->burst_time_doubleSpinBox->setFocus();
}

void short_job_first_non_preemptive::on_back_pushButton_clicked()
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
    ui->burst_time_doubleSpinBox->setFocus();
}

void short_job_first_non_preemptive::schedule_processess(QLinkedList<process> &timeline){
    QVector<process> processes = list;
    //Arrange processes according to burst & arrival time
    qSort(processes.begin(), processes.end(), less_than_burst_time_based);
    pritorize(processes);
    qSort(processes.begin(), processes.end(), less_than_arrival_time_based);
    double time = get_lowest_arrival_time(processes);
    QVector<process> current_processes_running_now;
    int highest_prority_process_id;
    for (int i = 0; i < number_of_processes; i++){
        if(time < get_lowest_arrival_time(processes)){
            time = get_lowest_arrival_time(processes);
        }
        current_processes_running_now = get_current_processes_at_time(processes, time);
        highest_prority_process_id =
                get_highest_priority_process_id(current_processes_running_now);
        process current_process = processes.at(highest_prority_process_id);
        if (current_process.get_burst_time() != 0){
            timeline.append(current_process);
            time += current_process.get_burst_time();
        }
        processes.remove(highest_prority_process_id);
    }
}

void short_job_first_non_preemptive::draw_timeline(const QLinkedList<process> &timeline){
    QString timeline_description = timeline_drawer(timeline, list);
    emit sendTimelineDescription(timeline_description);
    QString process_describe = "";
    for(int i = 0; i < number_of_processes; i++){
        process current_process = list.at(i);
        if(current_process.get_burst_time() != 0){
            process_describe += QString("P%1: Arrival Time: %2, Burst Time:%3\n")
                    .arg(current_process.get_id()).arg(current_process.get_arrival_time())
                    .arg(current_process.get_burst_time());
        }
    }
    emit sendProcessDescription(process_describe);
}

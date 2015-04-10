#include "fcfs.h"
#include "ui_fcfs.h"
#include <QMessageBox>
#include "common_functions.h"

fcfs::fcfs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fcfs)
{
    ui->setupUi(this);
    ui->process_no_label->setVisible(false);
    process_desc = new process_description(this);
    connect(this,SIGNAL(sendProcessDescription(QString)),process_desc,SLOT(getProcessDescription(QString)));
    connect(this,SIGNAL(sendTimelineDescription(QString)),process_desc,SLOT(getTimelineDescription(QString)));
    connect(this,SIGNAL(sendAWT(QString)),process_desc,SLOT(getAWT(QString)));
    process_desc->show();
}

fcfs::~fcfs()
{
    delete ui;
}

void fcfs::on_next_pushButton_clicked()
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

void fcfs::on_back_pushButton_clicked()
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

void fcfs::schedule_processess(QLinkedList<process> &timeline){
    int i;
    QVector<process> processes = list;
    //Arrange processes according to arrival time
    qSort(processes.begin(), processes.end(), less_than_arrival_time_based);
    for (i = 0; i < number_of_processes; i++){
        process current_process = processes.at(i);
        if (current_process.get_burst_time() != 0){
            timeline.append(current_process);
        }
    }
}

void fcfs::draw_timeline(const QLinkedList<process> &timeline){
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

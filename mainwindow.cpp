#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fcfs.h"
#include "short_job_first_preemptive.h"
#include "short_job_first_non_preemptive.h"
#include "priority_preemptive.h"
#include "priority_non_preemptive.h"
#include "round_robin.h"
#include "common_functions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quantum_label->setVisible(false);
    ui->quantum_doubleSpinBox->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enter_data_pushButton_clicked()
{
    QString process_type = ui->type_of_scheduler_comboBox->currentText();
    int number_of_processes = ui->no_of_processes_spinBox->value();
    if (number_of_processes < 1 || number_of_processes > 99) {
    } else {
        if (process_type == "FCFS"){
            fcfs modal;
            modal.set_number_of_processes(number_of_processes);
            modal.setModal(true);
            modal.exec();
        } else if (process_type == "SJF (Preemptive)"){
            short_job_first_preemptive modal;
            modal.set_number_of_processes(number_of_processes);
            modal.setModal(true);
            modal.exec();
        } else if (process_type == "SJF (Non Preemptive)"){
            short_job_first_non_preemptive modal;
            modal.set_number_of_processes(number_of_processes);
            modal.setModal(true);
            modal.exec();
        } else if (process_type == "Priority (Preemptive)"){
            priority_preemptive modal;
            modal.set_number_of_processes(number_of_processes);
            modal.setModal(true);
            modal.exec();
        } else if (process_type == "Priority (Non Preemptive)"){
            priority_non_preemptive modal;
            modal.set_number_of_processes(number_of_processes);
            modal.setModal(true);
            modal.exec();
        } else if (process_type == "Round Robin"){
            round_robin modal;
            modal.set_number_of_processes(number_of_processes);
            double quantum = ui->quantum_doubleSpinBox->value();
            modal.set_quantum(quantum);
            modal.setModal(true);
            modal.exec();
        }
    }
}

void MainWindow::on_type_of_scheduler_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Round Robin"){
        ui->quantum_label->setVisible(true);
        ui->quantum_doubleSpinBox->setVisible(true);
    } else{
        ui->quantum_label->setVisible(false);
        ui->quantum_doubleSpinBox->setVisible(false);
    }
}

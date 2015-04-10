#include "short_job_first_preemptive.h"
#include "ui_short_job_first_preemptive.h"

short_job_first_preemptive::short_job_first_preemptive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::short_job_first_preemptive)
{
    ui->setupUi(this);
}

short_job_first_preemptive::~short_job_first_preemptive()
{
    delete ui;
}

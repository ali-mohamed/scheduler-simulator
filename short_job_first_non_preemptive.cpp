#include "short_job_first_non_preemptive.h"
#include "ui_short_job_first_non_preemptive.h"

short_job_first_non_preemptive::short_job_first_non_preemptive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::short_job_first_non_preemptive)
{
    ui->setupUi(this);
}

short_job_first_non_preemptive::~short_job_first_non_preemptive()
{
    delete ui;
}

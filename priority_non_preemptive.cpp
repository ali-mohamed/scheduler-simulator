#include "priority_non_preemptive.h"
#include "ui_priority_non_preemptive.h"

priority_non_preemptive::priority_non_preemptive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::priority_non_preemptive)
{
    ui->setupUi(this);
}

priority_non_preemptive::~priority_non_preemptive()
{
    delete ui;
}

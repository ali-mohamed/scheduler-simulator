#include "priority_preemptive.h"
#include "ui_priority_preemptive.h"

priority_preemptive::priority_preemptive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::priority_preemptive)
{
    ui->setupUi(this);
}

priority_preemptive::~priority_preemptive()
{
    delete ui;
}

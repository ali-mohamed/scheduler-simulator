#include "fcfs.h"
#include "ui_fcfs.h"

fcfs::fcfs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fcfs)
{
    ui->setupUi(this);
}

fcfs::~fcfs()
{
    delete ui;
}

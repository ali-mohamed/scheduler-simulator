#include "process_description.h"
#include "ui_process_description.h"

process_description::process_description(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::process_description)
{
    ui->setupUi(this);
}

process_description::~process_description()
{
    delete ui;
}

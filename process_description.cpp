#include "process_description.h"
#include "ui_process_description.h"

process_description::process_description(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::process_description)
{
    ui->setupUi(this);
    ui->awt_label->setVisible(false);
}

process_description::~process_description()
{
    delete ui;
}

void process_description::getProcessDescription(const QString &text){
    ui->listWidget->clear();
    ui->listWidget->addItem(text);
}

void process_description::getTimelineDescription(const QString &text){
    ui->timeline_label->setText(text);
}

void process_description::getAWT(const QString &text){
    ui->awt_label->setText(text);
}

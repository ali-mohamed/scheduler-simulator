#include "round_robin.h"
#include "ui_round_robin.h"

round_robin::round_robin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::round_robin)
{
    ui->setupUi(this);
}

round_robin::~round_robin()
{
    delete ui;
}

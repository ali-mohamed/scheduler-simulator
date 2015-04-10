#ifndef FCFS_H
#define FCFS_H

#include <QDialog>

namespace Ui {
class fcfs;
}

class fcfs : public QDialog
{
    Q_OBJECT

public:
    explicit fcfs(QWidget *parent = 0);
    ~fcfs();

private:
    Ui::fcfs *ui;
};

#endif // FCFS_H

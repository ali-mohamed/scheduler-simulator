#ifndef PROCESS_DESCRIPTION_H
#define PROCESS_DESCRIPTION_H

#include <QDialog>

namespace Ui {
class process_description;
}

class process_description : public QDialog
{
    Q_OBJECT

public:
    explicit process_description(QWidget *parent = 0);
    ~process_description();

private:
    Ui::process_description *ui;
};

#endif // PROCESS_DESCRIPTION_H

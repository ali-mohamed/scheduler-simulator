#ifndef COMMON_FUNCTIONS
#define COMMON_FUNCTIONS

#include <QMessageBox>
#include <QLinkedList>
#include <QVector>
#include "process.h"

QString timeline_drawer(const QLinkedList<process> &timeline, QVector<process> &list);

bool less_than_arrival_time_based(const process &p1, const process &p2);

bool less_than_burst_time_based(const process &p1, const process &p2);

void pritorize(QVector<process> &processes);

int get_highest_priority_process_id(const QVector<process> processes);

double get_lowest_arrival_time(const QVector<process> processes);

QVector<process> get_current_processes_at_time(
        const QVector<process> processes, const double time);

QVector<double> get_arrival_time_for_processes_list(const QVector<process> processes);

#endif // COMMON_FUNCTIONS

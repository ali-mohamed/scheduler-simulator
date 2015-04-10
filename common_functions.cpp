#include "common_functions.h"

QString timeline_drawer(const QLinkedList<process> &timeline, QVector<process> &list){
    QLinkedList<process> timeline_list = timeline;
    QString timeline_description = "";
    if (!(timeline_list.isEmpty())){
        int i;
        int timeline_size = timeline_list.size();
        double time = 0;
        int previous_pid = 0;
        QVector<int> processes_id;
        for(i = 0; i < timeline_size; i++){
            process current_process = timeline_list.first();
            double arrival_time = current_process.get_arrival_time();
            if (arrival_time > time){
                timeline_description += QString("%1---N---").arg(time);
                time = arrival_time;
            }
            if (processes_id.indexOf(current_process.get_id())== -1){
                processes_id.append(current_process.get_id());
                list[current_process.get_id()-1].set_waiting_time(time - arrival_time);
            }
            double burst_time = current_process.get_burst_time();
            int pid = current_process.get_id();
            if(pid != previous_pid){
                timeline_description += QString("%1---P%2---").arg(time).arg(pid);
            }
            time += burst_time;
            timeline_list.removeFirst();
            previous_pid = pid;
        }
        timeline_description += QString("%1").arg(time);
        double total_waiting_time = 0;
        int total_number_of_processes = 0;
        int number_of_processes = list.size();
        for(i = 0; i < number_of_processes; i++){
            process current_process = list.at(i);
            if(current_process.get_burst_time() != 0){
                total_waiting_time += current_process.get_waiting_time();
                total_number_of_processes++;
            }
        }
        double average_waiting_time = total_waiting_time / total_number_of_processes;
        timeline_description += QString("\nAWT: %1\n").arg(average_waiting_time);
    }else{
        timeline_description = QString("No timeline to show!!");
    }
    return timeline_description;
}

bool less_than_arrival_time_based(const process &p1, const process &p2){
    return p1.get_arrival_time() < p2.get_arrival_time();
}

bool less_than_burst_time_based(const process &p1, const process &p2){
    return p1.get_burst_time() < p2.get_burst_time();
}

void pritorize(QVector<process> &processes){
    if (!(processes.isEmpty())){
        int processes_size = processes.size();
        for(int i = 0; i < processes_size; i++){
            processes[i].set_priority(processes_size - i);
        }
    }
}

int get_highest_priority_process_id(const QVector<process> processes){
    int number_of_processes = processes.size();
    int highest_priority_process_number = 0;
    int highest_priority = processes.at(0).get_priority();
    for(int i = 0; i < number_of_processes; i++){
        int priority = processes.at(i).get_priority();
        if (priority > highest_priority){
            highest_priority = priority;
            highest_priority_process_number = i;
        }
    }
    return highest_priority_process_number;
}

double get_lowest_arrival_time(const QVector<process> processes){
    int number_of_processes = processes.size();
    double lowest_time = processes.at(0).get_arrival_time();
    for(int i = 1; i < number_of_processes; i++){
        double time = processes.at(i).get_arrival_time();
        if (time < lowest_time){
            lowest_time = time;
        }
    }
    return lowest_time;
}

QVector<process> get_current_processes_at_time(
        const QVector<process> processes, const double time){
    int number_of_processes = processes.size();
    process current_process;
    QVector<process> running_processes_at_time;
    for(int i = 0; i < number_of_processes; i++){
        current_process = processes.at(i);
        if(current_process.get_arrival_time() <= time){
            running_processes_at_time.append(current_process);
        }
    }
    return running_processes_at_time;
}

QVector<double> get_arrival_time_for_processes_list(const QVector<process> processes){
    int number_of_processes = processes.size();
    QVector<double> arrival_time_stack;
    for(int i = 0; i < number_of_processes; i++){
        arrival_time_stack.append(processes.at(i).get_arrival_time());
    }
    return arrival_time_stack;
}

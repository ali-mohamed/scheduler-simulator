#ifndef PROCESS
#define PROCESS

class process
{
public:
    process() { id = 0; priority = 0; burst_time = 0;
                arrival_time = 0; waiting_time = 0; }
    void set_id(int pid) { id = pid; }
    void set_priority(int prty) { priority = prty; }
    void set_burst_time(double time) { burst_time = time; }
    void set_arrival_time(double time) { arrival_time = time; }
    void set_waiting_time(double time) { waiting_time = time; }
    int get_id() const { return id; }
    int get_priority() const { return priority; }
    double get_burst_time() const { return burst_time; }
    double get_arrival_time() const { return arrival_time; }
    double get_waiting_time() const { return waiting_time; }

private:
    int id;
    int priority;
    double burst_time;
    double arrival_time;
    double waiting_time;
};

#endif // PROCESS


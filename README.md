# Scheduler Simulator
Simulator for Process Scheduling Types used by Operating Systems

# Scheduling Algorithms Included
- First Come First Served (FCFS)
- Shortest Job First (SJF - preemptive)
- Shortest Job First (SJF - non-preemptive)
- Priority Based (preemptive)
- Priority Based (non-preemptive)
- Round Robin (RR)

# How to Use
- Main Window
  1. Choose Process Type
  2. Set Number of Processes
  3. Set Quantum (if Round Robin is chosen)
- Processes Window (For every process you will)
  4. Set Prcess Arrival Time
  5. Set Process Burst/Execute Time
  6. Set Prcess Priority (if Priority Based is chosen)
  7. Press Next
Note: You will find a Dialog Window shows Timeline and every process added to add more interactivity (WYDIWYG).
Note: You can press Back if you want to edit process info and you will still have Timeline updated.
Note: You can not run more than an Algorithm at time.

# TO DO
- Have a more interactive timeline.
- Change algorithm types interactively.

# Developing
- Software is built on Qt and C++
- Tested on Linux Machine (Debian Wheezy)

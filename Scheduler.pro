#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T20:38:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scheduler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fcfs.cpp \
    priority_preemptive.cpp \
    priority_non_preemptive.cpp \
    short_job_first_preemptive.cpp \
    short_job_first_non_preemptive.cpp \
    round_robin.cpp \
    common_functions.cpp \
    process_description.cpp

HEADERS  += mainwindow.h \
    fcfs.h \
    priority_preemptive.h \
    priority_non_preemptive.h \
    process.h \
    short_job_first_preemptive.h \
    short_job_first_non_preemptive.h \
    round_robin.h \
    common_functions.h \
    process_description.h

FORMS    += mainwindow.ui \
    fcfs.ui \
    priority_preemptive.ui \
    priority_non_preemptive.ui \
    short_job_first_preemptive.ui \
    short_job_first_non_preemptive.ui \
    round_robin.ui \
    process_description.ui

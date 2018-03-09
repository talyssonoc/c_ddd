#ifndef __INTERFACE_ENROLLMENT_SYSTEM_H
#define __INTERFACE_ENROLLMENT_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include "../domain/student/student.h"
#include "../app/enrollment_system/enrollment_system.h"

#define ADD_STUDENT 1
#define LIST_STUDENTS 2

#ifdef __linux__
#define CLEAR_BUFFER __fpurge(stdin)
#elif _WIN32
#define CLEAR_BUFFER fflush(stdin)
#else
#define CLEAR_BUFFER printf("BUFFER_ERROR");exit(-1)
#endif

void fgets_without_new_line(char *buffer, int max_size);

typedef struct {
  EnrollmentSystem * enrollment_system;
} EnrollmentSystemUI;


EnrollmentSystemUI * new_enrollment_system_ui(EnrollmentSystem * enrollment_system);
int start_enrollment_system_ui(EnrollmentSystemUI * this);
int enrollment_system_ui_show_main_menu(EnrollmentSystemUI * this);
int enrollment_system_ui_execute_operation(EnrollmentSystemUI * this, int operation);
int enrollment_system_ui_add_student(EnrollmentSystemUI * this);
int enrollment_system_ui_list_students(EnrollmentSystemUI * this);

#endif

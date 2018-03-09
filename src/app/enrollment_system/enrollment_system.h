#ifndef __APP_ENROLLMENT_SYSTEM_H
#define __APP_ENROLLMENT_SYSTEM_H

#include <stdio.h>
#include <stdio_ext.h>
#include "../../domain/student/student.h"
#include "../../infra/student/student_repository.h"

typedef struct {
  StudentRepository * student_repo;
} EnrollmentSystem;

EnrollmentSystem * new_enrollment_system();
int enrollment_system_add_student(EnrollmentSystem * enrollment_system, char name[STUDENT_MAX_NAME_LENGTH]);

#endif

#ifndef __INFRA_STUDENT_REPOSITORY
#define __INFRA_STUDENT_REPOSITORY

#include "../../domain/student/student.h"

#define STUDENT_MAX_AMOUT 100

typedef struct {
  int current_id;
  int length;
  Student ** students;
} StudentRepository;

StudentRepository * new_student_repository();
int student_repository_add(StudentRepository * this, Student * student);

#endif

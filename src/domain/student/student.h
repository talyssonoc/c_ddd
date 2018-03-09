#ifndef __DOMAIN_STUDENT_H
#define __DOMAIN_STUDENT_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STUDENT_MAX_NAME_LENGTH 50
#define STUDENT_MAX_COURSES 10
typedef int student_id;

typedef struct {
  student_id id;
  char name[STUDENT_MAX_NAME_LENGTH];
  bool active;
  int course_ids[STUDENT_MAX_COURSES];
} Student;

Student * new_student(char name[STUDENT_MAX_NAME_LENGTH]);

#endif

#include "student.h"

Student * new_student(char name[STUDENT_MAX_NAME_LENGTH]) {
  Student * student = malloc(sizeof(Student));
  student->id = -1;
  strcpy(student->name, name);
  student->active = true;

  return student;
}

#include <stdlib.h>
#include "student.h"

StudentRepository * new_student_repository() {
  StudentRepository * student_repo = malloc(sizeof(StudentRepository));
  Student ** students = malloc(STUDENT_MAX_AMOUT * sizeof(Student*));
  student_repo->length = 0;
  student_repo->current_id = 0;
  student_repo->students = students;

  return student_repo;
}

int student_repository_add(StudentRepository * this, Student * student) {
  if(this->length >= STUDENT_MAX_AMOUT) {
    return 1;
  }

  student->id = this->current_id++;

  this->students[this->length] = student;
  this->length++;

  return 0;
}

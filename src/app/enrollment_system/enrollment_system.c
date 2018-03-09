#include <stdlib.h>
#include "enrollment_system.h"

EnrollmentSystem * new_enrollment_system() {
  EnrollmentSystem * enrollment_system = malloc(sizeof(EnrollmentSystem));
  StudentRepository * student_repo = new_student_repository();

  enrollment_system->student_repo = student_repo;

  return enrollment_system;
}

int enrollment_system_add_student(EnrollmentSystem * this, char name[STUDENT_MAX_NAME_LENGTH]) {
  Student * student = new_student(name);

  student_repository_add(this->student_repo, student);

  return 0;
}

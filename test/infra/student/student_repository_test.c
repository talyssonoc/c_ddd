#include "../../min_unit.h"

static char * test_infra_student_new_student_repository() {
  StudentRepository * student_repo = new_student_repository();

  mu_assert("error, student_repo->length != 0", student_repo->length == 0);
  mu_assert("error, student_repo->students is NULL", student_repo->students);
  return 0;
}

static char * test_infra_student_student_repository_add() {
  StudentRepository * student_repo = new_student_repository();
  Student * student = new_student("John Doe");

  student_repository_add(student_repo, student);

  mu_assert("error, student->length != 1", student_repo->length == 1);
  mu_assert("error, student->students[0] != John Doe",
    !strcmp(student_repo->students[0]->name, "John Doe"));
}

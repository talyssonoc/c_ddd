#include "../../min_unit.h"

static char * test_domain_student_new_student() {
  Student * student = new_student("John Doe");

  mu_assert("error, student->name != John Doe", !strcmp(student->name, "John Doe"));
  return 0;
}

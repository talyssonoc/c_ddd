#include "min_unit.h"

#include "domain/student/student_test.c"
#include "infra/student/student_repository_test.c"

int tests_run = 0;

static char * all_tests() {
  mu_run_test(test_domain_student_new_student);
  mu_run_test(test_infra_student_new_student_repository);
  mu_run_test(test_infra_student_student_repository_add);
  return 0;
}

int main(int argc, char **argv) {
  char * result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}

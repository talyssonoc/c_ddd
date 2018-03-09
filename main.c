#include <stdio.h>
#include "src/src.h"

int main(int argc, char const *argv[]) {
  EnrollmentSystem * enrollment_system = new_enrollment_system();
  EnrollmentSystemUI * enrollment_system_ui = new_enrollment_system_ui(enrollment_system);

  return start_enrollment_system_ui(enrollment_system_ui);
}

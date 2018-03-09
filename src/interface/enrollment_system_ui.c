#include "enrollment_system_ui.h"

EnrollmentSystemUI * new_enrollment_system_ui(EnrollmentSystem * enrollment_system) {
  EnrollmentSystemUI * enrollment_system_ui = malloc(sizeof(EnrollmentSystemUI));
  enrollment_system_ui->enrollment_system = enrollment_system;

  return enrollment_system_ui;
}

int start_enrollment_system_ui(EnrollmentSystemUI * enrollment_system_ui) {
  return enrollment_system_ui_show_main_menu(enrollment_system_ui);
}

int enrollment_system_ui_show_main_menu(EnrollmentSystemUI * this) {
  printf(" ############################################\n");
  printf(" # Welcome to the student enrollment system #\n");
  printf(" ############################################\n\n");

  int operation = 0;

  do {
    printf("What operation would you like to do?\n");
    printf("\n%d - Add an student", ADD_STUDENT);
    printf("\n%d - List students", LIST_STUDENTS);
    printf("\n\nOperation: ");

    scanf("%d", &operation);


    enrollment_system_ui_execute_operation(this, operation);
  } while(operation != -1);

  return 0;
}

int enrollment_system_ui_execute_operation(EnrollmentSystemUI * this, int operation) {
  switch(operation) {
    case ADD_STUDENT:
      return enrollment_system_ui_add_student(this);
    case LIST_STUDENTS:
      return enrollment_system_ui_list_students(this);
  }
}

int enrollment_system_ui_add_student(EnrollmentSystemUI * this) {
  char * name = malloc((STUDENT_MAX_NAME_LENGTH + 1) * sizeof(char));

  printf("\nNew student name: ");
  fgets_without_new_line(name, STUDENT_MAX_NAME_LENGTH);

  return enrollment_system_add_student(this->enrollment_system, name);
}

int enrollment_system_ui_list_students(EnrollmentSystemUI * this) {
  EnrollmentSystem * enrollment_system = this->enrollment_system;

  for (int i = 0; i < enrollment_system->student_repo->length; ++i) {
    printf("#%d - %s\n",
      enrollment_system->student_repo->students[i]->id,
      enrollment_system->student_repo->students[i]->name
    );
  }
}

void fgets_without_new_line(char *buffer, int max_size) {
  CLEAR_BUFFER;
  fgets(buffer, max_size, stdin);
  buffer[strlen(buffer) - 1] = '\0';
}

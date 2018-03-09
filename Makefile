SOURCE_FILES_GLOB = ./src/**/*.c ./src/**/**/*.c
SOURCE_FILES = $(wildcard $(SOURCE_FILES_GLOB))

MAIN_FILE = ./main.c
MAIN_BIN = ./enrollment_system
COMPILATION_ARGS = -o $(MAIN_BIN) $(SOURCE_FILES) $(MAIN_FILE)

TEST_FILE = ./test/test.c
TEST_BIN = ./enrollment_system_tests
TEST_ARGS = -o $(TEST_BIN) $(SOURCE_FILES) $(TEST_FILE)

compile:
	gcc $(COMPILATION_ARGS)

run:
	$(MAIN_BIN)

dev: compile run

compile_debug:
	gcc $(COMPILATION_ARGS) -g

run_debug:
	gdb $(MAIN_BIN)

debug: compile_debug run_debug

compile_test:
	gcc $(TEST_ARGS)

run_test:
	$(TEST_BIN)

test: compile_test run_test

compile_debug_test:
	gcc $(TEST_ARGS) -g

run_debug_test:
	gdb $(TEST_BIN)

debug_test: compile_debug_test run_debug_test

clean:
	rm -f $(MAIN_BIN)

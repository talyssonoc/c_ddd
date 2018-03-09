MAIN_FILE = ./main.c
MAIN_BIN = ./enrollment_system
SOURCE_FILES = ./src/**/*.c ./src/**/**/*.c
DEBUG_FILES = ./*.s
COMPILATION_ARGS = -o $(MAIN_BIN) $(wildcard $(SOURCE_FILES)) $(MAIN_FILE)

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

clean:
	rm -f $(MAIN_BIN)

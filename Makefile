FLAGS = -Wall -Wextra -Werror -Wuninitialized -std=c11 
TESTFLAGS = -lcheck --coverage 
SRC_DIR := src
SOURCES_FUN := $(wildcard $(SRC_DIR)/*.c)

ifeq ($(shell uname), Linux)
TESTFLAGS += -lm -lsubunit
else
TESTFLAGS += -fprofile-arcs -ftest-coverage
endif

all: s21_matrix.a
	rm -rf *.o

s21_matrix.a: clean
	gcc $(FLAGS) -c $(SOURCES_FUN)
	ar rcs s21_matrix.a *.o
	@ranlib s21_matrix.a
	@rm -rf *.o

test: s21_matrix.a
	@gcc ./src/tests/*.c s21_matrix.a $(TESTFLAGS) -o testing
	./testing

gcov_report: clean
	@gcc $(TESTFLAGS) ./src/*.c ./src/tests/*.c -o s21_lib_test $(TESTFLAGS)
	./s21_lib_test
	@gcov -f $(SOURCES_FUN)
	@lcov --no-external -t test -o coverage.info -c -d .
	@lcov --remove coverage.info 'tests/*' -o coverage_filtered.info
	@genhtml -o html_report coverage_filtered.info
	@open html_report/index.html

lint:
	@clang-format --style=Google -i ./src/*.c ./src/*.h ./src/tests/*.c ./src/tests/*.h

clean:
	@rm -rf *.o testing.c testing *.a *.gcno *.gcda *.gcov *.info *.out
	@rm -rf html_report s21_matrix s21_lib_test html_report

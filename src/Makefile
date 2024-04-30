CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 
LIBFLAG = -lm
CHECK_FLAGS = $(shell pkg-config check --cflags --libs)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)

SRC = ./functions
PROJECT_NAME = my_matrix
OBJECTS = $(SRC)/*.o

all : $(PROJECT_NAME).a

$(PROJECT_NAME).a : $(SRC)/*.c
	$(CC) $(CFLAGS) -c $+
	ar rc $(PROJECT_NAME).a *.o
	ranlib $(PROJECT_NAME).a
	rm -rf *.o

clean :
	rm -rf *.a *.o */*.o *.gcda *.gcno report $(PROJECT_NAME)_gcov_report $(PROJECT_NAME)_test

rebuild : clean all gcov_report

test :
	$(CC) $(CFLAGS) $(GCOV_FLAGS) my_matrix_test.c ./tests/*.c $(PROJECT_NAME).a -o $(PROJECT_NAME)_test $(CHECK_FLAGS) $(LIBFLAG)
	./$(PROJECT_NAME)_test 
	rm -rf *.gcda *.gcno *.o

gcov_report : $(wildcard $(SRC)/*.c)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $^
	ar rc $(PROJECT_NAME).a *.o
	ranlib $(PROJECT_NAME).a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) my_matrix_test.c ./tests/*.c $(PROJECT_NAME).a -o $(PROJECT_NAME)_$@ $(CHECK_FLAGS)
	./$(PROJECT_NAME)_$@
	rm -rf report
	mkdir -p report
	gcovr --html-details -o report/coverage.html --exclude tests/
	rm -rf *.gcda *.gcno *.o
	open report/coverage.html
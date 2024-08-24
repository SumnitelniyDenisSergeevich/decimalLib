CC=gcc
CFLAGS=-c -Wall -Wextra -Werror -std=c11
LDFLAGS=-O2 -Wall -Wextra -Werror -std=c11
SOURCE=$(wildcard s21_*.c)
OBJECTS=$(patsubst %.c,%.a, ${SOURCE}) # заменяет в именах всех исходников расширение
UNAME:=$(shell uname -s) # определяем ОС
ifeq ($(UNAME),Linux ) # Linux
	OPEN_CMD=xdg-open # команда для открытия отчета
	ADD_LIB=-lm -lrt -lpthread -lsubunit # дополнительные библиотеки
	BREW=/home/darkwolf/homebrew
endif
ifeq ($(UNAME),Darwin ) # MacOS
	OPEN_CMD=open
	ADD_LIB= 
	BREW=${HOME}/homebrew
endif
PATH := $(PATH):$(BREW)/bin # пути поиска lcov и genhtml
GCOV=--coverage
PROJECTNAME=s21_decimal
TESTC=test_s21_decimal.c

all: clean ${PROJECTNAME}.a test

$(PROJECTNAME).a: ${SOURCE}
	${CC} $(CFLAGS) ${ADD_LIB} ${SOURCE}
	ar rc $(PROJECTNAME).a $(PROJECTNAME).o
	ranlib $(PROJECTNAME).a

test: $(TESTC) ${PROJECTNAME}.a
	${CC} ${LDFLAGS} -o $@ $^ -lcheck ${ADD_LIB}
	./$@

gcov_report: clean $(PROJECTNAME).a ${SOURCE} $(TESTC)
	-mkdir report
	${CC} ${LDFLAGS} -o $@ ${GCOV} $(TESTC) ${SOURCE} -lcheck ${ADD_LIB}
	-./$@
	--gcov $(TESTC)
	if [ "$(UNAME)","Linux " ]; then \
        lcov -t ${PROJECTNAME} -o ${PROJECTNAME}.info -c -d .;\
		genhtml -o report ${PROJECTNAME}.info;\
    else \
        $(shell PATH=$(PATH) which lcov)  -t ${PROJECTNAME} -o ${PROJECTNAME}.info -c -d .;\
		$(shell PATH=$(PATH) which genhtml) -o report ${PROJECTNAME}.info;\
    fi
	-$(OPEN_CMD) ./report/index.html

rebuild: clean all

main: main.c s21_decimal.c
	gcc main.c s21_decimal.c -lm -g

clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/

.PHONY: all clean test
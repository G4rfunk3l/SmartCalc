CC = gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
GCOV = -fprofile-arcs -ftest-coverage
OS = $(shell uname)
QMAKE = qmake
INSTALL_DIR = SmartCalc_v1.0
  BUILD_DIR = build_SmartCalc_v1.0
ifeq ($(OS), Linux)
  APP=Smart
  APP_INSTALLED=SmartCalc_v1.0
  LIBS=-lcheck -lm -lpthread -lsubunit -lrt
  OPEN=xdg-open
  LEAKS= valgrind test
else
  APP=Smart.app
  APP_INSTALLED=SmartCalc_v1.0.app
  LIBS=-lcheck
  OPEN=open
  LEAKS=CK_FORK=no leaks --atExit -- test
endif

all: install

build:
	$(QMAKE) -o $(BUILD_DIR)/Makefile ./Smart/Smart.pro
	make -C $(BUILD_DIR)/

rebuild: clean uninstall build

install: build
	mkdir -p $(INSTALL_DIR)
	cp -r $(BUILD_DIR)/$(APP) $(INSTALL_DIR)/$(APP_INSTALLED)

uninstall:
	rm -rf $(INSTALL_DIR)

dist: install
	tar -cf SmartCalc_v1.0.tar readme.md SmartCalc_v1.0 *.c *.h Makefile 

test: clean
	$(CC) $(CFLAGS) $(GCOV) test.c calculator.c $(LIBS) -o gcov_report
	./gcov_report

leaks: clean test
	$(LEAKS)

gcov_report: test
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	$(OPEN) ./report/index.html

gcov: test
	gcov s21_calc.gcda s21_calc.gcno
	gcovr --json s21_calc.json
	gcovr -a s21_calc.json --html-details coverage.html
	$(OPEN) ./coverage.html
	rm -rf *.gcno *.gcda *.json s21_calc.c.gcov

lint:
	clang-format -i *.c *.h
	clang-format -i Smart/*.cpp Smart/*.h
	clang-format -n *.c *.h
	clang-format -n Smart/*.cpp Smart/*.h

check:
	cppcheck --std=c11 --enable=all --suppress=missingIncludeSystem *.c *.h

clean:
	rm -rf ./report build*
	rm -f *.gcno *.gcda *.info gcov_report *.tar coverage.*
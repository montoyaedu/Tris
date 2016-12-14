all: TrisTest test TrisGame

clean0:
	rm -f *.o
	rm -fr TrisTest.dSYM
	rm -f *.gc*

clean: clean0
	rm -f TrisTest
	rm -f TrisGame

TrisTest: TrisTest.c TrisImpl.c
	gcc -g -Wall -fprofile-arcs -ftest-coverage -o $@ TrisTest.c TrisImpl.c

TrisGame: TrisGame.o TrisImpl.o
	gcc -o $@ TrisGame.o TrisImpl.o

test: TrisTest
	./TrisTest
	gcov -bcf TrisImpl.c
	rm -fr gcovr-report-html
	mkdir gcovr-report-html
	gcovr -r . --html --html-details -o gcovr-report-html/coverage.html
	gcovr -r . --xml -o gcovr-report-html/coverage.xml
	gcovr -r .

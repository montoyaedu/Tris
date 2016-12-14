all: TrisTest test TrisGame

clean:
	rm -f *.o
	rm -f TrisTest

TrisTest: TrisTest.o TrisImpl.o
	cc -o $@ TrisTest.o TrisImpl.o

TrisGame: TrisGame.o TrisImpl.o
	cc -o $@ TrisGame.o TrisImpl.o

test: TrisTest
	./TrisTest

CMP=g++ -std=c++14 -Wall

all: ps_translator	

ps_translator: cpsmain.o ComplexShapes.o cps.o Shape.o SimpleShapes.o UniqueShapes.o
	$(CMP) -o PS_Translator.out build/cpsmain.o build/ComplexShapes.o build/cps.o build/Shape.o \
	build/SimpleShapes.o build/UniqueShapes.o

cpsmain.o: main.cpp
	$(CMP) -c -o build/cpsmain.o main.cpp

ComplexShapes.o: ComplexShapes.cpp
	$(CMP) -c -o build/ComplexShapes.o ComplexShapes.cpp

cps.o: cps.cpp
	$(CMP) -c -o build/cps.o cps.cpp

Shape.o: Shape.cpp
	$(CMP) -c -o build/Shape.o Shape.cpp

SimpleShapes.o: SimpleShapes.cpp
	$(CMP) -c -o build/SimpleShapes.o SimpleShapes.cpp

UniqueShapes.o: UniqueShapes.cpp
	$(CMP) -c -o build/UniqueShapes.o UniqueShapes.cpp

cps_test_suites.o: cps_test_suites.cpp
	$(CMP) -c -o build/cps_test_suites.o cps_test_suites.cpp	

testmain.o: testmain.cpp
	$(CMP) -c -o build/testmain.o testmain.cpp

tests: ComplexShapes.o cps.o cps_test_suites.o Shape.o SimpleShapes.o testmain.o UniqueShapes.o
	$(CMP) -o tests.out build/ComplexShapes.o build/cps.o build/cps_test_suites.o build/Shape.o \
	build/SimpleShapes.o build/testmain.o build/UniqueShapes.o

tests-run: tests
	./tests.out $1

clean: 
	rm build/*.o *.out
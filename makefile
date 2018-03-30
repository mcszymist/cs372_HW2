all:
	g++ -std=c++14 -o PS_Translator.out \
		ComplexShapes.cpp \
		cps.cpp \
		main.cpp \
		Shape.cpp \
		SimpleShapes.cpp \
		UniqueShapes.cpp \

tests:
	g++ -std=c++14 -o tests.out \
		ComplexShapes.cpp \
		cps.cpp \
		cps_test_suites.cpp \
		Shape.cpp \
		SimpleShapes.cpp \
		testmain.cpp \
		UniqueShapes.cpp \

tests-run: tests
	./tests.out $1
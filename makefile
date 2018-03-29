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
	./$(TEST_OUT_FILE) $1

run: all
	./$(OUT_FILE)

clean:
	rm $(OBJ_FILES) $(MAIN).o *.out

clean-tests:
	rm $(TESTING_OBJ_FILES)
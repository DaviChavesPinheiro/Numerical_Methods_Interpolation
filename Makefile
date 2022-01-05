main: main.o system_equations.o lagrange.o newton.o inverse_interpolation.o
	g++ -static -o ./build/main build/main.o build/system_equations.o build/lagrange.o build/newton.o build/inverse_interpolation.o
main.o:
	g++ -c src/main.cpp -o ./build/main.o
system_equations.o:
	g++ -c src/system_equations.cpp -o ./build/system_equations.o
lagrange.o:
	g++ -c src/lagrange.cpp -o ./build/lagrange.o
newton.o:
	g++ -c src/newton.cpp -o ./build/newton.o
inverse_interpolation.o:
	g++ -c src/inverse_interpolation.cpp -o ./build/inverse_interpolation.o

test: test.o system_equations.o lagrange.o newton.o inverse_interpolation.o
	g++ -static -o ./build/test build/test.o build/system_equations.o build/lagrange.o build/newton.o build/inverse_interpolation.o
test.o:
	g++ -I./src -c tests/test.cpp -o ./build/test.o

clean:
	rm -f ./build/*.c ./build/*.o all

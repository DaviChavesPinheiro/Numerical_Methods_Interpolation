main: main.o system_equations.o lagrange.o newton.o inverse_interpolation.o
	g++ -o main main.o system_equations.o lagrange.o newton.o inverse_interpolation.o

main.o system_equations.o lagrange.o newton.o inverse_interpolation.o:
	g++ -c main.cpp system_equations.cpp lagrange.cpp newton.cpp inverse_interpolation.cpp

clean:
	rm -f *.c *.o all

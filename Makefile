main: main.o system_equations.o lagrange.o newton.o
	g++ -o main main.o system_equations.o lagrange.o newton.o

main.o system_equations.o lagrange.o newton.o:
	g++ -c main.cpp system_equations.cpp lagrange.cpp newton.cpp

clean:
	rm -f *.c *.o all

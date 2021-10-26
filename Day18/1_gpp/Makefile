normal: main.cpp a.o b.o c.o
	@echo -- Building a.out from $^
	g++ main.cpp a.o b.o c.o -IC -o a.out

static: main.cpp abc.a
	@echo -- Building ar.out using abc.a static object
	g++ main.cpp abc.a -IC -o ar.out

lib: main.cpp liba.so b.o c.o
	@echo -- Building alib.out using liba.so as a shared library
	@echo -- run "export LD_LIBRARY_PATH=."
	g++ main.cpp b.o c.o -L. -la -IC -o alib.out

libfail: main.cpp liba.so b.o c.o
	g++ b.o c.o -L. -la main.cpp -IC -o alib.out

abc.a: a.o b.o c.o
	ar -rv abc.a a.o b.o c.o

liba.so: a.cpp
	@echo -- Building shared library $@
	g++ --shared -fPIC a.cpp -o liba.so

c.o: C/c.cpp
	@echo -- Compiling $< into $@
	g++ C/c.cpp -IC -c

%.o: %.cpp
	@echo -- Compiling $< into $@
	g++ $< -c

libload:
	export LD_LIBRARY_PATH=.

clean:
	@echo -- Cleaning up folder
	rm -rf *.o *.so *.a *.out
#=====================================================
#						varibal
#=====================================================
objects := main.o 
CFLAGS := -I /usr/share/cunit/include/CUnit
CFLAGS += -L /usr/share/cunit/lib/
#=====================================================
#						rules
#=====================================================
.PHONY : all clean
all : $(objects)
	gcc -o test $(CFLAGS) $^ -lcunit -static

clean:
	rm *.o test

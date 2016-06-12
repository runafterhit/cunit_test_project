#=====================================================
#						varibal
#=====================================================
objects := main.o 
CFLAGS := -I./cunit/include/CUnit
CFLAGS += -L./cunit/lib/
#=====================================================
#						rules
#=====================================================
.PHONY : all clean
all : $(objects)
	gcc -o test $(CFLAGS) $^ -lcunit -static

clean:
	rm *.o test
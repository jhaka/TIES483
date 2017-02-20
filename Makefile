DEPENDS = 
LIBS =

index:
	@echo
	@echo "make all - compile everything"
	@echo "make clean - remove temporary files"
	@echo

all:	prob4



prob4: prob4.c $(DEPENDS)
	gcc -o $@ prob4.c $(LIBS)
#	gcc-4 -o $@ prob4.c $(LIBS)


clean:
	rm -f prob4.exe *~ prob4.o prob4

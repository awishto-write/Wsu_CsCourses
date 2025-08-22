# define CC as gcc
# define CLAGS as flags to gcc
# define OBJS as object code files

#CC=gcc
#CFLAGS=-Wall
#OBJS = cathw.o in1.txt in2.txt

#mycathw: $(OBJS)
#	$(CC) $(CFLAGS) -o mycathw
mycathw: cathw.c
	gcc -o mycathw cathw.c

build: mycathw					# compile the code

run: 							# run the code
	$(info Running mycathw..)
	./mycathw
	#./mycathw in1.txt in2.txt
	#Cpts360_Hw1a ../cathw.c

all: build run

clean: 							# clean all object files
	$(info Removing object files..)
	rm mycathw

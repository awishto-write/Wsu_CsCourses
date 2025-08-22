# define CC as gcc
# define CLAGS as flags to gcc
# define OBJS as object code files

CC=gcc
CFLAGS=-Wall
OBJS = comparecat.o

#mycathw: $(OBJS)
#	$(CC) $(CFLAGS) -o mycathw

#UNAME_S := $(shell uname -s)
#
#ifeq ($(UNAME_S),Linux)
#    # On Linux, use -lrt
#    LDFLAGS = -lrt
#endif

mycomparecat: comparecat.c
	gcc -o mycomparecat comparecat.c
	#gcc -o mycomparecat comparecat.c $(LDFLAGS)

build: mycomparecat					# compile the code

run: 							# run the code
	$(info Running mycomparecat..)
	./mycomparecat cat.c cathw.c

all: build run

clean: 							# clean all object files
	$(info Removing object files..)
	rm mycomparecat

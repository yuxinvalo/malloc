CC=gcc
CFLAGS =-std=c99 -pedantic -Wextra -Wall -Werror
LDFLAGS=-shared -fPIC
TARGET=libmalloc.so
CHECK=check

SRC=./src/metadata.c  ./src/malloc.c \
		./src/calloc.c  	./src/free1.c
OBJ=$(SRC=.c:.o)
RM = rm -fr


#target $@, object $^, first dependency file $<
$(TARGET):$(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(SRC)

level1:
	#$(MAKE) -C test/
	$(CC) $(CFLAGS) -o tests/level1 src/level1.c
 
level2:
	$(CC) $(CFLAGS) -o level2 src/level2.c

level3:
	$(CC) $(CFLAGS) -o tests/level3 src/level3.c
 

check:all
all:$(TARGET) $(OBJ) level1 level3
	LD_PRELOAD=./libmalloc.so  ./tests/level1 ./tests/level2
.PHONY: clean
clean:
	$(RM) $(OBJ) $(TARGET) \
	$(RM) a.out tests/level1 tests/level2 tests/level3


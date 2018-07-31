CC := gcc
LDFLAGS := -ltestu01 -lprobdist -lmylib -lm
CFLAGS := -Wall

SRCS := $(wildcard *.c)
BINS := $(patsubst %.c,%,$(SRCS))
OBJS := $(patsubst %,%.o,$(BINS))

all: $(BINS)

test: test.c morton.h
	gcc -o test test.c

run: 
	$(foreach x,$(BINS),./$(x);)

clean:
	$(RM) $(BINS)

rebuild: clean all

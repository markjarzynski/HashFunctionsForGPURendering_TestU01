CC := gcc
LDFLAGS := -ltestu01 -lprobdist -lmylib -lm
CFLAGS := -Wall

SRCS := $(wildcard *.c)
BINS := $(patsubst %.c,%,$(SRCS))
OBJS := $(patsubst %,%.o,$(BINS))

all: $(BINS)

clean:
	$(RM) $(BINS)

rebuild: clean all

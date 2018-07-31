CC := gcc
LDFLAGS := -ltestu01 -lprobdist -lmylib -lm
CFLAGS := -Wall

SRCS := $(wildcard *.c)
BINS := $(patsubst %.c,%,$(SRCS))
OBJS := $(patsubst %,%.o,$(BINS))

all: $(BINS)

test: test.c morton.h util.h
	gcc -o test test.c

run: 
	$(foreach x,$(BINS),./$(x) >> $(x).txt;)

big:
	sed -i -e 's/SmallCrush/BigCrush/g' $(SRCS)

small:
	sed -i -e 's/BigCrush/SmallCrush/g' $(SRCS)

clean:
	$(RM) $(BINS)

rebuild: clean all

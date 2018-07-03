CC := gcc
LDFLAGS := -ltestu01 -lprobdist -lmylib -lm
CFLAGS := -Wall

SRCS := $(wildcard *.c)
BINS := $(patsubst %.c,%,$(SRCS))
OBJS := $(patsubst %,%.o,$(BINS))

define \n

endef

all: $(BINS)

run: 
	$(foreach x,$(BINS),./$(x);)

clean:
	$(RM) $(BINS)

rebuild: clean all

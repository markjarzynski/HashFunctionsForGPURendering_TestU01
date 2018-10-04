CC := g++
LDFLAGS := -ltestu01 -lprobdist -lmylib -lm
CPPFLAGS := -O2 -Wall

SRCS := $(wildcard *.c)
BINS := $(patsubst %.c,%,$(SRCS))
OBJS := $(patsubst %,%.o,$(BINS))

all: $(BINS)

run: 
	$(foreach x,$(BINS),./$(x) >> $(x).txt;)

big:
	sed -i -e 's/SmallCrush/BigCrush/g' $(SRCS)

small:
	sed -i -e 's/BigCrush/SmallCrush/g' $(SRCS)

clean:
	$(RM) $(BINS)

rebuild: clean all

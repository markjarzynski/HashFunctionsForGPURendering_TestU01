CC := g++
LDFLAGS := -ltestu01 -lprobdist -lmylib -lm
CPPFLAGS := -O2 -Wall

SRCS := $(wildcard *.c)
BINS := $(patsubst %.c,%,$(SRCS))
OBJS := $(patsubst %,%.o,$(BINS))

all: $(BINS)

.PHONY: run big small clean

run:
ifdef r
	gstdbuf -o 0 ./$(r) | tee $(r).txt
else
	$(foreach x,$(BINS),gstdbuf -i 0 ./$(x) | tee $(x).txt;)
endif

big:
	sed -i -e 's/SmallCrush/BigCrush/g' $(SRCS)

small:
	sed -i -e 's/BigCrush/SmallCrush/g' $(SRCS)

clean:
	$(RM) $(BINS)

rebuild: clean all

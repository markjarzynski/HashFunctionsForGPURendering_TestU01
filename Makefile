CXX := mpiicpc
LDFLAGS := -Iinclude -ltestu01 -lprobdist -lmylib -lm
CPPFLAGS := -std=c++11 -O2 -Wall

SRCS := $(wildcard *.cpp)
BINS := $(patsubst %.cpp,%,$(SRCS))
OBJS := $(patsubst %,%.o,$(BINS))

all: $(BINS)

.PHONY: clean

clean:
	$(RM) $(BINS)

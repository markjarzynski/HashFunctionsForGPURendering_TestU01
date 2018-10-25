CC := g++
LDFLAGS := -ltestu01 -lprobdist -lmylib -lm
CPPFLAGS := -std=c++11 -O2 -Wall

SRCS := $(wildcard *.c)
BINS := $(patsubst %.c,%,$(SRCS))
OBJS := $(patsubst %,%.o,$(BINS))

hashes := bbs city fast ign iqint1 iqint2 iqint2.x iqint2.y iqint2.z iqint3 jkiss32 lcg murmur3 \
	pg3d pcg3d.x pcg3d.y pcg3d.z pcg3d16 pcg3d16.x pcg3d16.y pcg3d16.z pseudo ranlim32 sca08 superfast \
    tea2 tea2.x tea2.y tea3 tea3.x tea3.y tea4 tea4.x tea4.y tea5 tea5.x tea5.y tea6 tea6.x tea6.y \
	trig wang xorshift32 xxhash32 Rand3DPCG32

all: $(BINS)

cluster:
	/usr/cluster/contrib/gcc/gcc-5.5.0/bin/g++ -std=c++11 -O3 -Wall -o main main.cpp -Iinclude -Llib -ltestu01 -lprobdist -lmylib -lm

.PHONY: run clean

run:
ifdef r
	gstdbuf -o 0 ./main $(r) | tee $(r).txt
else
	$(foreach x,$(hashes),gstdbuf -i 0 ./main $(x) | tee $(x).txt;)
endif

clean:
	$(RM) $(BINS)

rebuild: clean all

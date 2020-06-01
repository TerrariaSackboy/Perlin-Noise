SHELL = /bin/bash
CXX = g++
CFLAGS = -Wall -Wextra -ggdb
SDIR = src
BDIR = build
LODEPNG_DIR = lodepng

project_path = $(shell pwd)

CFLAGS += -I$(project_path)/$(LODEPNG_DIR)

_obj0 = vector2.o
_obj1 = noise.o
_obj2 = main.o
_obj = $(_obj0) $(_obj1) $(_obj2)
obj = $(patsubst %,$(BDIR)/%,$(_obj))

$(BDIR)/%.o: $(SDIR)/%.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

perlin-noise: $(obj) $(BDIR)/lodepng.o
	$(CXX) -o $@ $^ $(CFLAGS)

$(BDIR)/lodepng.o: $(LODEPNG_DIR)/lodepng.cpp
	$(CXX) -c -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(obj)
	rm -f perlin-noise


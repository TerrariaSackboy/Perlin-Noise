SHELL = /bin/bash
CXX = g++
CFLAGS = -Werror -Wextra -ggdb
SDIR = src
BDIR = build

_obj0 = main.o
_obj = $(_obj0)
obj = $(patsubst %,$(BDIR)/%,$(_obj))

$(BDIR)/%.o: $(SDIR)/%.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

perlin-noise: $(obj)
	$(CXX) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(obj)
	rm -f perlin-noise


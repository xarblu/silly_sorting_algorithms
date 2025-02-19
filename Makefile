# simple makefile

CXX := clang++
CXXFLAGS := -O3 -pipe

SRCDIR := src
BINDIR := bin

all: just_malloc_it_sort

just_malloc_it_sort: $(BINDIR)/just_malloc_it_sort

$(BINDIR)/%: $(BINDIR) $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(subst bin,src,$@).cpp -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

.PHONY: all just_malloc_it_sort

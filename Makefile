CXX := g++
CFLAGS := -std=c++11 -lm -lcrypt -O2 -pipe #TODO: Flags

SRCDIR := ./src
BUILDDIR := ./build
TESTDIR := ./tests

ej1DIR := $(SRCDIR)/ej1
ej2DIR := $(SRCDIR)/ej2
ej3DIR := $(SRCDIR)/ej3
ej4DIR := $(SRCDIR)/ej4

ENTREGA := Cappella_Mallol_Teplizky_Stemberg.zip

default: main
.PHONY: clean

entrega: clean
	zip $(ENTREGA) Makefile README.md consignas src -r9
	
all: clean builddir main debug test submit
main: clean builddir ej1_main ej2_main ej3_main ej4_main
debug: clean builddir ej1_debug ej2_debug ej3_debug ej4_debug
submit: clean builddir ej1_submit ej2_submit ej3_submit ej4_submit

%_main: builddir
	$(CXX) $(CFLAGS) -I$($*DIR) $($*DIR)/*.cc -o $(BUILDDIR)/$*

%_debug: builddir
	$(CXX) $(CFLAGS) -I$($*DIR) -g -D DEBUG $($*DIR)/*.cc -o $(BUILDDIR)/$@

ej1_submit: builddir
	@printf "To submit ej1 do: \ncat $(ej1DIR)/{utils.h,dfs.h,*.cc} > $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed -i '/#include \"/d' $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@\n"

ej2_submit: builddir
	@printf "To submit ej2 do: \ncat $(ej2DIR)/{utils.h,disjoint.h,*.cc} > $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed -i '/#include \"/d' $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@\n"

ej3_submit: builddir
	@printf "To submit ej3 do:\ncat $(ej3DIR)/{utils.h,dijkstra.h,*.cc} > $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed -i '/#include \"/d' $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@\n"

ej4_submit: builddir
	@printf "To submit ej4 do:\ncat $(ej4DIR)/{utils.h,fishburn.h,*.cc} > $(BUILDDIR)/$@.cc && sed -i '/#pragma once/d' $(BUILDDIR)/$@.cc && sed -i '/#include \"/d' $(BUILDDIR)/$@.cc && $(CXX) $(CFLAGS) $(BUILDDIR)/$@.cc -o $(BUILDDIR)/$@\n"

builddir:
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR) $(ENTREGA)

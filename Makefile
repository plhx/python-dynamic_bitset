# python3-dynamic_bitset Makefile
#
# Copyright (c) 2017, PlasticHeart
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# The views and conclusions contained in the software and documentation are
# those of the authors and should not be interpreted as representing official
# policies, either expressed or implied, of the FreeBSD Project.

ARCH           =

CC             = gcc
CXX            = g++

VERSION        = 1.63.0

ifeq ($(ARCH), arm)
CROSS          = arm-linux-gnueabihf
CROSS_COMPILE  = $(CROSS_COMPILE)-
CXXFLAGS      += -I/usr/$(CROSS)/boost/$(VERSION)/include
CXXFLAGS      += -L/usr/$(CROSS)/boost-python/$(VERSION)/lib
endif

ifeq ($(ARCH), darwin)
CC             = clang
CXX            = clang++
CXXFLAGS      += -I/usr/local/Cellar/boost/$(VERSION)/include
CXXFLAGS      += -L/usr/local/Cellar/boost-python/$(VERSION)/lib
CXXFLAGS      += `pkg-config --cflags --libs /usr/local/Cellar/python3/3.6.1/Frameworks/Python.framework/Versions/3.6/lib/pkgconfig/python3.pc`
endif

ifeq ($(ARCH), linux)
CXXFLAGS      += -I/usr/local/boost/$(VERSION)/include
CXXFLAGS      += -L/usr/local/boost-python/$(VERSION)/lib
CXXFLAGS      += `pkg-config --cflags --libs python3.pc`
endif

ifeq ($(ARCH), win)
$(error 'not yet implemented')
endif

CFLAGS        += -fPIC -O2 -Wall
CXXFLAGS      += $(CFLAGS)
CXXFLAGS      += -lboost_python3

AR             = $(CROSS_COMPILE)ar
LD             = $(CROSS_COMPILE)ld
RANLIB         = $(CROSS_COMPILE)ranlib

export AR CC CXX CFLAGS CXXFLAGS LIB RANLIB


PYTHON3_DYNAMIC_BITSET = python3-dynamic_bitset.so.$(VERSION)

.PHONY: all
all: $(PYTHON3_DYNAMIC_BITSET)
	ln -s $(PYTHON3_DYNAMIC_BITSET) dynamic_bitset.so

$(PYTHON3_DYNAMIC_BITSET): python3-dynamic_bitset.o
	$(CXX) -shared $(CXXFLAGS) -o $@ $^

.SUFFIXES: .o .cpp
.o .cpp:
	$(CXX) $(CXXFLAGS) -c $^

.PHONY: clean
clean:
	rm -f *.o

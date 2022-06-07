#/bin/sh
CC  	= gcc
CFLAGS    = -fpic -c
SHARED    = -shared
CXXFLAGS  = 
INCLUDE   = -I../include/
TARGET    = libmylib.so
LIBPATH   = ./lib/
EXT 	  =c
TOP       =.

VPATH				+= $(TOP)

#OBJS      = list.o dlist.o
SRCS      += $(shell find $(TOP) -name '*.$(EXT)')
C_SRC_NODIR	+= $(notdir $(SRCS))
OBJS	  += $(patsubst %.$(EXT), %.o,$(C_SRC_NODIR))

$(TARGET):$(OBJS)
	$(CC) $(SHARED) $^ -o $@ -lm
	mv $(TARGET) $(LIBPATH)
$(OBJS):$(C_SRC_NODIR)
	$(CC) $(CFLAGS) $^ $(INCLUDE)
clean:
	rm -f *.o
	rm -f ${LIBPATH}*
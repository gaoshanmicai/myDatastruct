# myDatastruct
这个文件中主要是Mastering Algorithms with C书的源代码 
使用共享库来对程序进行编译等等 
首先进入source中 
1. make
    编译libmylib.so
2. 在代码中引用相关的动态库头文件

```makefile
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
	$(CC) $(SHARED) $^ -o $@
	mv $(TARGET) $(LIBPATH)
$(OBJS):$(C_SRC_NODIR)
	$(CC) $(CFLAGS) $^ $(INCLUDE)
clean:
	rm -f *.o
	rm -f ${LIBPATH}*
```
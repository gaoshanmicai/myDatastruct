
SRCFILES := Mathfunctions.cc Mathfunctions.h main.cc
OBJFILES := Mathfunctions.o main.o
TARGET = Demo

$(TARGET):$(OBJFILES)
	$(CXX) $(OBJFILES) -o $@
$(OBJFILES):$(SRCFILES)
	$(CC) Mathfunctions.cc -c
	$(CC) main.cc -c
.PHONY:
clean:.PHONY
	rm -RF $(OBJFILES)$(TARGET)
	

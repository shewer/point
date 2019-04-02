
CC = c99
CFLAGS = -g -I./include
LIBS = 
TARGET = chk_ptr
OBJECT = main.o point.o 

all : $(TARGET)

#*c : *.h ./include/*.h
#	touch $*

*.o : *.c
	$(CC) $(CFLAGS) -c -o $*.o $<

#*.s : *.c
#	$(CC) $(CFLAGS) -s -o $*.s $<

#*.m : *.c
#	$(CC) $(CFLAGS) -E -o $*.m $<

$(TARGET) : $(OBJECT)
	$(CC) $(OBJECT) $(CFLAGS) $(LIBS) -o $@



.PHONY: all clean run

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./chk_ptr




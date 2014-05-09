CC=avr-gcc
CFLAGS=-g -Os -Wall -mmcu=atmega164a -DF_CPU=1000000UL
OBJ2HEX=avr-objcopy
ADFLAGS=-c jtag2 -p m164a

SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c, obj/%.o, $(SRC))

TARGET=receiver
HEX=$(TARGET).hex


.PHONY: clean upload

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

obj/%.o: src/%.c obj
	$(CC) $(CFLAGS) -c -Iinclude/ $< -o $@

$(HEX): $(TARGET)
	$(OBJ2HEX) -O ihex $< $@

upload: $(HEX)
	avrdude $(ADFLAGS) -e -U flash:w:$(HEX)

obj:
	mkdir obj

clean:
	rm -rf receiver *.hex obj

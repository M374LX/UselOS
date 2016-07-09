CFLAGS  := -fno-stack-protector -fno-builtin -nostdinc -O -g -I.
LDFLAGS := -nostdlib -Wl,-N -Wl,-Ttext -Wl,100000

TARGET := UselOS
OBJS := start.o main.o ioports.o screen.o keyboard.o console.o ush.o ush_commands.o

all:	$(TARGET).bin

$(TARGET).bin: $(OBJS)
	ld -T linker.ld -o $@ $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

%.o: %.s
	as $< -o $@

iso:
	mkdir -p iso/boot/grub
	cp $(TARGET).bin iso/boot/
	cp grub.cfg iso/boot/grub
	grub-mkrescue -o $(TARGET).iso iso
	rm -r iso

clean: 
	rm -f *.o *.bin $(TARGET).iso


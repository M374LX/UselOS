CFLAGS  := -m32 -fno-stack-protector -fno-builtin -nostdinc -O -g -I.

TARGET := UselOS
OBJS := start.o main.o ioports.o screen.o keyboard.o console.o ush.o ush_commands.o

all:	$(TARGET).bin

$(TARGET).bin: $(OBJS)
	ld -m elf_i386 -T linker.ld -o $@ $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

%.o: %.s
	as --32 $< -o $@

iso:
	mkdir -p iso/boot/grub
	cp $(TARGET).bin iso/boot/
	cp grub.cfg iso/boot/grub
	grub-mkrescue -o $(TARGET).iso iso
	rm -r iso

clean: 
	rm -f *.o *.bin $(TARGET).iso


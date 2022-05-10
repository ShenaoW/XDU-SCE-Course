cc=gcc

all: exploit stack setuid setuid.asm stack.asm exploit.asm

.PHONY : clean

exploit.asm:exploit
	objdump -d exploit > exploit.asm

stack.asm:stack
	objdump -d stack > stack.asm

setuid.asm:setuid
	objdump -d setuid > setuid.asm

setuid: setuid.o
	cc -m32 -no-pie -z execstack -fno-stack-protector -o setuid setuid.o

setuid.o: setuid.c
	cc -m32 -no-pie -z execstack -fno-stack-protector -c setuid.c

exploit: exploit.o
	cc -m32 -no-pie -z execstack -fno-stack-protector -o exploit exploit.o

exploit.o: exploit.c
	cc -m32 -no-pie -z execstack -fno-stack-protector -c exploit.c

stack: stack.o
	cc -m32 -no-pie -z execstack -fno-stack-protector -o stack stack.o

stack.o: stack.c
	cc -m32 -no-pie -z execstack -fno-stack-protector -c stack.c

clean:
	rm *.asm
	rm *.o

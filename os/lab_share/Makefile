all: mycp write read

mycp:share.c
	gcc share.c -o mycp
write:write.c pv.c
	gcc write.c -o write
read:read.c pv.c
	gcc read.c -o read

.PHONY: clean
clean:
	rm mycp write read

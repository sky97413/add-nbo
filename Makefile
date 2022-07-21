SHELL = bash

add-nbo: main.c thousand.bin five-hundred.bin
	gcc -o add-nbo ./main.c
	
thousand.bin:  
	echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
five-hundred.bin:
	echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin

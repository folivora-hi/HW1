all:merg_int.o quick_int.o heap_int.o quick_char.o heap_char.o

merg_int.o:merg_int.c dataset1.txt
	gcc merg_int.c -o mint
	cat dataset1.txt | ./mint
quick_int.o:quick_int.c dataset1.txt
	gcc quick_int.c -o qint
	cat dataset1.txt | ./qint
heap_int.o:heap_int.c dataset1.txt
	gcc heap_int.c -o hint
	cat dataset1.txt | ./hint
quick_char.o:quick_char.c dataset2.txt
	gcc quick_char.c -o qar
	cat dataset2.txt | ./qar
heap_char.o:heap_char.c dataset2.txt
	gcc heap_char.c -o har
	cat dataset2.txt | ./har

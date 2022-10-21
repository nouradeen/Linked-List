#Link command
huvud: huvud.o node.h list/list.o driv/driv.o
	gcc -o program huvud.o list/list.o driv/driv.o

#Compilation commands
huvud.o: huvud.c driv/driv.h node.h
	gcc -c huvud.c
node.o: node.c
	gcc -c node.c
list.o: list.c ../node.h
	gcc -c list.c
driv.o: driv.c ../list/list.h ../node.h
	gcc -c driv.c
zad1: zad1.c
	gcc -Wall -pedantic -std=gnu89 zad1.c -o zad1

zad2: zad2.c
	gcc -Wall -pedantic -std=gnu89 zad2.c -o zad2

server: server.c
	gcc -Wall -pedantic -std=gnu99 -g -fdiagnostics-color=always -fsanitize=address server.c -o server

client: client.c
	gcc -Wall -pedantic -std=gnu99 -g -fdiagnostics-color=always -fsanitize=address client.c -o client

clean:
	rm -f zad1 zad2 server client
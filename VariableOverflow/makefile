CC=gcc -g -fno-stack-protector
Flags=-Wl, -no-pie

server: main.o httpd.o includes.o
	$(CC) main.o httpd.o includes.o -o server $(Flags)

main.o: main.c httpd.h includes.h
	$(CC) main.c -c

httpd.o: httpd.c httpd.h
	$(CC) httpd.c -c

includes.o: includes.c includes.h
	$(CC) includes.c -c

clean: 
	rm -f *.o server

# server: main.o httpd.o includes.o
# 	gcc main.o httpd.o includes.o -o server

# main.o: main.c httpd.h includes.h
# 	gcc main.c -c

# httpd.o: httpd.c httpd.h
# 	gcc httpd.c -c

# includes.o: includes.c includes.h
# 	gcc includes.c -c

# clean: 
# 	rm -f *.o server

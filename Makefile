INCLUDE = /usr/local/libcurl/include/
LIBRARY = /usr/local/libcurl/lib/

#DEBUG = -g
CFLAGS = -I$(INCLUDE) -c $(DEBUG)
OFLAGS = -L$(LIBRARY) -lcurl
OSSLFLAGS = -L/usr/local/openssl/lib/ -lssl

http.o: http.c
	gcc $(CFLAGS) http.c  

http: http.o
	gcc -o http http.o $(OFLAGS)

https.o: https.c
	gcc $(CFLAGS) https.c  
	
https: https.o
	gcc -o https https.o $(OFLAGS) $(OSSLFLAGS)

post.o: post.c
	gcc $(CFLAGS) post.c  
	
post: post.o
	gcc -o post post.o $(OFLAGS)

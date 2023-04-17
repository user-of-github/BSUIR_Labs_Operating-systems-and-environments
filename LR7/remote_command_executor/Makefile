COMPILER = g++
OPTIONS = -pthread   # -pthread ==> because I had error "undefined reference to `pthread_create'"

build: client server

server: clean_server
	$(COMPILER) -o server_app ./server.cpp ./shared.hpp $(OPTIONS)

client: clean_client
	$(COMPILER) -o client_app ./client.cpp ./shared.hpp $(OPTIONS)

clean: clean_server clean_client

clean_server:
	rm -rf server_app

clean_client:
	rm -rf client_app


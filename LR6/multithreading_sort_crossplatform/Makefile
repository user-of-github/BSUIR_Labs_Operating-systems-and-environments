run: build
	./main_app
	rm -rf ./main_app


build: clean
	g++ -o main_app ./main.cpp ./sort_service.cpp -pthread -std=c++2a


clean:
	rm -rf ./main_app
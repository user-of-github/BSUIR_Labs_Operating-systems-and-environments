run: all
	./main_app
	rm -rf main_app
	rm -rf transform_app


all: clean main compute_data_from_shared_memory

main:
	g++ -o main_app main.cpp ./shared/shared.cpp -std=c++17

compute_data_from_shared_memory:
	g++ -o transform_app compute_data_from_shared_memory.cpp ./shared/shared.cpp

clean:
	rm -rf transform_app
	rm -rf main_app
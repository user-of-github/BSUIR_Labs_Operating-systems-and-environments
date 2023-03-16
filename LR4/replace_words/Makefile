CXXFLAGS=-g -std=c++20 -std=gnu++20 -Wall -pedantic

all: clean
	g++ main.cpp ./utils/utils.hpp ./data_reader/data_reader.hpp ./convert_text/convert_text.hpp ./utils/utils.cpp ./data_reader/data_reader.cpp ./convert_text/convert_text.cpp -o text_converter  -std=c++20 -std=gnu++20

test: clean
	g++ -std=c++17 -std=gnu++17 test.cpp ./utils/utils.hpp ./convert_text/convert_text.hpp ./utils/utils.cpp ./convert_text/convert_text.cpp -o test_app  -std=c++17 -std=gnu++17
	./test_app

clean:
	rm -rf test_app
	rm -rf text_converter
all: clean
	g++ main.cpp ./utils/utils.cpp ./errors_checker/errors_checker.cpp ./data_reader/data_reader.cpp -o text_error_checker -std=c++20 -std=gnu++20

test: clean
	g++ test.cpp ./utils/utils.cpp ./errors_checker/errors_checker.cpp -o test_program -std=c++20 -std=gnu++20
	./test_program

clean:
	rm -rf ./test_program
	rm -rf ./text_error_checker
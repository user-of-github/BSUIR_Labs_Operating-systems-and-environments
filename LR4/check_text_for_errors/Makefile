all: clean
	g++ main.cpp ./lib/errors_checker.a -o text_error_checker -std=c++20 -std=gnu++20

test: clean
	g++ test.cpp ./lib/errors_checker.a -o test_program -std=c++20 -std=gnu++20
	./test_program

clean:
	rm -rf ./test_program
	rm -rf ./text_error_checker
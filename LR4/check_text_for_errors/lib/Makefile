all:
	rm -rf data_reader.o
	rm -rf errors_checker.o
	rm -rf utils.o
	rm -rf errors_checker.a
	g++ -c ./utils.cpp ./data_reader.cpp ./errors_checker.cpp
	ar -r errors_checker.a ./utils.o ./data_reader.o ./errors_checker.o
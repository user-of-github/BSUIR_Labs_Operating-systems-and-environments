all: clean first second destroy_shared_memory

first:
	g++ -o first_app first.cpp ./shared/shared.cpp

second:
	g++ -o second_app second.cpp ./shared/shared.cpp

destroy_shared_memory:
	g++ -o destroy_shared_memory_app destroy_shared_memory.cpp ./shared/shared.cpp

clean:
	rm -rf destroy_shared_memory_app
	rm -rf second_app
	rm -rf first_app
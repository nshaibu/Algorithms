CC=g++

all: list

list: ./dlinked_list.cpp ./List.o
	$(CC) -g -Wall -Werror ./dlinked_list.cpp -o list ./List.o
List.o: ./List.cpp List.h
	$(CC) -g -std=c++11 -Wall -Werror -c ./List.cpp
	
clean:
	rm -f ./List.o ./list
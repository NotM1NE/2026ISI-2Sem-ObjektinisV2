vector_app: main_vector.o io_vector.o student.o utils.o
	g++ -o vector_app main_vector.o io_vector.o student.o utils.o

main_vector.o:
	g++ -Iinclude -c src/main_vector.cpp

io_vector.o:
	g++ -Iinclude -c src/io_vector.cpp

list_app: main_list.o io_list.o student.o utils.o
	g++ -o list_app main_list.o io_list.o student.o utils.o

main_list.o:
	g++ -Iinclude -c src/main_list.cpp

io_list.o:
	g++ -Iinclude -c src/io_list.cpp

deque_app: main_deque.o io_deque.o student.o utils.o
	g++ -o deque_app main_deque.o io_deque.o student.o utils.o

main_deque.o:
	g++ -Iinclude -c src/main_deque.cpp

io_deque.o:
	g++ -Iinclude -c src/io_deque.cpp

student.o:
	g++ -Iinclude -c src/student.cpp

utils.o:
	g++ -Iinclude -c src/utils.cpp

clean:
	rm -f *.o vector_app list_app deque_app
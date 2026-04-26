CXX = g++
CXXFLAGS = -Iinclude

DEQUE_SRC = src/main_deque.cpp src/io_deque.cpp src/student.cpp src/utils.cpp

vector_app: main_vector.o io_vector.o student.o utils.o
	$(CXX) -o vector_app main_vector.o io_vector.o student.o utils.o

main_vector.o:
	$(CXX) $(CXXFLAGS) -c src/main_vector.cpp

io_vector.o:
	$(CXX) $(CXXFLAGS) -c src/io_vector.cpp

list_app: main_list.o io_list.o student.o utils.o
	$(CXX) -o list_app main_list.o io_list.o student.o utils.o

main_list.o:
	$(CXX) $(CXXFLAGS) -c src/main_list.cpp

io_list.o:
	$(CXX) $(CXXFLAGS) -c src/io_list.cpp

deque_app: main_deque.o io_deque.o student.o utils.o
	$(CXX) -o deque_app main_deque.o io_deque.o student.o utils.o

main_deque.o:
	$(CXX) $(CXXFLAGS) -c src/main_deque.cpp

io_deque.o:
	$(CXX) $(CXXFLAGS) -c src/io_deque.cpp

student.o:
	$(CXX) $(CXXFLAGS) -c src/student.cpp

utils.o:
	$(CXX) $(CXXFLAGS) -c src/utils.cpp

deque_struct_O1:
	$(CXX) $(CXXFLAGS) -O1 $(DEQUE_SRC) -o deque_struct_O1.exe

deque_struct_O2:
	$(CXX) $(CXXFLAGS) -O2 $(DEQUE_SRC) -o deque_struct_O2.exe

deque_struct_O3:
	$(CXX) $(CXXFLAGS) -O3 $(DEQUE_SRC) -o deque_struct_O3.exe

opt_struct: deque_struct_O1 deque_struct_O2 deque_struct_O3

clean:
	rm -f *.o vector_app list_app deque_app deque_struct_O1.exe deque_struct_O2.exe deque_struct_O3.exe
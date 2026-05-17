CXX = g++
CXXFLAGS = -std=c++17 -O2

test: MyVector-test.cpp
	$(CXX) $(CXXFLAGS) -Iinclude MyVector-test.cpp -o MyVectorTest.exe
	./MyVectorTest.exe

benchmark: benchmark.cpp
	$(CXX) $(CXXFLAGS) -Iinclude benchmark.cpp -o Benchmark.exe
	./Benchmark.exe

studentai-myvector:
	$(CXX) $(CXXFLAGS) -I8-uzduotis/include -Iinclude 8-uzduotis/src/main_vector.cpp 8-uzduotis/src/io_vector.cpp 8-uzduotis/src/student.cpp 8-uzduotis/src/utils.cpp -o StudentaiMyVector.exe

studentai-std:
	$(CXX) $(CXXFLAGS) -I8-uzduotisOld/include 8-uzduotisOld/src/main_vector.cpp 8-uzduotisOld/src/io_vector.cpp 8-uzduotisOld/src/student.cpp 8-uzduotisOld/src/utils.cpp -o StudentaiStdVector.exe

clean:
	rm -f *.o *.exe MyVectorTest.exe Benchmark.exe StudentaiMyVector.exe StudentaiStdVector.exe
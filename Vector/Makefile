CXX = g++
CXXFLAGS = -Iinclude

test: MyVector-test.cpp
	$(CXX) $(CXXFLAGS) MyVector-test.cpp -o MyVectorTest.exe

benchmark : benchmark.cpp
	$(CXX) $(CXXFLAGS) benchmark.cpp -o Benchmark.exe

clean:
	rm -f *.o *.exe MyVectorTest.exe Benchmark.exe
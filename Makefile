CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

LLREC_OBJS = llrec.o llrec-test.o
STACK_OBJS = stack-test.o
HEAP_OBJS = heap-test.o

# Build all executables.
all: llrec-test stack-test heap-test

#-----------------------------------------------------
# llrec-test target
#-----------------------------------------------------
llrec-test: $(LLREC_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(LLREC_OBJS)

llrec-test.o: llrec.h llrec-test.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ llrec-test.cpp

llrec.o: llrec.h llrec.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ llrec.cpp

#-----------------------------------------------------
# stack-test target
#-----------------------------------------------------
stack-test: $(STACK_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(STACK_OBJS)

stack-test.o: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) -c -o $@ stack-test.cpp

#-----------------------------------------------------
# heap-test target
#-----------------------------------------------------
heap-test: $(HEAP_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(HEAP_OBJS)

heap-test.o: heap-test.cpp heap.h
	$(CXX) $(CXXFLAGS) -c -o $@ heap-test.cpp

#-----------------------------------------------------
# Clean up build files
#-----------------------------------------------------
clean:
	rm -f *.o llrec-test stack-test heap-test *~

.PHONY: clean

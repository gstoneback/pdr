CXX = g++
CXXFLAGS = -Iinclude -O3 --std=c++17
OBJS = src/main.o
all: pdr
pdr: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o pdr

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -I/usr/include/SFML

# Libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lboost_random -lboost_system

# Source files
SRCS = src/route.cpp \
       src/point.cpp \
       src/consts.cpp \
       src/bitset.cpp \
       src/main.cpp \
       src/algo/algo.cpp \
       src/algo/donothing.cpp \
       src/algo/permutation.cpp \
       src/algo/shortest.cpp

# Output executable
TARGET = traveling_salesman

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
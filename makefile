# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -I./include -I./include/sortHeader

# Source directories
SRC_DIR = src
SRC_SORT_DIR = src/sortSource

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_SORT_DIR)/*.cpp)

# Output executable
TARGET = main

# Build rule
$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC_FILES)

# Clean rule
clean:
	rm -f $(TARGET)

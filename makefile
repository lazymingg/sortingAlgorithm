# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -I include

# Linker flags
LDFLAGS = -mconsole

# Sources
SRCS := $(wildcard src/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = my_program

# Default target
all: $(EXEC)

# Link
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean

#g++ -o main src/*.cpp -I ./include/

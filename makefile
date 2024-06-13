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

# g++ -I include -o my_program src/*.cpp
# //compile main.cpp
# //g++ -I include -c main.cpp -o src/main.o
# // link all object files
# //g++ src/main.o src/other.o -o my_program -mconsole
# help me write make file 
#my program is the executable file
#src is the folder where all the source files are present
# include is the folder where all the header files are present



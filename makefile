TARGET = bst
CXXFLAGS = -std=c++17 -Os -Wall -pedantic

BINDIR =  bin
OBJDIR = obj

SRCDIR =  src
TREEDIR = $(SRCDIR)/tree

.PHONY: default all clean

default: $(BINDIR)/$(TARGET)
all: default

INCLUDES = -I $(TREEDIR)

SRCS = $(wildcard $(SRCDIR)/*.cpp $(TREEDIR)/*.cpp)
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))
HEADERS = $(wildcard $(TREEDIR)/*.h)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@echo $(CXX) "     "$@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	@$(CXX) $(OBJECTS) $(LIBS) -o $@
	@echo "Created: "$@

clean:
	$(RM) -r $(OBJDIR) $(BINDIR)
TARGET = gusevmak

SRCS  = $(shell find ./src/Sources -type f -name *.cpp)
HEADS = $(shell find ./src/Headers -type f -name *.h)
OBJS = $(SRCS:.cpp=.o)
DEPS = Makefile.depend

INCLUDES = -I./src/Headers
CXXFLAGS = -std=c++17 -O2 -Wall -lstdc++fs $(INCLUDES)
LDFLAGS = -lm


all: $(TARGET)

$(TARGET): $(OBJS) $(HEADS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

run: all
	@./$(TARGET)

.PHONY: depend clean
depend:
	$(CXX) $(INCLUDES) -MM $(SRCS) > $(DEPS)
	@sed -i -E "s/^(.+?).o: ([^ ]+?)\1/\2\1.o: \2\1/g" $(DEPS)

clean:
	$(RM) $(OBJS) $(TARGET)

compile : $(TARGET) $(OBJS) $(HEADS)

-include $(DEPS)
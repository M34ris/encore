CC=clang
TARGET=test
INC=/home/jihan/uni/exjobb/sync/release/inc/
LIB=/home/jihan/uni/exjobb/sync/release/lib/*.a
FLAGS=-std=gnu11 -Wall -fms-extensions -Wno-format -Wno-microsoft -Wno-parentheses-equality -Wno-unused-variable -Wno-unused-value  -lpthread -ldl -lm -Wno-attributes /home/jihan/uni/exjobb/sync/release/lib/*.a -I /home/jihan/uni/exjobb/sync/release/inc/ -I . 
BENCH_FLAGS=-std=gnu11 -Wall -fms-extensions -Wno-format -Wno-microsoft -Wno-parentheses-equality -Wno-unused-variable -Wno-unused-value  -lpthread -ldl -lm -Wno-attributes /home/jihan/uni/exjobb/sync/release/lib/*.a -I /home/jihan/uni/exjobb/sync/release/inc/ -I . 
DEFINES=
DEPS=shared.c Main.encore.c Foo.encore.c String.encore.c

all: $(TARGET)

$(TARGET): $(DEPS)
	$(CC) $(FLAGS) -I $(INC) -I .. $(DEPS) $(LIB) $(LIB) $(DEFINES) -o $(TARGET)

bench: $(DEPS)
	$(CC) $(BENCH_FLAGS) -I $(INC) -I .. $(DEPS) $(LIB) $(LIB) $(DEFINES) -o $(TARGET)

clean:
	rm -rf $(TARGET) $(TARGET).dSYM

.PHONY: all bench clean

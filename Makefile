TARGET := loxone

CC := g++
CFLAGS := -MD -Wall

PREF_SRC := src/
PREF_OBJ := build/
PREF_BIN := bin/
PREF_INC := $(PREF_SRC)include/

ARCH_NAME := Loxone_test_task

SRCS = $(wildcard $(PREF_SRC)*.cpp)
OBJS = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRCS))

all: dir $(TARGET) install

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(PREF_OBJ)%.o: $(PREF_SRC)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(PREF_INC)

install:
	install $(TARGET) $(PREF_BIN)
	rm -f $(TARGET)

dir:
	mkdir -p $(PREF_BIN)
	mkdir -p $(PREF_OBJ)

clean:
	rm -rf $(PREF_BIN)
	rm -rf $(PREF_OBJ)
	rm -f $(ARCH_NAME).zip

zip:
	@zip $(ARCH_NAME).zip $(PREF_SRC)*.cpp $(PREF_INC)*.h Makefile README.md

.PHONY: all clean zip

-include $(OBJS:.o=.d)

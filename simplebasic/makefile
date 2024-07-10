APP_NAME = sbt

SRC_EXT = cpp
CC = g++
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

APP_SOURCES = $(wildcard *.$(SRC_EXT))
APP_OBJECTS := $(patsubst %.$(SRC_EXT),%.o,$(APP_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_NAME)

-include $(DEPS)

$(APP_NAME): $(APP_OBJECTS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

%.o: %.$(SRC_EXT)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(APP_OBJECTS) $(DEPS) $(APP_NAME)
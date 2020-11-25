BUILD_DIR = ./build
CC = gcc
LD = gcc
LIB = -I include/
CFLAGS = -c $(LIB)

OBJS = $(BUILD_DIR)/test.o

###### 编译 ######
$(BUILD_DIR)/test.o: test.c include/set_ticker.h include/stdint.h
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/list.o: list.c include/list.h
	$(CC) $(CFLAGS) $< -o $@

###### 链接 ######
$(BUILD_DIR)/test: $(OBJS)
	$(LD) $(^) -o $@

.PHONY: mk_dir clean all

mk_dir:
	if [[ ! -d $(BUILD_DIR) ]]; then mkdir $(BUILD_DIR);fi

clean:
	cd $(BUILD_DIR) && rm -f ./*

build: $(BUILD_DIR)/test

all:mk_dir build

BUILD_DIR = ./build
CC = gcc
LD = ld
LIB = -I include/
CFLAGS = -c
LDFLAGS = 

###### 编译 ######
$(BUILD_DIR)/test.o: test.c include/set_ticker.h
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/list.o: list.c include/list.h
	$(CC) $(CFLAGS) $< -o $@

.PHONY: mk_dir clean all

mk_dir:
	if[[ ! -d $(BUILD_DIR) ]]; then mkdir $(BUILD_DIR); fi

clean:
	cd $(BUILD_DIR) && rm -f ./*

build: $(BUILD_DIR)/test

all:mk_dir build hd
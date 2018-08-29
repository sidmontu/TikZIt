CC 		:= gcc
CFLAGS 	:= -O3 -fPIC -I./include

all : build

dir : 
	@mkdir -p build

build : dir
	@$(CC) $(CFLAGS) src/main.c src/argparse.c -o./build/tikzit

clean :
	@rm -rf build

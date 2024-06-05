# THIS IS AN AUTOGENERATED FILE. DO NOT EDIT!
all: build/ncurses.exe
	@echo Run: build/ncurses.exe
	@echo
	@./build/ncurses.exe
build/ncurses.exe: build/ build/demonstration.o build/main.o
	@echo Link: ncurses.exe
	@clang -lncursesw build/*.o -o build/ncurses.exe
build/:
	@echo Create: build/
	@mkdir build/
build/demonstration.o: demonstration.c demonstration.h
	@echo Compile: demonstration.c
	@clang -std=c17 -Weverything  -I. -c demonstration.c -o $@
build/main.o: main.c demonstration.h
	@echo Compile: main.c
	@clang -std=c17 -Weverything  -I. -c main.c -o $@
clean:
	@echo Clean
	@rm -fr build

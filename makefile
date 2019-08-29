RELEASE_NAME=release
DEBUG_NAME=debug
ODIR=objects

all: main.o
	gcc -o $(RELEASE_NAME) main.c

debug: main.o
	gcc -o $(DEBUG_NAME) -g main.c


.PHONY: clean

clean:
	rm -f ./*.o ./$(DEBUG_NAME) ./$(RELEASE_NAME)

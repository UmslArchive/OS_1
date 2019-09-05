RELEASE_NAME=dt

ALL: main.o
	gcc -o $(RELEASE_NAME) main.c Options.c FileSystem.c Print.c -g -I .

.PHONY: clean

clean:
	rm -f *.o $(RELEASE_NAME)

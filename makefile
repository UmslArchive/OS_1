RELEASE_NAME=dt

ALL: main.o
	gcc -o $(RELEASE_NAME) main.c

.PHONY: clean

clean:
	rm -f *.o $(RELEASE_NAME)

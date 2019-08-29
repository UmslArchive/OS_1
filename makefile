RELEASE_NAME=dt
DEBUG_NAME=debug
ODIR=objects
INSTALL_PATH=/classes/OS/ackerman/bin

ALL: main.o
	gcc -o $(INSTALL_PATH)/$(RELEASE_NAME) main.c
	gcc -o $(RELEASE_NAME) main.c

.PHONY: clean

clean:
	rm -f ./*.o ./$(DEBUG_NAME) ./$(RELEASE_NAME)
	rm -f $(INSTALL_PATH)/$(RELEASE_NAME)

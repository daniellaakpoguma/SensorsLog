CC = gcc
CC_FLAGS =  -g -pedantic -Wall

lab4: test.o windGust.o temp.o windSpeedDirection.o lab4.h 
	$(CC) -g -o lab4 test.o windGust.o temp.o  windSpeedDirection.o $(CC_FLAGS)

test.o: test.c 
	$(CC) -c test.c  $(CC_FLAGS)

temp.o : temp.c lab4.h
	$(CC) -c  temp.c $(CC_FLAGS)

windGust.o: windGust.c lab4.h
	$(CC) -c  windGust.c $(CC_FLAGS)

windSpeedDirection.o: windSpeedDirection.c lab4.h
	$(CC) -c  windSpeedDirection.c $(CC_FLAGS)


	
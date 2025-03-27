CC := gcc
CFLAGS := -Wall -Wextra -Werror

football.exe: football_main.o football.o
	$(CC) $(CFLAGS) -o football.exe football_main.o football.o

football_main.o: football_main.c football.h
	$(CC) $(CFLAGS) -c football_main.c -o football_main.o

football.o: football.c football.h
	$(CC) $(CFLAGS) -c football.c -o football.o

temperature.exe: temperature_main.o temperature.o
	$(CC) $(CFLAGS) -o temperature.exe temperature_main.o temperature.o

temperature_main.o: temperature_main.c temperature.h
	$(CC) $(CFLAGS) -c temperature_main.c -o temperature_main.o

temperature.o: temperature.c temperature.h
	$(CC) $(CFLAGS) -c temperature.c -o temperature.o

clean:
	rm -f *.o football.exe temperature.exe
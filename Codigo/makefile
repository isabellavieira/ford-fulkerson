CC     = gcc
CFLAGS = -g
OBJS = oplista.o opgrafo.o entradaSaida.o fordfulkerson.o bellmannFord.o tp1.o 
TARGET = tp1

all: $(TARGET)

tp1: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o tp1
	
tp1.o: tp1.c opgrafo.c opgrafo.h fordfulkerson.c fordfulkerson.h bellmannFord.h entradaSaida.h
		$(CC) $(CFLAGS) -c tp1.c

fordfulkerson.o: fordfulkerson.c fordfulkerson.h opgrafo.c opgrafo.h oplista.c oplista.h
	$(CC) $(CFLAGS)  -c fordfulkerson.c		
	
bellmannFord.o: bellmannFord.c bellmannFord.h opgrafo.c opgrafo.h
	$(CC) $(CFLAGS)  -c bellmannFord.c		

entradaSaida.o: entradaSaida.c entradaSaida.h opgrafo.c opgrafo.h
	$(CC) $(CFLAGS)  -c entradaSaida.c	

opgrafo.o: opgrafo.c opgrafo.h oplista.c oplista.h
	$(CC) $(CFLAGS)  -c opgrafo.c	

oplista.o: oplista.c oplista.h
	$(CC) $(CFLAGS)  -c oplista.c	

clean: 
	rm -rf *.o ./$(TARGET)
	
run: 
	./tp1

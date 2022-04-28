all: text_processing

text_processing: main.o functions.o
	gcc -g $^ -Wall -pedantic -fsanitize=undefined -o $@

.c.o: 
	gcc -g -Wall -fsanitize=undefined -pedantic -c $<

main.o: main.c functions.h

functions.o: functions.h functions.c

clean:
	-rm main.o functions.o text_processing
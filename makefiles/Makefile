weather.so: weather.c weather.h
	gcc -std=c11 -Wall -Wextra -c weather.c -o weather.so

program: program.c weather.so
	gcc -std=c11 -Wall -Wextra  weather.so program.c -o program

launch: program
	./program

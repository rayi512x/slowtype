#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
	FILE* textfile;
	int character;
	long int delay_ms;
	char* delay_ms_endptr;
	
	if (argc != 3) {
		printf("Usage: %s <filename> <delay_ms>\n", argv[0]);
		return 1;
	}

	delay_ms = strtol(argv[2], &delay_ms_endptr, 10);
	if (*delay_ms_endptr != '\0') {
		printf("Invalid duration: %s\n", argv[2]);
		return 1;
	}

	textfile = fopen(argv[1], "r");
	if (!textfile) {
		perror(argv[1]);
		return 1;
	}

	while ((character = fgetc(textfile)) != EOF) {
		putchar(character);
		fflush(stdout);
		usleep(delay_ms * 1000);
	}

	fclose(textfile);
	return 0;
}

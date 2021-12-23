#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

/*
AK Lab 3
Onyshchuk Yurii IV-91
*/

int main(int argc, char* argv[]) {

	const char* short_options = "hvs::f:";

	const struct option long_options[] = {
		{"all", no_argument, NULL, 'a'},
		{"echo",optional_argument,NULL,'e'},
		{"help",no_argument,NULL,'h'},
		{"version",no_argument,NULL,'v'},
		{NULL,0,NULL,0}
	};

	int check_a = 1;
	int check_e = 1;
	int check_h = 1;
	int check_v = 1;
	int option_index;
	int rez;

	opterr = 0;
	while ((rez = getopt_long(argc, argv, short_options,
		long_options, &option_index)) != -1) {

		switch (rez) {
		case 'a': {
			if (check_a > 0) {
				printf("Parameters list:\n-a or --all\n-e or --echo\n-h or --help\n-v or --version\n-s or --save\n");
			}
			check_a--;
			break;
		};
		case 'e': {
			if (check_e > 0) {
				if (optarg != NULL)
					printf("Echoed: %s\n", optarg);
				else
					printf("Something went wrong with echo :(\n");
			}
			check_e--;
			break;
		};
		case 'h': {
			if (check_h > 0) {
				printf("Supported commands are: \n-a or --all\n-e or --echo\n-h or --help\n-v or --version\n-s or --save\n");
			}
			check_h--;
			break;
		};
		case 'v': {
			if (check_v > 0) {
				printf("Current version = 1.0.0.\nTry -v or --version.\n\n");
			}
			check_v--;
			break;
		};
		case '?': default: {
			printf("Error.\nError code: 404.\nYou`ve used unknown option or didn`t clarify value for the existing one.\n\n");
			break;
		};
		};
	};
	return 0;
};
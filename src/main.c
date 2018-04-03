#include <stdio.h>
#include <string.h>

#define VERSION_MAJOR 0
#define VERSION_MINOR 0

int main(int argc, char* argv[]) {
	if(argc == 1) {
		printf("Usage: CML [-h | --help] [-v | --version] <input file>\n");
		return (0);
	}
	//Then parse the args.
	int i = 0;
	for (i = 1; i < argc; i ++) {
		if((*argv[i]) == '-') {
			//Parse it
			if((strcmp(argv[i], "-h") == 0 ) | (strcmp(argv[i], "--help") == 0)) {
				puts("Usage : CML [-h | --help] [-v | --version] <input file>\n");
				puts("Option description: ");
				puts("\t-h or --help    - Shows this help menu");
				puts("\t-v or --version - Shows the version");
			}
			else if((strcmp(argv[i], "-v") == 0) | (strcmp(argv[i], "--version") == 0)) {
				printf("Version: %d.%d\n", VERSION_MAJOR, VERSION_MINOR);
				printf("Compiled: %s, %s\n", __DATE__, __TIME__);
			}
		}
		else {
			break;
		}
	}
	FILE* fp;
	if(i + 1 > argc) {
		fprintf(stderr, "No input files!\n");
		return (0);
	}

	if ((fp = fopen(argv[argc-1], "rb")) == NULL) {
		fprintf(stderr, "Something went wrong...\n");
		perror("OOPS");
		return (0);
	}
	//Read
	char c[10];
	while(!feof(fp)) {
		fread(c, 9, sizeof(char), fp);
		printf("%s", c);
	}
	return (0);
}

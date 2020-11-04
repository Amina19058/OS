#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_exists(char * name) {
    return access(name, F_OK) != -1;
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("Wrong number of arguments");
        exit(1);
    }

    bool appendMode = false;
    if ((argc == 3) && (strcmp(argv[1], "-a") == 0)) {
        appendMode = true;
    }
    int index = argc - 1;
    char * nfile = argv[index];
    if (is_exists(nfile) == false) {
        appendMode = false;
    }
    FILE * out;
    if (appendMode == true) {
        out = fopen(nfile, "a");
    } else {
        out = fopen(nfile, "w+");
    }

    int c = fgetc(stdin);
    while (c != EOF) {
        fputc(c, out);
        c = fgetc(stdin);
    }
}

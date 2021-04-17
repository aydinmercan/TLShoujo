#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tlshoujo.h>

#include "cpu.h"
#include "help.h"

typedef int (*subcommand_main)(int argc, char ** argv);

struct subcommand {
    char * name;
    subcommand_main func;
};

static const struct subcommand _cmd[] = {
    {(char *) "cpu", command_cpu},
    {(char *) "help", command_help},
    {NULL, NULL},
};

int main(int argc, char ** argv) {
    size_t i, name_len;

    if (shoujo_init() == 0) {
        fprintf(stderr, "[ CRIT ] Library initializtion failed\n");
        abort();
    }

    if (argc < 2) {
        return command_help(0, NULL);
    }

    // Bikeshed this later if you want
    for (i = 0; i < 2; i++) {
        name_len = strlen(_cmd[i].name);
        if (strncmp(argv[1], _cmd[i].name, name_len) == 0) {
            return (*_cmd[i].func)(argc, argv);
        }
    }

    return 0;
}

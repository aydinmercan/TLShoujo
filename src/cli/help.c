#include "help.h"

#include <stdio.h>

int command_help(int argc, char **argv)
{
	printf("TLShoujo CLI Utility\n"
	       "Usage: shoujo <SUBCOMMAND> [<OPTION>]...\n"
	       "Subcommands:\n"
	       "  cpu - display cpu settings that the library recognizes\n"
	       "  help COMMAND - display help for a command, no argument for this screen\n");

	return 0;
}

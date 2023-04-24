#include "shell.h"

#include <stdio.h>
#include <string.h>

int main(int ac, char**av, char **env)
{
	struct stat status;

	int on = 1;
	char *str = NULL;
	size_t len;

	(void)ac;
	(void)av;
	(void)env;
		printf("$ ");
		getline(&str, &len, stdin);
		if (stat((const char *) strtok(str, "\n\0"), &status) == 0)
			printf("exists\n");
		if (strcmp(str, "exit\n") == 0)
		{
			on = 0;
		}
		printf("%s", str);
		(void)on;
	return (0);
}

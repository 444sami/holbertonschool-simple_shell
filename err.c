#include "shell.h"

/**
 * err_han- handles errors
 * @s1: shell name
 * @s2: command
 * Return: void
 */
void err_han(char *s1, char *s2)
{
	(void)s2;
	fprintf(stderr, "%s: No such file or directory\n", s1);
}

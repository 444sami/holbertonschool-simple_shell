#ifndef SHELL_H
#define SHELL_H

/*---->    Included Libraries    <----*/
#include <sys/wait.h>

#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*---->    Structures    <----*/

/**
 * struct word_list- a list of words
 * @word: the word
 * @len: words length
 * @next: next word
 */
typedef struct word_list
{
	char *word;
	int len;
	struct word_list *next;
} wl_t;


/*---->     Prototypes     <----*/

/* _simple_shell.c */
int main(int ac, char **av, char **envron);

/* aux_func.c */
char **cmd_to_arg(void);
char **free_cmds(char **cmds);

/* err.c */
void err_han(char *s1, char *s2);

/* built_in.c */

/* low.c */
wl_t *create_list(char *str);
void *free_list(wl_t *l, int flag);
int words_counter(wl_t *l);
void print_list(wl_t *l);

#endif

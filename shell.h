#ifndef MAIN_H
#define MAIN_H

/* libraries */
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

/* structures */

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


/* Prototypes */

/* _simple_shell.c */
int main(int ac, char **av, char **env);
void interactive_mode(int mode, int ac, char **av, char **env);

/* aux_func.c */
char **cmd_to_arg(void);

/* wl_man.c */
wl_t *create_list(char *str);
void *free_list(wl_t *l, int flag);
int words_counter(wl_t *l);
void print_list(wl_t *l);

#endif

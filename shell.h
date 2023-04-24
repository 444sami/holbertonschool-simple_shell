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

/* wl_man.c */
wl_t *create_list(char *str);
void *free_list(wl_t *l, int flag);
int words_counter(wl_t *l);
void print_list(wl_t *l);

#endif

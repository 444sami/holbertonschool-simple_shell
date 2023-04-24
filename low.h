#ifndef LOW_H
#define LOW_H

#include "libaries.h"

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

/* prototypes */
wl_t *create_list(char *str);
void *free_list(wl_t *l, int flag);
int words_counter(wl_t *l);
void print_list(wl_t *l);

#endif

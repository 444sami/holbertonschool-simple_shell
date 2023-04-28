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
        struct word_list *next;
} l_node;


/*---->     Prototypes     <----*/

/* cmds.c */
l_node *cmds_inter();
char **args_arr(l_node *l);
void free_args(char **args);
void print_args(char **args);

/* list_commands.c */
l_node *command_str(char *buf);
l_node *args_str(char *buf);
void add_end(l_node *l, l_node *a);

/* list_aux.c */
void *free_list(l_node *l, int flag);
int node_count(l_node *l);
void print_list(l_node *l);

#endif

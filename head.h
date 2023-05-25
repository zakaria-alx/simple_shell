#ifndef _HOLBERTON_
#define _HOLBERTON_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TKN_BUFFSIZE 128
#define TKN_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @vector: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **vector;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} shell_data;

/**
 * struct seperator_node - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct seperator_node
{
	char separator;
	struct seperator_node *next;
} seperator_list;

/**
 * struct command_node - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct command_node
{
	char *line;
	struct command_node *next;
} command_list;

/**
 * struct variable_node - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct variable_node
{
	int len_var;
	char *val;
	int len_val;
	struct variable_node *next;
} variable_list;

/**
 * struct shell_builtin_node - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct shell_builtin_node
{
	char *name;
	int (*f)(shell_data *shdata);
} shell_builtin_list;

/* lists.c */
seperator_list *add_sep_node_end(seperator_list **head, char sep);
void free_sep_list(seperator_list **head);
command_list *add_cmd_node_end(command_list **head, char *line);
void free_cmd_list(command_list **head);

/* lists2.c */
variable_list *add_var_node(variable_list **head, int varLength, char *var, int valLength);
void free_var_list(variable_list **head);

/* str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdptr(char **ptr, unsigned int old_size, unsigned int new_size);

/* str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* str3.c */
void _strrev(char *s);

/* check_syntax_error.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(shell_data *shdata, char *input, int i, int bool);
int check_syntax_error(shell_data *shdata, char *input);

/* shell_loop.c */
char *without_comment(char *in);
void shell_loop(shell_data *shdata);

/* readline.c */
char *readline(int *i_eof);

/* split.c */
char *swap_char(char *input, int bool);
void add_nodes(seperator_list **head_s, command_list **head_l, char *input);
void get_next_command(seperator_list **list_s, command_list **list_l, shell_data *shdata);
int split_commands(shell_data *shdata, char *input);
char **split_line(char *input);

/* replace_var.c */
void check_env(variable_list **h, char *in, shell_data *data);
int check_vars(variable_list **h, char *in, char *st, shell_data *data);
char *replaced_input(variable_list **head, char *input, char *new_input, int nlen);
char *replace_var(char *input, shell_data *shdata);

/* get_line.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int exec_line(shell_data *shdata);

/* exec_cmd.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(shell_data *shdata);
int check_cmd_error(char *dir, shell_data *shdata);
int exec_cmd(shell_data *shdata);

/* env1.c */
char *_getenv(const char *name, char **_environ);
int _env(shell_data *shdata);

/* env2.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, shell_data *shdata);
int _setenv(shell_data *shdata);
int _unsetenv(shell_data *shdata);

/* cd.c */
void handle_dot(shell_data *shdata);
void handle_to_path(shell_data *shdata);
void handle_cd_back(shell_data *shdata);
void handle_cd_home(shell_data *shdata);

/* shell_cd.c */
int shell_cd(shell_data *shdata);

/* get_builtin */
int (*get_builtin(char *cmd))(shell_data *shdata);

/* _exit.c */
int exit_shell(shell_data *shdata);

/* stdlib.c */
int get_len(int n);
char *_itoa(int n);
int _atoi(char *s);

/* error1.c */
char *strcat_cd(shell_data *, char *, char *, char *);
char *error_get_cd(shell_data *shdata);
char *error_not_found(shell_data *shdata);
char *error_exit_shell(shell_data *shdata);

/* error2.c */
char *error_get_alias(char **args);
char *error_env(shell_data *shdata);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(shell_data *shdata);

/* get_error.c */
int get_error(shell_data *shdata, int eval);

/* get_sigint.c */
void get_sigint(int sig);

/* help.c */
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_general(void);
void help_exit(void);

/* help2.c */
void help(void);
void help_alias(void);
void help_cd(void);

/* get_help.c */
int get_help(shell_data *shdata);

#endif

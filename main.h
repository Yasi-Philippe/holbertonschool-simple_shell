#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void fork_shell(char *args[], char **env);
char **arr_strtok(char *str, char *separator);
size_t strtok_arr_len(char *str);
void free_args(char **args);
char **find_path(char *args[], char **env);
void exit_shell(char **args, char **commands);
void ev_exec_cmd(char **commands, char **env);
void print_env(char **env);

#endif

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void prompt_display(void);
void drew_print(const char *info);
void read_command(char *command, size_t size);
void exec_command(const char *command);

#endif

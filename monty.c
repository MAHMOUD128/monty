#include "monty.h"

char *lineptr = NULL;

/**
 * read_file - reads a file and prints it to the POSIX standard output
 * @filename: a pointer to the name of the file
 * @stack: head of linked list
 */

void read_file(char *filename, stack_t **stack)
{
	FILE *fp;
	char *opcode;
	size_t n = 0, line_number = 1;
	instruction_t operation[] = {
		{"push", _push}, {"pall", pall}, {"pint", pint}, {"pop", _pop},
		{"swap", swap},	{"add", add}, {"sub", sub}, {"div", _div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}
	};
	int i, operationsLen = sizeof(operation) / sizeof(instruction_t);

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&lineptr, &n, fp) != -1)
	{
		opcode = strtok(lineptr, " \n");
		if (opcode != NULL && strcmp(opcode, "nop") && opcode[0] != '#')
		{
			for (i = 0; i < operationsLen; i++)
				if (!strcmp(opcode, operation[i].opcode))
				{
					operation[i].f(stack, line_number);
					break;
				}
			if (i == operationsLen)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n", line_number, opcode);
				free(lineptr), free_stack(*stack);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	free(lineptr), fclose(fp);
}

/**
 * main - run monty interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &stack);
	free_stack(stack);

	return (EXIT_SUCCESS);
}

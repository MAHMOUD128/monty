#include "monty.h"

/**
 * isInteger - checks if string is integer
 * @str: pointer to string
 *
 * Return: 1 is true, 0 if not
 */
char isInteger(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-')
			continue;
		else if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * _push - add int to the top of the stack
 * @head: head of linked list
 * @line_number: number of interpreted line
 */

void _push(stack_t **head, unsigned int line_number)
{
	int n;
	char *secArg;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	secArg = strtok(NULL, " \n");
	if (!secArg || !isInteger(secArg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(secArg);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}

/**
 * _pop - removes the top element of the stack
 * @head: head of linked list
 * @line_number: number of interpreted line
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	*head = tmp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 * @head: A pointer to the head of the dlistint_t.
 * @line_number: number of interpreted line
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int swap_tmp;

	if (!tmp || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	swap_tmp = tmp->n ^ tmp->next->n;
	tmp->n = tmp->n ^ swap_tmp;
	tmp->next->n = tmp->next->n ^ swap_tmp;
}

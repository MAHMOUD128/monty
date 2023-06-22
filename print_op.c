#include "monty.h"

/**
 * pall - print all nodes
 * @head: head of linked list
 * @line_number: number of interpreted line
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	(void) line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print top value
 * @head: head of linked list
 * @line_number: number of interpreted line
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @head: A pointer to the head of the dlistint_t
 * @line_number: number of interpreted line
 */
void pchar(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	putchar(tmp->n);
	putchar('\n');
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: A pointer to the head of the dlistint_t
 * @line_number: number of interpreted line
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	(void) line_number;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
		{
			break;
		}
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}

#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: A pointer to the head of the dlistint_t.
 * @line_number: number of interpreted line
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp->next->n += tmp->n;
	_pop(head, line_number);
}

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @head: A pointer to the head of the dlistint_t
 * @line_number: number of interpreted line
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp->next->n -= tmp->n;
	_pop(head, line_number);
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack.
 * @head: A pointer to the head of the dlistint_t
 * @line_number: number of interpreted line
 */
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp->next->n /= tmp->n;
	_pop(head, line_number);
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @head: A pointer to the head of the dlistint_t.
 * @line_number: number of interpreted line
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp->next->n *= tmp->n;
	_pop(head, line_number);
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: A pointer to the head of the dlistint_t
 * @line_number: number of interpreted line
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp->next->n %= tmp->n;
	_pop(head, line_number);
}


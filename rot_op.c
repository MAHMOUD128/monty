#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @head: A pointer to the head of the dlistint_t
 * @line_number: number of interpreted line
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *last;

	if (*head == NULL || (*head)->next == NULL)
		return;
	(void) line_number;
	last = *head, temp = *head;

	while (last->next != NULL)
		last = last->next;

	*head = temp->next;
	(*head)->prev = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @head: A pointer to the head of the dlistint_t
 * @line_number: number of interpreted line
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp, *last;

	if (*head == NULL || (*head)->next == NULL)
		return;
	(void) line_number;
	last = *head, tmp = *head;
	while (last->next != NULL)
		last = last->next;

	tmp->prev = last;
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
}


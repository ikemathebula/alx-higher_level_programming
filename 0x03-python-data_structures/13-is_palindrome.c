#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head)
{
	// Check for empty list or single-node list
	if (*head == NULL || (*head)->next == NULL)
		return 1;

	// Find the middle of the list
	listint_t *slow = *head, *fast = *head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	// Reverse the second half of the list
	listint_t *prev = NULL, *curr = slow, *next = slow->next;
	while (next)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}
	curr->next = prev;

	// Compare the first and second halves of the list
	listint_t *left = *head, *right = curr;
	while (right)
	{
		if (left->n != right->n)
			return 0;
		left = left->next;
		right = right->next;
	}

	// Restore the original list
	prev = NULL;
	curr = slow;
	next = slow->next;
	while (next)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}
	curr->next = prev;

	return 1;
}

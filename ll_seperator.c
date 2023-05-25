#include "head.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a seperator_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
seperator_list *add_sep_node_end(seperator_list **head, char sep)
{
	seperator_list *new, *temp;

	new = malloc(sizeof(seperator_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - frees a seperator_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(seperator_list **head)
{
	seperator_list *temp;
	seperator_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

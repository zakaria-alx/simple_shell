#include "head.h"

/**
 * add_cmd_node_end - adds a command line at the end
 * of a command_list.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
command_list *add_cmd_node_end(command_list **head, char *line)
{
	command_list *new, *temp;

	new = malloc(sizeof(command_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * free_cmd_list - frees a command_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_cmd_list(command_list **head)
{
	command_list *temp;
	command_list *curr;

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

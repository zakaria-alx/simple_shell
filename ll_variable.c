#include "head.h"

/**
 * add_var_node - adds a variable at the end
 * of a variable_list list.
 * @head: head of the linked list.
 * @varLength: length of the variable.
 * @val: value of the variable.
 * @valLength: length of the value.
 * Return: address of the head.
 */
variable_list *add_var_node(variable_list **head,
							 int varLength, char *val, int valLength)
{
	variable_list *new, *temp;

	new = malloc(sizeof(variable_list));
	if (new == NULL)
		return (NULL);

	new->len_var = varLength;
	new->val = val;
	new->len_val = valLength;

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
 * free_var_list - frees a variable_list list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_var_list(variable_list **head)
{
	variable_list *temp;
	variable_list *curr;

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

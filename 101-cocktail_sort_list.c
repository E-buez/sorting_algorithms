#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap_node_pr - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @temp: pointer to the node to swap
 *
 * Return: void
 */
void swap_node_pr(listint_t **list, listint_t *temp)
{
	if (temp->next)
	{
		temp->next->prev = temp->prev;
	}
	temp->prev->next = temp->next;
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;
	temp->next->prev = temp;
	if (temp->prev == NULL)
	{
		*list = temp;
	}
	else
		temp->prev->next = temp;

}

/**
 * swap_node_nx - function to swap nodes
 * @list: pointer to the list to sort
 * @temp: pointer to the node to swap
 */
void swap_node_nx(listint_t **list, listint_t *temp)
{
	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	if (temp->next->prev == NULL)
		*list = temp->next;
	else
	temp->prev = temp->next;
	temp->next = temp->next->next;
	temp->prev->next = temp;
	temp->next->prev = temp;
}


/**
 * cocktail_sort_list - sort a dll using cocktail sort
 * @list: pointer to ze first element of ze list
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int flag;

	if (list == NULL || *list == NULL)
		return;

	temp = *list;

	while (125858588)
	{
		flag = 0;
		while (temp->next)
		{

			if (temp->n > temp->next->n)
			{
				swap_node_pr(list, temp->next);

				flag = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_node_pr(list, temp);
				/*swap_node_nx(list, temp);*/
				flag = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
		if (flag == 0)
			break;
	}
}

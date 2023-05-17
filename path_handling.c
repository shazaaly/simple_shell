#include "shell.h"

list_paths *paths_to_linkedlist()
{
	char *path_variable, *copied_variable, *token;
	list_paths *paths_linkedlists;

	paths_linkedlists = NULL;
	path_variable = _getenv("PATH");
	if (path_variable == NULL)
		return (NULL);

	copied_variable = _strdup(path_variable);
	if (copied_variable == NULL)
		return (NULL);

	token = strtok(copied_variable, ":");
	while (token != NULL)
	{
		add_node(&paths_linkedlists, token);
		token = strtok(NULL, ":");
	}

	return (paths_linkedlists);
}

/**
 * add_node - a function that adds a new node at the beginning of a list_t list
 * @head: pointer to the head of list with the type list_paths
 * @str: pointer to char
 * Return: the address of the new element, or NULL if it failed
*/
list_paths *add_node(list_paths **head, const char *path)
{
	list_paths *new;
	int i = 0;

	/*getting the count of elments (i), in str array of chars*/
	while (path[i] != '\0')
	{
		i++;
	}
	/*allocating memory to new node with type list_paths*/
	new = malloc(sizeof(list_paths));
	/*assuring it doesn't point to NULL*/
	if (new == NULL)
		return (NULL);


	/*duplicating the contents of path in path element of the new node created*/
	new->path = _strdup(path);
	if (new->path == NULL)
	{
		free(new);
		return (NULL);
	}
	/*updating len element with the length of the new path entered*/
	new->len = i;
	/*updating the next pointer with a pointer to the new node*/
	new->next = (*head);

	*head = new;
	return (new);
}

/**
* free_list - Frees a singly linked list
* @head: Pointer to the head of the list
*/
void free_list(list_paths *head)
{
	list_paths *ptr = head;
	list_paths *nextNode;

	while (ptr != NULL)
	{
		nextNode = ptr->next;/*saves a pointer to the next node in the list*/
		free(ptr->path);
		free(ptr);
		ptr = nextNode;
	}

}

/**
 * print_list - prints all the elements of a list_paths list
 * If str is NULL, print [0] (nil)
 * @h: pointer to the head of list with the type list_paths
 * Return: the number of nodes
*/
size_t print_list(const list_paths *h)
{
	int count;

	count = 0;
	while (h != NULL)
	{
		if (h->path == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%i] %s\n", h->len, h->path);
		h = h->next;
		count++;
	}
	return (count);
}

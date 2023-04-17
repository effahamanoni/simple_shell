#include "main.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to new node
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    if (!head)
        return NULL;

    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;

    new_node->str = str ? strdup(str) : NULL;
    new_node->num = num;
    new_node->next = *head;
    *head = new_node;

    return new_node;
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to new node
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    if (!head)
        return NULL;

    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;

    new_node->str = str ? strdup(str) : NULL;
    new_node->num = num;
    new_node->next = NULL;

    if (!*head)
        *head = new_node;
    else
    {
        list_t *last_node = *head;
        while (last_node->next)
            last_node = last_node->next;
        last_node->next = new_node;
    }

    return new_node;
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: number of nodes in list
 */
size_t print_list_str(const list_t *h)
{
    size_t count = 0;

    while (h)
    {
        if (h->str)
            printf("%s\n", h->str);
        else
            printf("(nil)\n");
        h = h->next;
        count++;
    }

    return count;
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    if (!head || !*head)
        return 0;

    list_t *node_to_delete = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        free(node_to_delete->str);
        free(node_to_delete);
        return 1;
    }

    list_t *prev_node = NULL;
    unsigned int i = 0;

    while (node_to_delete && i != index)
    {
        prev_node = node_to_delete;
        node_to_delete = node_to_delete->next;
        i++;
    }

    if (i == index && node_to_delete)
    {
        prev_node->next = node_to_delete->next;
        free(node_to_delete->str);
        free(node_to_delete);
        return 1;
    }

    return 0;
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
    if (!head_ptr || !*head_ptr)
        return;

    list_t *node = *head_ptr;

    while (node)
    {
        list_t *next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }
    *head_ptr = NULL;
}
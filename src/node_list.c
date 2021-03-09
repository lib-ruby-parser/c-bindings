#include <stddef.h>
#include <stdlib.h>
#include "node_list.h"
#include "node.h"

void nodes_ptr_free(struct Node *);
void node_list_free_(struct NodeList *);

void node_list_free(struct NodeList *node_list)
{
    if (node_list->len > 0)
    {
        for (uint32_t i = 0; i < node_list->len; i++)
        {
            struct Node *node = &node_list->list[i];
            inner_node_free(node->inner, node->node_type);
        }
        nodes_ptr_free(node_list->list);
    }
    node_list_free_(node_list);
}

#include <stddef.h>
#include <stdlib.h>
#include "node_list.h"
#include "node.h"

void node_list_free(struct NodeList *node_list)
{
    if (node_list->len > 0)
    {
        for (uint32_t i = 0; i < node_list->len; i++)
        {
            struct Node *node = &node_list->list[i];
            inner_node_free(node->inner, node->node_type);
        }
        free(node_list->list);
    }
    free(node_list);
}
#include <stddef.h>
#include <stdlib.h>
#include "node_list.h"
#include "node.h"
#include "rust_free.h"

void node_list_free(NodeList *node_list)
{
    if (node_list->len > 0)
    {
        for (uint32_t i = 0; i < node_list->len; i++)
        {
            Node *node = &node_list->list[i];
            inner_node_free(node->inner, node->node_type);
        }
        rust_nodes_free(node_list->list);
    }
    rust_node_list_free(node_list);
}

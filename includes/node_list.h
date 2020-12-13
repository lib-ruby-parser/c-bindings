#ifndef LIB_RUBY_PARSER_NODE_LIST_H
#define LIB_RUBY_PARSER_NODE_LIST_H

#include <stddef.h>
#include <stdlib.h>

// struct Node;
// enum NodeType;
// union InnerNode;
// void inner_node_free(union InnerNode *inner_node, enum NodeType node_type);

#include "gen.h"

struct NodeList
{
    size_t len;
    struct Node *list;
};

void node_list_free(struct NodeList *node_list)
{
    if (node_list->len > 0)
    {
        for (size_t i = 0; i < node_list->len; i++)
        {
            struct Node *node = &node_list->list[i];
            inner_node_free(node->inner, node->node_type);
        }
        free(node_list->list);
    }
    free(node_list);
}

#endif // LIB_RUBY_PARSER_NODE_LIST_H

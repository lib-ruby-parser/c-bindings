#ifndef LIB_RUBY_PARSER_NODE_LIST_H
#define LIB_RUBY_PARSER_NODE_LIST_H

#include <stddef.h>
#include <stdint.h>

typedef struct Node Node;

// A list of AST nodes
typedef struct NodeList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of nodes
    Node *list;
} NodeList;

// Destructor of the the list of nodes
void node_list_free(NodeList *node_list);

#endif // LIB_RUBY_PARSER_NODE_LIST_H

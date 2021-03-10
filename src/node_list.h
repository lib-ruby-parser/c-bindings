#ifndef LIB_RUBY_PARSER_NODE_LIST_H
#define LIB_RUBY_PARSER_NODE_LIST_H

#include <stddef.h>
#include <stdint.h>

// A list of AST nodes
struct NodeList
{
    // Length of the list
    uint32_t len;

    // Pointer to array of nodes
    struct Node *list;
};

// Destructor of the the list of nodes
void node_list_free(struct NodeList *node_list);

#endif // LIB_RUBY_PARSER_NODE_LIST_H

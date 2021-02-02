#ifndef LIB_RUBY_PARSER_NODE_LIST_H
#define LIB_RUBY_PARSER_NODE_LIST_H

#include <stddef.h>
#include <stdint.h>

struct NodeList
{
    uint32_t len;
    struct Node *list;
};

void node_list_free(struct NodeList *node_list);

#endif // LIB_RUBY_PARSER_NODE_LIST_H

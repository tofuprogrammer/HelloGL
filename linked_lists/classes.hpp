#pragma once

#include "structs.hpp"

class linked_lists
{
private:
    list_node* m_head = nullptr;
public:
    linked_lists();
    ~linked_lists();

    list_node* add_node(list_node** head, int data);
    list_node* insert_first(list_node** head, int data);
    void insert_after(list_node* last_node, int data);
    void delete_list(list_node** node);
    void delete_after(list_node* node);
    list_node* get_node(list_node* node, int position);
    list_node* find(list_node* node, int value);
    void print_list(list_node* node);
};

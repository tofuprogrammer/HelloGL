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
    void delete_list(list_node** node);
    void delete_after(list_node* node);
    list_node* find_node_by_data(list_node* node, int data);
    list_node* find_node_by_position(list_node* node, int position);
    void insert_after(list_node* last_node, int data);
    list_node* insert_first(list_node** head, int data);
    void print_list(list_node* node);
};

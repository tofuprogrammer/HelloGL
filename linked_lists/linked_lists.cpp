#include <iomanip>
#include <iostream>

#include "classes.hpp"

linked_lists::linked_lists()
= default;


list_node* linked_lists::add_node(list_node** head, int data)
{
    list_node* new_node = new list_node();
    list_node* last_node = *head;

    new_node->data = data;
    new_node->next_node = nullptr;

    if (*head == nullptr)
    {
        *head = new_node;
        return new_node;
    }

    while (last_node->next_node != nullptr)
    {
        last_node = last_node->next_node;
    }

    last_node->next_node = new_node;

    return new_node;
}

void linked_lists::delete_after(list_node* node)
{
    list_node* temporary_pointer;
    if (node != nullptr && node->next_node != nullptr)
    {
        temporary_pointer = node->next_node;
        node->next_node = temporary_pointer->next_node;
        delete temporary_pointer;
    }
}

void linked_lists::delete_list(list_node** node)
{
    list_node* temporary_pointer = *node;
    list_node* next_node;

    while (temporary_pointer != nullptr)
    {
        next_node = temporary_pointer->next_node;
        delete temporary_pointer;
        temporary_pointer = next_node;
    }
    *node = nullptr;
}

void linked_lists::insert_after(list_node* last_node, int data)
{
    list_node* new_node = new list_node();
    new_node->data = data;
    new_node->next_node = last_node->next_node;
    last_node->next_node = new_node;
}

list_node* linked_lists::insert_first(list_node** head, int data)
{
    list_node* new_node = new list_node();
    new_node->data = data;
    new_node->next_node = *head;
    *head = new_node;

    return new_node;
}

void linked_lists::print_list(list_node* node)
{
    while (node != nullptr)
    {
        std::cout << "| " << node->data << " |-->";
        node = node->next_node;
    }

    if (node == nullptr)
    {
        std::cout << "| NULL |\n";
    }
}

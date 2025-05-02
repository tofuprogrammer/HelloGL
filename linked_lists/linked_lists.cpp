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

void linked_lists::print_list(list_node* node)
{
    while (node != nullptr)
    {
        std::cout << std::setw(5) << "| " << node->data << " |-->";
        node = node->next_node;
    }

    if (node == nullptr)
    {
        std::cout << "| NULL |\n";
    }
}

#include <iostream>

#include "classes.hpp"

int main()
{
    linked_lists* lists = new linked_lists();
    list_node* head = nullptr;

    lists->add_node(&head, 1);
    // Appends a node with data set to 1.
    lists->add_node(&head, 2);
    // Appends a node with data set to 2.
    lists->add_node(&head, 3);
    // Appends a node with data set to 3.
    lists->print_list(head);
    // Outputs the list
    lists->insert_after(head, 4);
    // Inserts a node after the head node with data set to 4.
    lists->print_list(head);
    // Outputs the list.
    lists->insert_after(head->next_node, 5);
    // Inserts a node after the second node with data set to 5.
    lists->find_node_by_position(head, 1);
    // Finds the node at position 1 and outputs its data.
    lists->insert_first(&head, 0);
    // Inserts a node at the beginning of the list with data set to 0.
    lists->print_list(head);
    // Outputs the list.
    lists->find_node_by_position(head, 6);
    // Finds the node at position 6 and outputs its data.
    lists->print_list(head);
    // Outputs the list.
    lists->find_node_by_data(head, 4);
    lists->delete_after(head->next_node);
    // Deletes the node after the second node.
    std::cout << "Third node deleted\n";
    lists->print_list(head);
    // Outputs the list.
    lists->find_node_by_data(head, 7);
    lists->delete_list(&head);
    // Deletes the entire list.
    std::cout << "List deleted\n";
    lists->print_list(head);
    // Outputs the list.
}

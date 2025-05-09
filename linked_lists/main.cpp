#include <iostream>

#include "classes.hpp"

int main()
{
    linked_lists* lists = new linked_lists();
    list_node* head = nullptr;

    // Testing `add_node` function.
    lists->add_node(&head, 1); // Appends a node with data set to 1.
    lists->add_node(&head, 2); // Appends a node with data set to 2.
    lists->add_node(&head, 3); // Appends a node with data set to 3.
    lists->add_node(&head, 4); // Appends a node with data set to 4.
    lists->add_node(&head, 5); // Appends a node with data set to 5.

    lists->print_list(head); // Outputs the list.

    // Testing `delete_after` function.
    lists->delete_after(head); // Deletes the node after the head node.

    lists->print_list(head); // Outputs the list.

    // Testing `delete_node_at_position` function.
    lists->delete_node_at_position(head, 0); // Deletes the node at position 2.

    lists->print_list(head); // Outputs the list.
}

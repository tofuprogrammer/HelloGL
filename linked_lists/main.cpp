#include <iostream>

#include "classes.hpp"

int main()
{
    linked_lists* lists = new linked_lists();
    list_node* head = nullptr;

    lists->add_node(&head, 1);
    lists->add_node(&head, 2);
    lists->add_node(&head, 3);
    lists->print_list(head);
    lists->insert_after(head, 4);
    lists->print_list(head);
    lists->insert_after(head->next_node, 5);
    lists->get_node(head, 1);
    lists->insert_first(&head, 0);
    lists->print_list(head);
    lists->get_node(head, 6);
    lists->print_list(head);
    lists->delete_after(head->next_node);
    std::cout << "Final node deleted\n";
    lists->print_list(head);
    lists->delete_list(&head);
    std::cout << "List deleted\n";
    lists->print_list(head);
}

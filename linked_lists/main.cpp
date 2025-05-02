#include "classes.hpp"

int main()
{
    linked_lists* lists = new linked_lists();
    list_node* head = nullptr;

    lists->add_node(&head, 1);
    lists->add_node(&head, 2);
    lists->add_node(&head, 3);
    lists->print_list(head);
}

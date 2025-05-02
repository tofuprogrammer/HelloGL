#include "classes.hpp"

int main()
{
    linked_lists* lists = new linked_lists();
    list_node* head = nullptr;

    lists->add_node(&head, 1);
    lists->print_list(head);
}

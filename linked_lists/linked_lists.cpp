#include <iomanip>
#include <iostream>

#include "classes.hpp"

linked_lists::linked_lists() = default;

/**
 * Adds a new node to the end of a linked list.
 *
 * @param head A pointer to the pointer of the list's head node.
 *             If the list is empty, the new node will become the head.
 * @param data An integer value to be assigned to the new node's data field.
 * @return A pointer to the newly added node.
 */
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

/**
 * Deletes the node after a given node.
 *
 * @param node A pointer to a given node in the list.
 *             The node after this will be deleted.
 */
void linked_lists::delete_after(list_node* node)
{
    if (node != nullptr && node->next_node != nullptr)
    {
        list_node* temporary_pointer = node->next_node;
        node->next_node = temporary_pointer->next_node;
        delete temporary_pointer;
    }
    else if (node != nullptr && node->next_node == nullptr)
    {
        std::cerr << "The given node is the last node in the list\n";
    }
    else if (node == nullptr)
    {
        std::cerr << "The given node is invalid\n";
    }
}

/**
 * Steps through the list, deleting every node.
 *
 * @param node A pointer to the pointer to the head node.
 */
void linked_lists::delete_list(list_node** node)
{
    if (node == nullptr || *node == nullptr)
    // Check if node or *node is nullptr
    {
        return; // Exit early if node is invalid
    }

    list_node* temporary_pointer = *node;
    list_node* next_node = temporary_pointer->next_node;
    delete temporary_pointer;
    *node = next_node;
    delete_list(node); // Recursive call
    *node = nullptr; // Ensure the pointer is set to nullptr after deletion
}

/**
 * Deletes a node at the specified position in the linked list.
 *
 * @param head A pointer to the head node of the list.
 * @param position The index of the node to be deleted.
 *                 If the position is invalid, an error message is output.
 */
void linked_lists::delete_node_at_position(list_node* &head, int position)
{
    if (head == nullptr) // Check if the list is empty.
    {
        std::cerr << "List is empty. Cannot delete node at position " << position << ".\n";
        return;
    }

    if (position == 0) // Special case for deleting the head.
    {
        list_node* temp = head;
        head = head->next_node; // Move the head pointer to the next node.
        delete temp; // Delete the old head.
        std::cout << "Node at position 0 deleted\n";
        return;
    }

    list_node* current = head;
    list_node* prev = nullptr;
    int counter = 0;

    while (current != nullptr && counter < position)
    {
        prev = current;           // Keep track of the previous node.
        current = current->next_node; // Move to the next node.
        counter++;
    }

    if (current == nullptr) // If position is out of bounds.
    {
        std::cerr << "Position " << position << " is invalid. No node deleted.\n";
        return;
    }

    // Delete the node at the desired position.
    prev->next_node = current->next_node; // Update the previous node's next.
    delete current; // Delete the current node.
    std::cout << "Node at position " << position << " deleted\n";
}

/**
 * Searches for a node with the given data.
 *
 * @param node A pointer to the given node in the list.
 * @param data A given data value to search for in the list.
 * @return A pointer to the node(s) with the given data.
 */
list_node* linked_lists::find_node_by_data(list_node* node, int data)
{
    if (node == nullptr)
    {
        std::cout << "Data " << data << " not found in the linked list\n";
        return nullptr;
    }

    if (node->data == data)
    {
        return node;
    }

    return find_node_by_data(node->next_node, data);
}

/**
 * Searches the list for a node at a given position.
 *
 * @param node A pointer to the given node in the list.
 * @param position The index of a node to search for.
 * @return A pointer to the node at the given position.
 */
list_node* linked_lists::find_node_by_position(list_node* node, int position)
{
    if (node == nullptr)
    {
        std::cout << "Position " << position << " is invalid\n";
        return nullptr;
    }

    if (position < 0)
    {
        std::cout << "Invalid position - position must be positive\n";
        return nullptr;
    }

    if (position == 0)
    {
        std::cout << "Data found at position 0 is " << node->data << '\n';
        return node;
    }

    return find_node_by_position(node->next_node, position - 1);
}

/**
 * Inserts a new node after a given node.
 *
 * @param node A pointer to a given node in the list.
 * @param data A given data value to insert.
 *             The data is inserted at the added node.
 */
void linked_lists::insert_after(list_node* node, int data)
{
    list_node* new_node = new list_node();
    new_node->data = data;
    new_node->next_node = node->next_node;
    node->next_node = new_node;
}

/**
 * Inserts a new node at the head of the list.
 *
 * @param head A pointer to the pointer to the head node of the list.
 * @param data The data to be inserted with the node
 * @return A pointer to the new node to be created
 */
list_node* linked_lists::insert_first(list_node** head, int data)
{
    list_node* new_node = new list_node();

    new_node->data = data;

    new_node->next_node = *head;
    *head = new_node;
    return new_node;
}

/**
 * Outputs the entire list to the console.
 *
 * @param node A pointer to a given node.
 */
void linked_lists::print_list(list_node* node)
{
    if (node == nullptr)
    {
        std::cout << "| NULL |\n";
    }
    else
    {
        std::cout << "| " << node->data << " |-->";
        print_list(node->next_node);
    }
}

/**
 * Outputs the list in reverse order.
 *
 * @param node A pointer to a given node.
 */
void linked_lists::print_list_reversed(list_node* node)
{
    if (node != nullptr)
    {
        print_list_reversed(node->next_node);
        std::cout << "| " << node->data << " |-->";
    }
}

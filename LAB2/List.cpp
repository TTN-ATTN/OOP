#include "List.h"
#include <iostream>

/**
 * Default constructor for List class.
 * Initializes head to nullptr.
 */
List::List() : head(nullptr) {}

/**
 * Destructor for List class.
 * Deletes all nodes in the list to free memory.
 */
List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

/**
 * Adds a new node with the given value to the end of the list.
 * @param x - The value to add.
 */
void List::add(double x) {
    Node* newNode = new Node(x);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/**
 * Removes the first node with the given value from the list.
 * @param x - The value to remove.
 */
void List::removeFirst(double x) {
    if (head == nullptr) return;

    if (head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != x) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

/**
 * Removes all nodes with the given value from the list.
 * @param x - The value to remove.
 */
void List::removeAll(double x) {
    while (head != nullptr && head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == x) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

/**
 * Replaces the value at the given index with a new value.
 * @param index - The index of the node to replace.
 * @param y - The new value.
 */
void List::replace(int index, double y) {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (count == index) {
            current->data = y;
            return;
        }
        current = current->next;
        count++;
    }
}

/**
 * Prints the values of all nodes in the list.
 */
void List::print() const {
    Node* current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << ",";
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}
/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
/* Add a prototype for a helper function here if you need */
void insertion(Node*& list, int value);

void split(Node*& in, Node*& odds, Node*& evens)
{
    /* Add code here */
// WRITE YOUR CODE HERE
    if(in == nullptr) {
        return;
    }
    if(in->value % 2 == 0){
        insertion(evens, in->value);
    }else{
        insertion(odds, in->value);
    }
    Node* temp = in;
    in = in->next;
    temp->next = nullptr;
    delete temp;
    split(in, odds, evens);

}

/* If you needed a helper function, write it here */
void insertion(Node*& list, int value){ // insert value to the end of the linked list
    if(list == nullptr){ // if list is empty insert
        list = new Node(value, nullptr);
        return;
    }
    if(list->next == nullptr){
        list->next = new Node(value, nullptr); // if list->next is still nullptr.
        return;
    }

    insertion(list->next, value); // go to next element
}

/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
int main(int argc, char* argv[])
{
    Node* second = new Node(32, nullptr);
    Node* head = new Node(69, second);
    Node* even = nullptr;
    Node* odd = nullptr;
    split(head, odd, even);
    std::cout << odd->value;
    std::cout << even->value;
    delete even;
    delete odd;
}

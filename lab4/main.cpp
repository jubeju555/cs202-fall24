// Lab 04: Adding List-Based Integers
/*
judah benjamin
lab 4
using linked lists for sets of addition
sources:
geeks for geeks: refinement of understanding of things that will be used,
google: visual representaiton of "passing" the number form one node to the next, after watching video
geeks4geeks: what a double free error means
Ria: double checking if i had changed my double linked back to single linked
Ria: carrying the added diget as carry
Stack overflow: reverse from the algorithim library to switch the order back
*/

#include "list.h"
#include <iostream>
int main(int argc, char *argv[])
{
    string num1, num2;
    while (cin >> num1 >> num2)
    {
        LinkedList list1, list2;
        for (int i = 0; i < 1; i++)
        {
            list1.push_front(num1);
            list2.push_front(num2);
            LinkedList result = list1.add(list2);
            result.print();
        }
    }
    return 0;
}

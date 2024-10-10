#include "list.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
 * read the integers as strings
 * if using classes remember the difference between passing by reference and passing by value
 * check the stack vs queues lecture for help with the data structure
 * draw it out
 */

LinkedList::LinkedList() : head(nullptr) {}
// Deletes temp after it find the next node
LinkedList::~LinkedList()
{
  Node *current = head;
  while (current != nullptr)
  {
    Node *temp = current;
    current = current->next;
    delete temp;
  }
};
// creates a new node
Node *LinkedList::newnode(int value)
{
  return new Node(value);
}

void LinkedList::push_front(const string &num)
{
  for (char ch : num)
  {
  Node *nn = new Node(ch - '0');
  nn->next = head;
      head = nn;
  }
  
};

void LinkedList::push_back(const string &num)
{
  for ( char ch : num)
  {
Node *nn = new Node(ch - '0');
  if (empty())
  {
    head = nn;
  }
  else
  {
    Node* current = head;
   while (current->next != nullptr)
   {
      current = current->next;

   }
   current->next = nn;
  }
  }
};
// checkes if first node is null
bool LinkedList::empty() const
{
  return head == nullptr;
};
// adds node to front of list
void LinkedList::appendNode(int data)
{
  Node *nn = newnode((data));
  if (empty())
  { 
    head = nn;
  }
  else
  { 
    Node *p = head;
    while (p->next != nullptr)
    {
      p = p->next;

    } 
    p->next = nn;
  }
  
};
// add the 2 lists together
LinkedList LinkedList::add(LinkedList &list2)
{
      string s;
LinkedList result;
  Node *p1 = head;
  Node *p2 = list2.head;

  int carry = 0;
  while (p1 != nullptr || p2 != nullptr || carry != 0)
  {
    int num1 = 0;
    int num2 = 0;

    if (p1 != nullptr)
    {
      num1 = p1->data;
    }
    if (p2 != nullptr)
    {
      num2 = p2->data;
    }
    int sum = num1 + num2 + carry;
    carry = sum / 10;

    result.appendNode(sum % 10);
    if (p1 != nullptr)
    {
      p1 = p1->next;
    }
    if (p2 != nullptr)
    {
      p2 = p2->next;
    }
  }
  return result;
};
// print out result
void LinkedList::print() const
{
  Node *current = head;
    string result;
    while (current != nullptr)
    {
        result += to_string(current->data);
        current = current->next;
    }
    
    // Reverse the result since we built it backwards
   reverse(result.begin(), result.end());

   // add a 0 if there is nothing these since thats the answer
    if (result.empty()) 
    {
        cout << "0";
    }
    else 
    {
        cout << result;
    }
    cout << endl;
};

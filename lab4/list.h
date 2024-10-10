#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next, *last;
  Node(int num) : data(num), next(nullptr) {}
};
class LinkedList
{
public:
  LinkedList();
  ~LinkedList(); // deconstructor

  void push_front(const string &num);
  void push_back(const string &num);
  void print() const;
  void read_input();
  void appendNode(int data);  
  bool empty() const;
  LinkedList add(LinkedList &list2); // void was my first choice but it never fully worked out
private:
  Node *head;
  Node *newnode(int value);
};
#endif

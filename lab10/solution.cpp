// Lab 10: kth smallest numbers
// Name: judah benjamin

// Brief description:

// This code reads in a number of ints...
/*
sources:
cppreference: push heap and pop heap definitions
geeks4geeks: determining whether min or max heap
keaton: bullied me for not having a heapify function 
*/

#include <iostream>
#include <vector>
#include <algorithm>
// #include <sstream>

using namespace std;
// write a function that perculates down the tree to find the kthsmallest element
void percdown(vector<int> &heap, int n, int i)
{
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < n && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            percdown(heap, n, smallest);
        }
}

void heapify(vector<int> &heap)
{
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        percdown(heap, n, i);
    }
}
// take the heap and pop the element to the back of the heap
int heapop(vector<int> &heap)
{
    int n = heap.size();
    if (n == 0) return -1;

    int result = heap[0];
    heap[0] = heap[n - 1];
    heap.pop_back();
    percdown(heap,heap.size(), 0);
    return result;
}
// find if the heap valid or a max heap
bool maxheap(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < heap.size() && heap[left] > heap[i])
        {
            return false;
        }
        if (right < heap.size()  && heap[right] > heap[i])
        {
            return false;
        }
    }
    return true;
}
// int main
int main(int argc, char *argv[])
{
    int k, n; 
        int kth = 0;
    while (cin >> n >> k)
    {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << (maxheap(arr) ? "Y" : "N")  << "  " ;
    heapify(arr);
    for (int i = 0; i < k; i++)
    {
        kth = heapop(arr);
    }
    cout << kth << endl;
 }
    return 0;
}

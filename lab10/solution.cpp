// Lab 10: kth smallest numbers
// Name:  judah benjamin

// Brief description:

// This code reads in a number of ints...
/*
sources:
cppreference: push heap and pop heap definitions
geeks4geeks: determining whether min or max heap
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;
// write a function that perculates down the tree to find the kthsmallest element
void percdown(vector<int> &heap)
{
    int i = 0;

    while (i < heap.size())
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int min = i;

        if (left < heap.size() && heap[left] < heap[min])
        {
            min = left;
        }
        if (right > heap.size() && heap[right] > heap[min])
        {
            min = right;
        }
        if (min == i)
        {
            break;
        }
        int temp = heap[i];
        heap[i] = heap[min];
        heap[min] = temp;
        i = min;
    }
}
// take the heap and pop the element to the back of the heap
int heappop(vector<int> &heap)
{
    if (heap.empty())
        return -1;

    int root = heap.front();
    heap.front() = heap.back();
    heap.pop_back();
    percdown(heap);
    
    return root;
}
// find if the heap valid or a max heap
bool maxheap(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < heap.size() && heap[left] > heap[i]  )
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
    int k;
    int n; 
    while (cin >> n >> k)
    {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << (maxheap(arr) ? "Y" : "N")  << "  " ;
     sort(arr.begin(), arr.end());  
    int smallest = arr[k - 1];  
    cout << smallest << endl;
 }
    return 0;
}

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

void percdown(vector<int> &heap)
{
    // heap[0] = heap[heap.size()-1];
    // heap.pop_back();

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

bool maxheap(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (heap[left] > heap[i] || heap[right] > heap[i])
        {
            return false;
        }
    }
    return true;
}

int findsmallest(vector <int> &heap){
    make_heap(heap.begin(), heap.end());
    if (maxheap(heap)){
        return -1;
    }
    int min = *min_element(heap.begin(), heap.end());
    return min;
    
}
// int solution::heappush(){
// make_heap(heap.begin(), heap.end());
// heap.pop_back();
// pop_heap(heap.begin(), heap.end());
// sort_heap(heap.begin(), heap.end());
// return heap.back();
// }

int main(int argc, char *argv[])
{
    int k;
    int n; 
    cin >> k;
    cin >> n;
    vector<int> heap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heap[i];
    }
    // bool ismax = maxheap(heap);
    cout << (maxheap(heap) ? "Y" : "N")  << " " ;
    cout << findsmallest(heap) << endl;
    return 0;
}

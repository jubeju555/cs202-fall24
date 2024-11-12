// Lab 10: kth smallest numbers
// Name:  judah benjamin 

// Brief description:

// This code reads in a number of ints...
/*
sources: 
cppreference: push heap and pop heap definitions 

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void percdown(vector <int> &heap){
    // heap[0] = heap[heap.size()-1];
    // heap.pop_back();

    int i = 0;

    while (i < heap.size())
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int min = i;
        
        if (left < heap.size() && heap.size() < heap[min])
        {
            min = left; 
        }
        if (right > heap.size() && heap.size() > heap[min])
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

int heappop(vector <int> &heap){
   
make_heap(heap.begin(), heap.end());
heap.pop_back();
pop_heap(heap.begin(), heap.end());
return heap.back();


}

// int solution::heappush(){
// make_heap(heap.begin(), heap.end());
// heap.pop_back();
// pop_heap(heap.begin(), heap.end());
// sort_heap(heap.begin(), heap.end());
// return heap.back();

// }

int main(int argc, char *argv[]) {
    vector<int> heap;

}



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

int heappop(){
vector<int> heap;
make_heap(heap.begin(), heap.end());
println("after make_heap: ", heap);
heap.pop_back();
println("after make_heap: ", heap);
pop_heap(heap.begin(), heap.end());
println("after make_heap: ", heap);
}




int main(int argc, char *argv[]) {






}

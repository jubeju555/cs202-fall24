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
class solution
{
private:

public:
    vector<int> heap;
    int heappop();
    int heappush();
};

int main(int argc, char *argv[]) {



}

int solution::heappop(){
make_heap(heap.begin(), heap.end());


}

int solution::heappush(){
make_heap(heap.begin(), heap.end());
heap.pop_back();
pop_heap(heap.begin(), heap.end());
}




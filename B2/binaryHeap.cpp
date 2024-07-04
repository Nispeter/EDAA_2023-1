#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>
 
using namespace std;

class binaryHeap{
    private: 
        vector<int> heap;
    public:
        binaryHeap(vector<int> &v){
            heap = v;
            make_heap(heap.begin(), heap.end());
        }
        void heapUnion(vector<int> &sum){
            heap.insert(heap.end(), sum.begin(),sum.end());
            make_heap(heap.begin(), heap.end());
        }
        void push(int n){
            heap.push_back(n);
            push_heap(heap.begin(),heap.end());
        }
        void pop(){
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
        int top(){
            return heap[0];
        }
};

int main(int argc, char const *argv[])
{
	vector<int> v = {3,6,3,12,7,9,6,23,4,0,3,3};
    binaryHeap B(v);
    cout<<B.top()<<endl;
    B.pop();
    cout<<B.top()<<endl;
	return 0;
}
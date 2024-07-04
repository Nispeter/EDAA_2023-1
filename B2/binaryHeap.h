#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>
 
using namespace std;

class binaryHeap{
    private: 
        
    public:
        vector<int> heap;
        binaryHeap(vector<int> &v){
            for (int i = 0; i < v.size(); ++i)
            {
                heap.push_back(v[i]);
            }
            make_heap(heap.begin(), heap.end(), std::greater<>{});
        }
        void heapUnion(vector<int> &sum){
            heap.insert(heap.end(), sum.begin(),sum.end());
            make_heap(heap.begin(), heap.end(),std::greater<>{});
        }
        void push(int n){
            heap.push_back(n);
            push_heap(heap.begin(),heap.end(),std::greater<>{});
        }
        void pop(){
            pop_heap(heap.begin(), heap.end(),std::greater<>{});
            heap.pop_back();
        }
        int top(){
            return heap[0];
        }
};

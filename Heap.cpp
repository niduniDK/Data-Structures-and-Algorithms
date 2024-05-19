#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& num_heap, int index, int n){
    int left = 2*index + 1;
    int right = 2*index + 2;
    int largest = index;
    if(left<n && num_heap[index]<num_heap[left]) {
        largest = left;
    }
    if(right<n && num_heap[largest]<num_heap[right]) {
        largest = right;
    }
    if(largest!=index) {
        swap(num_heap[largest],num_heap[index]);
        heapify(num_heap,largest,n);
    }
}

void build_heap(vector<int>& num_heap){
    int n = num_heap.size();
    for(int i=n/2; i>=0; i--){
        heapify(num_heap,i,n);
    }
}

vector<int> heap_sort(vector<int>& num_heap){
    build_heap(num_heap);
    int n = num_heap.size();
    vector<int> sorted_nums(n,0);
    for(int i=n-1; i>=0; i--){
        swap(num_heap[i],num_heap[0]);
        sorted_nums[i] = num_heap[i];
        heapify(num_heap,0,i);
    }

    return sorted_nums;
}

void heap_insert(vector<int>& num_heap, int element){
    num_heap.push_back(element);
    build_heap(num_heap);
}

void heap_extract(vector<int>& num_heap, int element){
    int n = num_heap.size();
    auto it = find(num_heap.begin(),num_heap.end(),element);
    int index = it-num_heap.begin();
    swap(num_heap[index],num_heap[n-1]);
    num_heap.pop_back();
    build_heap(num_heap);
}

void heap_increase_key(vector<int>& num_heap, int step){
    int n = num_heap.size();
    for(int i=0; i<n; i++){
        num_heap[i]+=step;
    }
    build_heap(num_heap);
}

int main()
{
    vector<int> nums = {2,5,1,4,9,6,11,3};
    cout<<"Before sorting.."<<endl;
    for(int n1:nums){
        cout<<n1<<" ";
    }
    cout<<endl;

    vector<int> sorted_num = heap_sort(nums);

    cout<<"After sorting.."<<endl;
    for(int n2:sorted_num){
        cout<<n2<<" ";
    }
    cout<<'\n'<<endl;

    heap_insert(nums,19);
    heap_extract(nums,6);
    heap_increase_key(nums,2);

    for(int n3:nums){
        cout<<n3<<" ";
    }
    cout<<endl;

    return 0;
}

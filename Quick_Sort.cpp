#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int first, int last){
    int temp=first+1, curr=first+1;
    int pivot=first;
    int n = nums.size();
    while(temp<n){
        curr = temp;
        if(nums[pivot]>nums[temp]){
            while(curr>pivot){
                if((curr-pivot)==1) pivot = curr;
                swap(nums[curr],nums[curr-1]);
                curr--;
            }
        }
        temp++;
    }
    return pivot;
}

void quick_sort(vector<int>& nums, int first, int last){
    if(first<last){
        int pivot = partition(nums, first, last);
        quick_sort(nums,first,pivot);
        quick_sort(nums,pivot+1,last);
    }
}

int main()
{
    vector<int> nums = {2, 6, 5, 1, 7, 8, 3};
    int n1 = nums.size()-1;
    quick_sort(nums,0,n1);
    for(int num: nums){cout<<num<<endl;}
    return 0;
}

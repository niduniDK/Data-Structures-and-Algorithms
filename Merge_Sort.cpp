#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums, int first, int mid, int last){
    vector<int> left;
    vector<int> right;
    int n1 = mid-first+1;
    int n2 = last-mid;

    for(int i1=0; i1<n1; i1++){
        left.push_back(nums[i1+first]);
    }
    for(int j1=0; j1<n2; j1++){
        right.push_back(nums[j1+mid+1]);
    }

    int k=first, i=0, j=0;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            nums[k] = left[i];
            i++;
            k++;
        }
        else{
            nums[k] = right[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        nums[k] = left[i];
        i++;
        k++;
    }

    while(j<n2){
        nums[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& nums, int first, int last){
    if(first<last){
        int mid = (first+last)/2;
        merge_sort(nums, first, mid);
        merge_sort(nums, mid+1, last);
        merge(nums,first,mid,last);
    }
}

int main()
{
    vector<int> nums = {2, 6, 5, 1, 7, 8, 3};
    int n1 = nums.size()-1;
    merge_sort(nums,0,n1);
    for(int num: nums){cout<<num<<endl;}
    return 0;
}

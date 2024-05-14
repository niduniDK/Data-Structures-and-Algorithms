#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<n; i++){
        int j = i-1;
        int value = nums[i];
        while(j>=0 && nums[j]>value){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = value;
    }
}

int main(){
    vector<int> nums = {2, 6, 5, 1, 7, 8, 3};
    insertion_sort(nums);
    for(int num: nums){cout<<num<<endl;}
    return 0;
}

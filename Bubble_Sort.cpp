#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(nums[j]>nums[j+1]) {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> nums = {2, 6, 5, 1, 7, 8, 3};
    bubble_sort(nums);
    for(int num: nums){cout<<num<<endl;}
    return 0;
}

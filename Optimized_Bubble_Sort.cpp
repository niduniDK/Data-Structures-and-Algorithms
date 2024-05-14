#include <iostream>
#include <vector>

using namespace std;

void optimized_bubble_sort(vector<int>& nums){
    int n = nums.size();
    bool swapped;
    for(int i=0; i<n; i++){
        swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(nums[j]>nums[j+1]) {
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int main()
{
    vector<int> nums = {2, 6, 5, 1, 7, 8, 3};
    optimized_bubble_sort(nums);
    for(int num: nums){cout<<num<<endl;}
    return 0;
}

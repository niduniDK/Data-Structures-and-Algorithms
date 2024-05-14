#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selection_sort(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<n; i++){
        int min_ele = *min_element(nums.begin()+i, nums.end());
        auto it = find(nums.begin(), nums.end(), min_ele);
        int min_idx = it-nums.begin();
        swap(nums[i],nums[min_idx]);
    }
}

int main()
{
    vector<int> nums = {2, 6, 5, 1, 7, 8, 3};
    selection_sort(nums);
    for(int num: nums){cout<<num<<endl;}
    return 0;
}

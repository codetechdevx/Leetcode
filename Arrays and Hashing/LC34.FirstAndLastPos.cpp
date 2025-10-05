#include <vector>
using namespace std;

class Solution {
private:
    int binarySearchLeft(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                index = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;

        }

        return index;
    }

    int binarySearchRight(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                index = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;

        }

        return index;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearchLeft(nums, target), binarySearchRight(nums, target)};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = sol.searchRange(nums, target);
    // result should be [3, 4]
    return 0;
}

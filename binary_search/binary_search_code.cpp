#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int ans = obj.search(nums, target);

    cout << ans << endl;

    return 0;
}
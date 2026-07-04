#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        vector<int> ans;
        int result = -1, result2 = -1;

        // Last Occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                result = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Reset
        low = 0;
        high = nums.size() - 1;

        // First Occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                result2 = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        ans.push_back(result2);
        ans.push_back(result);

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> ans = obj.searchRange(nums, target);

    cout << ans[0] << endl;
    cout  << ans[1] << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int j = nums.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            j = mid;
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    return j;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int ans = searchInsert(nums, target);
    cout << ans << endl;

    return 0;
}
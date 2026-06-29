class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = ((e - s) / 2) + s;
            cout << nums[mid] << endl;
            if (nums[mid] < target) {
                s = mid + 1;
            }
            else if (nums[mid] > target) {
                e = mid - 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};

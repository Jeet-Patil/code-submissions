struct box {
    int first;
    int second;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<box> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end(), [](box a, box b) {
            return a.first < b.first;
        });

        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            if (vec[s].first + vec[e].first == target) {
                if (vec[s].second < vec[e].second)
                    return {vec[s].second, vec[e].second};
                return {vec[e].second, vec[s].second};
            }
            else if (vec[s].first + vec[e].first < target) {
                s++;
            }
            else if (vec[s].first + vec[e].first > target) {
                e--;
            }
        }

        return {0, 0};
    }
};
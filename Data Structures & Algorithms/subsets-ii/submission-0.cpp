class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        for (int num: nums) {
            int sz = res.size();
            for (int i = 0; i < sz; i++) {
                vector<int> vec = res[i];
                vec.push_back(num);
                int size1 = st.size();
                st.insert(vec);
                int size2 = st.size();
                if (size1 != size2)
                    res.push_back(vec);
            }
        }
        return res;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        int s = 0;
        int e = sz1 - 1;

        while (s <= e) {
            int mid = ((e-s) / 2) + s;
            if (matrix[mid][0] < target) {
                s = mid + 1;
            }
            else if (matrix[mid][0] > target) {
                e = mid - 1;
            }
            else {
                return true;
            }
        }

        int row = s - 1;
        if (row >= 0) {
            int s = 0;
            int e = sz2 - 1;
            while (s <= e) {
                int mid = ((e-s) / 2) + s;
                if (matrix[row][mid] < target) {
                    s = mid + 1;
                }
                else if (matrix[row][mid] > target) {
                    e = mid - 1;
                }
                else {
                    return true;
                }
            }
        }

        return false;
    }
};

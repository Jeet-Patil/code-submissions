class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int it = 0;
        while (it < size / 2) {
            for (int i = it; i < size - it - 1; i++)  {
                swap (matrix[it][i], matrix[i][size - 1 - it]);
                swap (matrix[it][i], matrix[size - 1 - it][size - 1 - i]);
                swap (matrix[it][i], matrix[size - 1 - i][it]);
            }
            it++;
        }
    }
};

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for (int i = 0; i < strs.size(); i++) {
            string curr = strs[i];
            int size = curr.size();
            string len = to_string(size);
            encoded_string = encoded_string + len + "#" + curr;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        int i = 0;
        int size = s.size();
        vector<string> ans;
        while (i < size) {

            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            string temp = s.substr(j + 1, length);

            ans.push_back(temp);
            i = j + length + 1;
        }
        return ans;
    }
};

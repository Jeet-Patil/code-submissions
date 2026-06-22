class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz1 = s1.size();
        int sz2 = s2.size();

        if (sz1 > sz2) {
            return false;
        }

        int done = 0;
        int doneF = 0;

        vector<int> check(26, 0);
        vector<int> temp(26, 0);

        for (int i = 0; i < sz1; i++) {
            check[s1[i] - 'a']++;
            if (check[s1[i] - 'a'] == 1) {
                doneF++;
            }
        }
        for (int i = 0; i < sz1; i++) {
            temp[s2[i] - 'a']++;
            if (check[s2[i] - 'a'] >= 1){
                if (check[s2[i] - 'a'] == temp[s2[i] - 'a']) {
                    done++;
                    if (done == doneF) {
                        return true;
                    }
                }
            }
            cout << done << s2[i] << endl;
        }
        for (int i = sz1; i < sz2; i++) {
            int l = i - sz1;
            temp[s2[l] - 'a']--;
            if (check[s2[l] - 'a'] >= 1 && check[s2[l] - 'a'] - 1 == temp[s2[l] - 'a']) {
                done--;
            }
            
            temp[s2[i] - 'a']++;
            if (check[s2[i] - 'a'] >= 1){
                if (check[s2[i] - 'a'] == temp[s2[i] - 'a']) {
                    done++;
                    if (done == doneF) {
                        return true;
                    }
                }
            }
            cout << done << s2[l] << s2[i] << endl;
        }
        return false;
    }
};

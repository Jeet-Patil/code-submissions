class Solution {
public:
    bool isAlphanumeric(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }
        if (ch >= 'A' && ch <= 'Z') {
            return true;
        }
        if (ch >= '0' && ch <= '9') {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            cout << s[i] << " " << s[j] << endl;
            while (!isAlphanumeric(s[i]) && i <= j) {
                i++;
            }
            while (!isAlphanumeric(s[j]) && i <= j) {
                j--;
            }
            if (i > j) {
                return true;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

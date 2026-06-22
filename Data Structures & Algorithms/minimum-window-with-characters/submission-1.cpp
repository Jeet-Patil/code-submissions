class Solution {
public:

    pair<int, int> fun (int st, int ed, unordered_map <char, int> mp, unordered_map <char, int> check, string s) {
        cout << "Start " << st << " " << ed << endl;
        if (st > ed) {
            return {0, INT_MAX};
        }
        while (check[s[st]] == 0 && st <= ed) {
            st++;
        }
        while (check[s[ed]] == 0 && st <= ed) {
            ed--;
        }
        if (st > ed) {
            return {0, INT_MAX};
        }
        if (mp[s[st]] == check[s[st]] && mp[s[ed]] == check[s[ed]]) {
            cout << st << " " << ed << " " << mp[s[st]] << " " << check[s[st]] << " " << mp[s[ed]] << " " << check[s[ed]] << endl;
            return {st, ed};
        }
        int a = 0, c = 0, b = INT_MAX, d = INT_MAX;
        if (mp[s[st]] > check[s[st]]) {
            cout << "FUN1" << " " << st << endl;
            mp[s[st]]--;
            auto one = fun(st + 1, ed, mp, check, s);
            mp[s[st]]++;
            a = one.first;
            b = one.second;
        }
        if (mp[s[ed]] > check[s[ed]]) {
            cout << "FUN2" << " " << ed << endl;
            mp[s[ed]]--;
            auto two = fun(st, ed - 1, mp, check, s);
            mp[s[ed]]++;
            c = two.first;
            d = two.second;
        }
        if (b - a < d - c) {
            cout << "Ret1 " << a << " " << b << " " << c << " " << d << endl;
            return {a, b};
        }
        else {
            cout << "Ret2 " << a << " " << b << " " << c << " " << d << endl;
            return {c, d};
        }
    }

    string minWindow(string s, string t) {
        unordered_map <char, int> mp;
        unordered_map <char, int> check;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            check[t[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (mp[t[i]] < check[t[i]]) {
                return "";
            }
        }

        int st = 0;
        int ed = s.size() - 1;

        auto[a, b] = fun(st, ed, mp, check, s);

        string ans = s.substr(a, b - a + 1);

        return ans;
    }
};

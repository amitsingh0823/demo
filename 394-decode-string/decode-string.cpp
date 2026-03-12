class Solution {
public:

    string solve(string &s, int &i, int num, string result) {

        if (i >= s.size() || s[i] == ']')
            return result;

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
            return solve(s, i, num, result);
        }

        if (s[i] == '[') {
            i++;  
            string sub = solve(s, i, 0, "");

            i++; // skip ']'

            while (num--)
                result += sub;

            return solve(s, i, 0, result);
        }

        result += s[i];
        i++;

        return solve(s, i, num, result);
    }

    string decodeString(string s) {
        int i = 0;
        return solve(s, i, 0, "");
    }
};
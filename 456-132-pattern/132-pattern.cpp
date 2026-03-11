class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int c = INT_MIN;
        stack<int> st;
        for (int i = arr.size()-1; i >= 0; i--) {
            if (arr[i] < c)
                return true;
            else {
                while (!st.empty() && arr[i] > st.top()) {
                    c = st.top();
                    st.pop();
                }
                st.push(arr[i]);
            }
        }
        return false;
    }
};
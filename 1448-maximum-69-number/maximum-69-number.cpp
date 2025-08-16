class Solution {
public:
    int maximum69Number (int num) {
        
        string s=to_string(num);
        for (auto &n:s){
            if (n=='6'){
                n='9';
                break;
            }
        }
        return stoi(s);

    }
};
class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0)return 1;

        unsigned mask= ~0;

        while(mask&num){
            mask=mask<<1;
        }
        cout<<~mask;

        return ~mask ^num;

    }
};
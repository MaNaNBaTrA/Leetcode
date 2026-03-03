class Solution {
public:

    string switchbits(string s){
        for(char& c : s){
            if(c=='1'){
                c='0';
            }else{
                c='1';
            }
        }

        return s;
    }

    char findKthBit(int n, int k) {
        string prev = "0";

        for(int i = 1 ; i < n ; i++){
            string rev = prev;
            reverse(rev.begin(),rev.end());
            string curr = prev + '1' + switchbits(rev);
            prev = curr;
        }

        return prev[k-1];
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        unordered_map<char,int>m;
        int i=0;
        int maxLen=INT_MIN;
        for(int j=0;j<s.length();j++){
            char ch=s[j];
            if(m.find(ch)!=m.end()){
                i=max(i,m[ch]+1);
            }
            m[ch]=j;
            maxLen=max(maxLen,j-i+1);
        }
        if(maxLen!=INT_MIN)
        return maxLen;
        return 1;
    }
};

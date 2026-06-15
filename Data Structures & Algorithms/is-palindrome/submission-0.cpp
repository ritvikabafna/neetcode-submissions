class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            s[i]=tolower(s[i]);
        }
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(!isalnum(static_cast<unsigned char>(s[i])) ){
                i++;
                continue;
            }
            if(!isalnum(static_cast<unsigned char>(s[j])) ){
                j--;
                continue;
            }
            if(s[i]==' '){
                i++;continue;
            }
            if(s[j]==' '){
                j--;continue;
            }
            if(s[i]!=s[j])
                return false;
            else
                i++;j--;
        }
        return true;
    }
};

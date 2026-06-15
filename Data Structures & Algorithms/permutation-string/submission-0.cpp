class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int size=s1.length();
      int size2=s2.length();
      if(size>size2)
        return false;
      unordered_map<char,int>m;
      unordered_map<char,int>m2;
      for(int i=0;i<size;i++){
        m[s1[i]]++;
      }
    int i=0;
      for(int j=0;j<size2;j++){
            m2[s2[j]]++;
            if(j-i+1>size){
                m2[s2[i]]--;
                if(m2[s2[i]]==0)
                    m2.erase(s2[i]);
                i++;
            }
            if(m2==m)
            return true;
      }
    return false;
    }
};

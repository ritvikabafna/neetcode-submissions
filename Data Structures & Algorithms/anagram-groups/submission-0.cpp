class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
       for(int i=0;i<strs.size();i++) {
       string s=strs[i];
       string key=strs[i];
       sort(key.begin(),key.end());
       m[key].push_back(s);
       }
       vector<vector<string>> ans;
       
       for(auto it:m){
           ans.push_back(it.second);
       }

       return ans;

    }
};

class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(m.size()==0)
            return "";
        vector<pair<int,string>> &vec=m[key];
        string ans="";
        int st=0,end=vec.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(vec[mid].first<=timestamp){
                ans=vec[mid].second;
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        } 
        return ans;   
    }
    
};

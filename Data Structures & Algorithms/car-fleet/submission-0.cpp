class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back(make_pair(position[i],speed[i]));
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        stack<float>s;
        for(int i=0;i<position.size();i++){
            if(s.empty() || s.top()<1.0*(target-v[i].first)/v[i].second){
                s.push(1.0*(target-v[i].first)/v[i].second);
            }
            
        }
        return s.size();

    }
};

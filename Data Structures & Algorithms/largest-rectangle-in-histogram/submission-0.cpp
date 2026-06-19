class Solution {
public:

    vector<int> prevSmallerEle(vector<int>& heights,int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
     vector<int> nextSmallerEle(vector<int>& heights,int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }

        return ans;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next;
        next=nextSmallerEle(heights,n);
        vector<int>prev;
        prev=prevSmallerEle(heights,n);

        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int ht=heights[i];
            if(next[i]==-1)
                next[i]=n;
            int width=next[i]-prev[i]-1;
            int area=ht*width;
            maxi=max(area,maxi);
        }
        return maxi;

    }
};

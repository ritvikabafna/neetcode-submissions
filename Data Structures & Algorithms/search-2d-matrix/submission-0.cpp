class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colNum=matrix[0].size();
        int rowNum=matrix.size();
        int row=-1;
        for(int i=0;i<rowNum;i++){
            if(target>=matrix[i][0] && target<=matrix[i][colNum-1]){
                row=i;
                break;
            }
        }
        if(row==-1)
            return false;
        int st=0,end=colNum-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]<target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};

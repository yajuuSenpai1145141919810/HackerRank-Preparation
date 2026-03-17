//Find First Occurrence
int findFirstOccurrence(vector<int> nums, int target) {
    int n=nums.size();
    int left=0;
    int right=n-1;
    int mid=0;
    //!!!!!直接先設定-1是精髓
    int answer=-1;

    while(left<=right){
        mid=(left+right)/2;
        if(target==nums[mid]){
            
            //先把答案存起來
            answer=mid;
            
            //再繼續往左找即可 不用想太多
            right=mid-1;
        }else if(target>nums[mid]){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return answer;
}

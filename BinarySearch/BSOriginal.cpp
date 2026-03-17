//Binary search
//最基本款的
int binarySearch(vector<int> nums, int target) {
    int n=nums.size();
    int left=0;
    int right=n-1;
    int mid=0;
  
    //因為我設定right=n-1 所以用<= 
    while(left<=right){
        mid=(left+right)/2;
        if(target==nums[mid]){
            return mid;
        }else if(target>nums[mid]){
            //因為mid已經檢查過不是了 所以要+1 
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    //題目有說 找不到就-1
    return -1;
}

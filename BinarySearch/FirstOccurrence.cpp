//Find First Occurrence
int findFirstOccurrence(vector<int> nums, int target) {
    int n=nums.size();
    int left=0;
    int right=n-1;
    int mid=0;
    if(n==0 ){
        return -1;
    }
    while(left<=right){
        mid=(left+right)/2;
        if(target==nums[mid]){
            //這邊寫法是可以 但效能不好 
            while(mid>0&&nums[mid]==nums[mid-1]){
                mid--;
            }
            return mid;
        }else if(target>nums[mid]){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    return -1;
}

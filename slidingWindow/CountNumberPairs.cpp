// Count Number Pairs
// Given a sorted array of positive integers and a target value, count the number of pairs (i, j) where i < j and array[i] + array[j] <= target.
// Input: prices = [1, 2, 3, 4, 5], budget = 7 => Output: 8

// 關鍵字: Sorted array , Count the number of pairs , Array[i] + Array[j] <= target 
// 因此用雙指標

// Time complexity: O(n)  把array 跑過一次而已
// Space complexity: O(1) 沒有新增空間
int countAffordablePairs(vector<int> prices, int budget) {
    int n=prices.size();
  
    //edge cases
    if(n<2){
        return 0;
    }
    
    int left=0;
    int right=n-1;
    int count=0;
    while(left<right){
        if((prices[left]+prices[right])<=budget){
            //不用管這麼多 直接加上中間的差距 因為她有排好了
            count+=(right-left);
            left++;
        }else{
            right--;
        }
    }
    return count;
}



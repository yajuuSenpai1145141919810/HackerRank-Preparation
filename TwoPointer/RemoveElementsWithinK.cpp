// Easy
// Remove Elements Within K Distance

// Given a non-decreasing array of integers and an integer K, 
// remove in-place any element that is within K of the previous kept element and return the new length. 
// Use constant extra space and single pass with two pointers.

// Input: timestamps = [1, 2, 3, 8, 10] K = 3 Output: 2

#include <iostream>  
#include <vector>    

using namespace std;

int debounceTimestamps(vector<int> timestamps, int K) {
    int n=timestamps.size();
 
    // 像是另一題 因為他是鏈結串列 所以才要用fast跟slow指標 ,因問鏈結串列沒有index
    // 這裡只要設定一個 最後位子即可
    int lastPosition=0;

    // 第一個一定會算進去 所以直接從一即可!!!
    int count=1;
    
    //edge cases
    if(n==0){
        return 0;
    }
    if(K==0){
        return n;
    }

    // 不用處理第一筆資料=> 直接i=1開始就好!
    for(int i=1;i<n;i++){
        if((timestamps[i]-timestamps[lastPosition])>=K){
            lastPosition=i;
            count++;
        }

    }
    return count;
}

 

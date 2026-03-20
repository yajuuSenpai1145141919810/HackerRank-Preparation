// Two Sum
// Given an array of positive integers and a target integer, 
// return the indices of two elements that sum to the target or [-1, -1] if no such pair exists.

// Input:taskDurations = [2, 7, 11, 15] ,slotLength = 9, Output:[0, 1]

// Time complexity=O(n)  有用for迴圈
// Space complexity=O(n) 宣告了一個 Hash table

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findTaskPairForSlot(vector<int> taskDurations, int slotLength) {
    int n=taskDurations.size();
    if(n<2){
      
        // 注意回傳格式!!
        return {-1,-1};
    }
    // 注意格式!!!
    unordered_map<int, int> task;

    for(int i=0;i<n;i++){
      
        // 先設一個need 看差多少
        int need=slotLength-taskDurations[i];
      
        //去找task裡面是否有need的數值
        if(task.find(need)!=task.end()){
          
            // 假設陣列是 [2, 7, 11]，目標是 9
            // 當i=0(數值是 2),地圖現在是空的，找不到 7,你把自己存進去：task[2] = 0,
            // 當i=1(數值是 7),算出need=2。查地圖，找到了！2 住在 0 號位置。重點： 這時候 i 是 1。
            //如果寫 {task[need], i}，你會回傳 {0, 1}。
            return {task[need],i};
        }
        //這跟一般的陣列不一樣 這邊是task[你存的數值]=他的位置 跟陣列反過來
        task[taskDurations[i]]=i; 
    }
    return {-1,-1};

}



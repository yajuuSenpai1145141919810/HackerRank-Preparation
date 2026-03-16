//EASY
//Find the Smallest Missing Positive Integer
//Given an unsorted array of integers, find the smallest positive integer not present in the array in O(n) time and O(1) extra space.
//主要是讓1在一號位 2在二號位
//有說O(1)代表要in place 不能開新表格
//有負的可以無視
//如果數字大於位子數 也可以不用管
//重點是 讓你現在讀取到的數字 去他對應的位置
int findSmallestMissingPositive(vector<int> orderNumbers) {
    int n=orderNumbers.size();
    for(int i=0;i<n;i++){
      
        //[2 3 1]
        //當i=0, orderNumbers[orderNumbers[i]-1]是2應該要去的位子 目前是3 他不等於orderNumbers[i]的2 因此交換變成 [3 2 1]
        //然後orderNumbers[i]變成3 ,此時orderNumbers[orderNumbers[i]-1]的值是1 因此交換 變成 [1 2 3]
        //最後當orderNumbers[i]=1,進入第三個條件 自己跟自己相同 跳出
        while((orderNumbers[i]>0)&&orderNumbers[i]<=n&&orderNumbers[orderNumbers[i]-1]!=orderNumbers[i]){
          
            //這個交換會一直做到底才會停下來 因此要用while
            swap(orderNumbers[i],orderNumbers[orderNumbers[i]-1]);
        }
    }
    //如果抓到2不在第二個位子 那他就是missing
    for(int i=0;i<n;i++){
        if(orderNumbers[i]!=i+1){
            return i+1;
        }
    }
    //這是精髓!!! 如果都符合的話 就是下一個數
    return n+1;
}

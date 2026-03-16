//easy
//Check Palindrome by Filtering Non-Letters
//重點1.如果有兩個以上的字母再去檢查就好'
//重點2.採取即時比對避免浪費
//極端條件 空字串,只有一個數字或一個字母都會是回文 
//我採用的是雙指標的方式(left,right)

//Time complexity :O(n) 因為只有把這個string看一次
//space complexity:O(1) 因為只有宣告兩個變數

bool isAlphabeticPalindrome(string code) {
  //索引指標
  int left=0;
  int right=code.length()-1;
  
  //這邊可以過濾掉只有一個字母或數字以下的狀況
  while(left<right){
    //if not alphabet ,skip
    if(!isalpha(code[left])){
      left++;
    }else if(!isalpha(code[right])){
      right--;
      
    }else{
      //一對比發現錯誤就提早結束
      if(tolower(code[left])!=tolower(code[right])){
        return false;
      }
      left++;
      right--;
    }
  }
    return true;
}


//Validate Properly Nested Brackets
//Given a string, check if all brackets ('()', '{}', '[]') are properly matched and nested. Return 1 if valid, otherwise return 0.

//解題思路
//只要看到「成雙成對」、「後進先出」、「對稱檢查」，腦袋就要跳出：Stack 。
//要考慮三個錯誤條件 有左括號無右括號,只有右邊括號,錯誤的括號搭配像是{+]
//然後第一個條件是在迴圈外(最後一行) 其餘兩個在回圈內

bool areBracketsProperlyMatched(string code_snippet) {

    //建立堆疊的寫法
    stack<char> s;

    //注意不是拿s去算 s此時啥都沒有
    int n=code_snippet.size();
    
    //edge case
    if(n==0){
        return 1;
    }
  
    for(int i=0;i<n;i++){
        char c=code_snippet[i];
        if (c=='['||c=='{'||c=='(') {
            s.push(c);
        }else if(c==']'||c=='}'||c==')'){
            //no left but have rigtt symbol
            if (s.empty()) {
                return false;
            }
            //先儲存下來 因為不只要做一次!!!
            char sTOP=s.top();
          
            if((c==']'&&sTOP=='[')||(c=='}'&&sTOP=='{')||(c==')'&&sTOP=='(')){
                s.pop();
            }else {
            return false;
            }   
        }
    }
  
    //過濾掉 左邊括號比較多 因為 我已經run完結果還有剩下 因此寫在迴圈外面
    return s.empty();
}

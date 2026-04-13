// Min-Tracking Stack Implementation
// Implement a stack that supports push, pop, top, and getMin operations in O(1) time, where getMin returns the minimum element.

// Input format: array of n number of operations
// Output format: An integer array of length equal to the total number of "top" and "getMin" operations in the input

// min track 且要O(1)的getmin 所以要選擇用Two Stacks
// 不能在呼叫 getMin 時才去找答案，必須在 push 的那一刻就把「當下的最小值」存起來
// push pop不用列出來,但getmin top 要

//Time complexity :O(1), 四個操作 題目說的
//Space complexity :O(n),因為多開一個陣列

// EX:
// operations = ['push 2', 'push 0', 'push 3', 'push 0', 'getMin', 'pop', 'getMin', 'pop', 'top', 'getMin']
// 會印出 [0,0,0,0]

vector<int> getMinStack(vector<string> operations) {
    vector<int> result; // 存 top 和 getMin 的結果(題目要求)
    stack<int> mainStack; 
    stack<int> minStack; // 為了讓getmin可以是O(1)
  
    for (string op : operations) {
      
        // note: switch不支援string
        // 只有push有數字,且find是傳回來找到的起始位子,又題目的operations每一個資料都有用,隔開 因此==0就是抓每一個push
        // 不行寫 op == "push"：代表剛好只有push這四個字，抓不了數字
        if (op.find("push") == 0) {
          
            // substr(5): ex.push 12則剛好是從1的地方開始切substr
            // 上面宣告用int 要轉int
            int val = stoi(op.substr(5)); 
            
            mainStack.push(val);
            
            // 處裡minStack：如果新數字更小就放新的，否則重複放目前的最小值 如果說現在有8 進來2 就加入
            if (minStack.empty() || val < minStack.top()) {
                minStack.push(val);
            } else {
                //如果說原本2,進來5 那就複製一個2進來跟維持跟mainstack等高
                minStack.push(minStack.top());
            }
        } 
        else if (op == "pop") {
            mainStack.pop();
            minStack.pop();
        } 
        else if (op == "top") {
          
            //因為題目要回傳top的數,且result是vector 必須要用pushback,如果只有mainStack.top(),只是看一眼 並沒有回傳任何東西
            //注意! top是回傳mainstack
            result.push_back(mainStack.top());
        } 
        else if (op == "getMin") {
            //回傳最小值是minstack
            result.push_back(minStack.top());
        }
    }
    return result;
}



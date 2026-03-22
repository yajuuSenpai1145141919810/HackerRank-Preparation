// Generate Valid Angle Bracket Sequences
// Given n, return all valid sequences of n pairs of '<' and '>' with proper nesting.
// Input: n = 2 Output: <><> and <<>>

// 這題跟Validate Brackets那一題目差在 這題只有一種 所以不要用stack
// 不能用 while 的原因只有一個：while 只能走出一條直線，但這題是一棵樹!!!

include<iostream>
vector<string> generateAngleBracketSequences(int n) {
    
    vector<string> result;
    if(n==0){
        return {};
    }
    auto backstrack=[&](auto& self,string current,int left,int right){

        // 如果說n=2 其中一種 "<><>" 跑完後就輸出
        if(current.length()==2*n){

            //這是vector用的語法
            result.push_back(current);
            return;
        }
        
        if(left<n){

            // 因為要recursion下去 自己呼叫自己
            self(self,current+'<',left+1,right);
        }
        if(right<left){
        self(self,current+'>',left,right+1);
        }
    }; // 不要忘記這邊有一個;!!!

    // backtrack(backtrack, ...)：
    // 第一個 backtrack 是**「動作」（我要啟動這台機器）。
    // 第二個 backtrack 是「零件」**（我要把這台機器的名片傳進去，讓它內部可以遞迴）。
    backstrack(backstrack,"" ,0,0);
    return result;
}


// auto backtrack 的 auto 讓編譯器去幫你決定這個 Lambda 變數的類型
// auto& self 的 auto,不管傳進來的這個『自己』是什麼類型，請用引用 (&) 的方式接住它。
// [] (空的)：Lambda 變成一個孤島，它看不到你在外面宣告的 result 向量，也看不到 n。
// [=] (值傳遞)：它會把外面的變數「複製」一份進去。但因為是複製，你在 Lambda 裡面往 result 丟東西，外面的 result 根本不會變，這就白忙一場了。
// [&] (引用傳遞)：這代表 Lambda 直接「連線」到外面的變數。當你在 Lambda 裡面執行 result.push_back()，它會真的改動到外面那個 vector<string> result

// push_back 是 std::vector（動態陣列）專用的指令，意思是：「把一個新元素丟到陣列的最後面」


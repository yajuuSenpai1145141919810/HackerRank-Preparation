// Lexicographical Letter Combinations of Phone Digits
// Given a string of digits where '2'-'9' map to letters (like on a phone keypad) and '0','1' map to themselves, 
// return all possible letter combinations in lexicographical order.

// 每一層都有多個選擇，且層數不固定->backtracking

// Time complexity:O(n^4):因為每個數字最多對應 4 個字母，如果輸入長度為 $N$，總共會有 $4^N$ 種組合。
// Space complexity: O(1):遞迴的深度等於 digits 的長度

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> minTasksToCancelForNoConflict(string digits) {
    if(digits.empty()){
        return {};
    }
    vector<string> mapping{
        "0",
        "1",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> result;

    auto solve=[&](auto& self,int index,string current)->void{  // index就是我現在做到哪裡 如果說23,index=0就是2(指向現在做到哪裡拉)

        // 1. 終止條件
        if(index==digits.length()){
            result.push_back(current);
            return;
        }
        
        // digits[index] 抓出字元轉成數字 , "- '0'" 文字轉數字
        // mapping[0] 是 "0", mapping[1] 是 "1",mapping[2] 是 "abc"
        string letter=mapping[digits[index]-'0'];

        // 2. 遍歷當前層的所有選擇 
        // 如果說digits[index]抓到2會mapping到abc,然後這邊再讓abc分別下去跑
        for(char c:letter){ // 把一個字串（或陣列）裡的字元一個接一個抓出來

            // 3. 做出選擇 (Make a choice)
            self(self,index+1,current+c);
        }
    };
    // 4. 進入下一層遞迴
    solve(solve,0,"");
    return result;
}

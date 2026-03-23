// Lexicographical Letter Combinations of Phone Digits
// Given a string of digits where '2'-'9' map to letters (like on a phone keypad) and '0','1' map to themselves, 
// return all possible letter combinations in lexicographical order.

// 每一層都有多個選擇，且層數不固定->backtracking

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
    auto solve=[&](auto& self,int index,string current)->void{
        if(index==digits.length()){
            result.push_back(current);
            return;
        }
        string letter=mapping[digits[index]-'0'];
        for(char c:letter){
            self(self,index+1,current+c);
        }
    };
    solve(solve,0,"");

    return {result};
}

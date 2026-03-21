// Check Valid Anagram
// Given two strings s and t, return 1 if t is an anagram of s, otherwise return 0.
// Input: s = listen, t = silent. Output:1
// string s of length n, where 0 ≤ n ≤ 1000, "containing only lowercase letters 'a' to 'z'" .
// Anagram: 指由相同字母組成，但排列順序不同的字串
// Note: 'a' = 97
// 因為題目有說 containing only lowercase letters 'a' to 'z' 所以用減去'a'=97的hash方式即可!!!

int isAnagram(string s, string t) {
    int n=s.length();
    int m=t.length();
    
    if(n!=m){
        return 0;
    }
    int count[26]={0};
    for(int i=0;i<n;i++){
            count[s[i]-'a']++;
    }
    for(int i=0;i<m;i++){
            count[t[i]-'a']--;
    }
    //這邊要注意不用else,不然會變成只檢查了一個就離開了(return會立刻離開 但我要全部檢查一次!!
    for(int i=0;i<26;i++){
        if(count[i]!=0){
            return 0;
        }
    }
    return 1;    
}

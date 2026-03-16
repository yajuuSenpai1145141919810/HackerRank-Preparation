//查詢後發現更好的解題
//原本是1234 轉之後可以是2341,3412,4123
//我把1234變成12341234 裡面一定會包刮他們三個
bool isNonTrivialRotation(string s1, string s2) {
    int n=s1.length();
    int m=s2.length();
    //如果兩個長度不同就不可能對
    if(n!=m){
        return false;
    }
    //轉完後兩個相同也不行
    if(s1==s2){
        return false;
    }
    //空字串或是只有一個字母必定不對
    if(n<=1||m<=1){
        return false;
    }
    
    string comb=s1+s1;
    //因為find會返回位置,我只需要知道他不等於找不到即可(至於在comb中哪一段符合我不需要知道
    if(comb.find(s2)!=string::npos){
        return true;
    }
    return false;
}
/*bool found = false;
*int len_c = comb.length();
*int len_s = s2.length();
*
*// 外層迴圈：決定從哪一個位置開始比對
*for (int i = 0; i <= len_c - len_s; i++) {
*    // 內層比對：從位置 i 開始，抓出長度為 len_s 的子字串來比比看
*    // 這裡我們用 C++ 內建的 substr(開始位置, 長度) 來簡化
*   if (comb.substr(i, len_s) == s2) {
*        found = true;
*        break; // 找到了，不用再找了，直接跳出迴圈
*    }
*}
*
*if (found) return true;
*/

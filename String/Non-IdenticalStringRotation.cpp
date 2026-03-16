//Non-Identical String Rotation
//說空的不對
//只有一個字母也不對
//只有重複的字母像是aaa也不對
//aba轉三次(跟自己的字母一樣多次)return 0
//abab 這種有重複的轉兩次也會不對
bool isNonTrivialRotation(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    // 1. 處理「空字串」或「長度不等」
    if (n == 0 || n != m) return false;

    // 2. 處理「只有一個字母」 
    // 因為只有一個字母，轉完一定跟自己一樣，不符合 Non-Identical
    if (n == 1) return false;

    // 3. 題目要求 Non-Identical 
    // 這也順便處理了「aaa」這種 case，因為 aaa 轉完還是 aaa
    if (s1 == s2) return false;

    // 4. 開始「旋轉」並「比對」
    string temp = s1;
    for (int i = 1; i < n; i++) {
        // 模擬左旋轉一次：把第一個字放到最後面
        // 例如：abcde -> bcdea
        char firstChar = temp[0];
        temp.erase(0, 1);       // 刪除第 0 個字
        temp.push_back(firstChar); // 加到最後面

        //這段的重點就是 我轉動s1 去看是否會跟s2一樣 如果一樣的話 要避免題目說的轉完後跟原本s1一樣
        // 每轉一次，就檢查是否等於 s2
        if (temp == s2) {
            // 找到了！但還要最後確認：轉完後不能等於原本的 s1
            // (雖然一開始檢查過 s1 != s2，但這能防範 abab 轉兩次又變回 abab 的情況)
            if (temp != s1) {
                return true; 
            }
        }
    }

    // 跑完所有旋轉可能都沒匹配，或是匹配到的都跟 s1 一樣
    return false;
}

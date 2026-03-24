// Ways to Fill Slots with Single or Double Coverage
// Given n slots numbered 0 to n-1, return the number of ways to fill all slots where each operation covers either 1 slot or 2 adjacent slots.
// 注意 這不能直接用fibo去算 因為這是string 所以用DP!
// 把「數字」當成「字串」來處理
string add(string a, string b) {
    
    // Ex: a = "21", b = "34"
    string result = "";
    int carry = 0;
    
    int i = a.size() - 1; // i = 1 → 指到 '1'
    int j = b.size() - 1; // j = 1 → 指到 '4'

    // 只要「還有數字 or 還有進位」就繼續
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        // - '0'：字元 → 數字
        // a[1] = '1' → 1, sum = 0 + 1 = 1, i-- → i = 0  注意a=21的a[1]是1不是0!!
        if (i >= 0) sum += a[i--] - '0';    
        
        // b[1] = '4' → 4, sum = 1 + 4 = 5, j-- → j = 0
        if (j >= 0) sum += b[j--] - '0';  

        // 5 % 10 = 5 → '5'
        result += (sum % 10) + '0';      // + '0'：數字 → 字元

        // 5 / 10 = 0
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string countInstallationSequences(int n) {
    if (n == 0) return "1";
    if (n == 1) return "1";

    string a = "1"; // dp[0]
    string b = "1"; // dp[1]

    for (int i = 2; i <= n; i++) {
        string temp = add(a, b);
        a = b;
        b = temp;
    }

    return b;
}

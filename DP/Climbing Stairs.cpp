// Ways to Fill Slots with Single or Double Coverage
// Given n slots numbered 0 to n-1, return the number of ways to fill all slots where each operation covers either 1 slot or 2 adjacent slots.
// 注意 這不能直接用fibo去算 因為這是string 所以用DP!
string add(string a, string b) {
    string result = "";
    int carry = 0;

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result += (sum % 10) + '0';
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

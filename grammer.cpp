//網路上看到的 先記錄一下
vector<int> nums = {1, 2, 2, 3, 1, 1};
unordered_map<int, int> counts;

for (int x : nums) {
    counts[x]++; 
}

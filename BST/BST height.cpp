// Height of Binary Search Tree 
// Given the root of a binary search tree, return the height of the tree. Height is the number of nodes along the longest path from root to leaf.
// n = 7
// values = [4, 2, 6, 1, 3, 5, 7] // 其實本題不用喔XD
// leftChild = [1, 3, 5, -1, -1, -1, -1] 像是上面4,對照這邊1,代表4的左子在value[1]=2這樣
// rightChild = [2, 4, 6, -1, -1, -1, -1]
// Output:3

// 在處理樹狀結構時，遞迴是最強大的武器
//『左子樹』跟『右子樹』誰比較高，然後加 1 就好
// 高度不需要 values!!!!!

// 現在走到哪一個索引了？ currentIndex,
int calculate(int currentIndex, const vector<int>& leftChild, const vector<int>& rightChild) {
    if (currentIndex == -1) {
        return 0;
    }
    int leftH = calculate(leftChild[currentIndex], leftChild, rightChild);
    int rightH = calculate(rightChild[currentIndex], leftChild, rightChild);
    return 1 + max(leftH, rightH);
}

int getBinarySearchTreeHeight(vector<int> values, vector<int> leftChild, vector<int> rightChild) {
    if (values.empty()) return 0; 
    
    return calculate(0, leftChild, rightChild);
}

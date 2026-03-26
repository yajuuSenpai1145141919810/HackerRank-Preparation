// Compare BSTs for Equal Values but Different Structure
// Given two binary search trees root1 and root2, 
// return true if they contain the same multiset of values but have different structures, otherwise return false.

// Input
// root1 = [4, 2, 5, 1, 3, 100001, 100001]
// root2 = [3, 1, 5, 100001, 2, 4, 100001]
// Output: true

// First, collect the values of each tree (ignoring the sentinel 100001 for nulls). 
// Tree1 has values [4, 2, 5, 1, 3], and Tree2 has [3, 1, 5, 2, 4]. 
// Sorting both gives [1,2,3,4,5] in each, so the multisets match. 
// Next, compare structures: Tree1's root is 4 with children 2 (which itself has children 1 and 3) and 5; 
// Tree2's root is 3 with children 1 (right child 2) and 5 (left child 4). - The shapes differ, so the function returns true.
// 注意他題目說不要比較100001的值 要過濾掉! val1 是「資料」, root1 是「結構 + 資料」

bool verifySameMultisetDifferentStructure(vector<int> root1, vector<int> root2) {
    vector<int> val1;
    vector<int> val2;
    for(int x: root1){
        if(x!=100001) val1.push_back(x);}
    for(int x: root2){
        if(x!=100001) val2.push_back(x);}
    sort(val1.begin(),val1.end());
    sort(val2.begin(),val2.end());
    if(val1!=val2){
        return false;
    }
    

    for(int i=0;i<min(root2.size(),root1.size();i++){
        if((root1[i]==100001&&root2[i]!=100001)||(root1[i]!=100001&&root2[i]==100001)){
            return true;
        }
    }
    return false;
}


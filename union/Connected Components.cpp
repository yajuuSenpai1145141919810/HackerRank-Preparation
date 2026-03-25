// Count Connected Components in Network
// Given n computers labeled 0 to n-1 and a list of bidirectional communication links, find the number of connected components.

// links — 一個二維陣列，每個元素是一條邊，例如 [0, 1] 代表節點 0 和節點 1 相連
// 幾層括號 = 幾維 ,[[0,1], [2,3]]→ 二維

vector<int> parent;

// find 是在找這個節點的 root（老大）是誰。
// find 做了兩件事：找 root, 順便壓縮路徑
int find(int x) {
    // note:對於[0 1 2 3] 一開始就有複製一份parent=[0 1 2 3] 了喔!
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
// 把一條邊的兩個端點串起來 [0,1]這樣丟進去
void unite(int a, int b) {
    int ra = find(a), rb = find(b);

    //如果是1,2就把兩個的parents都改成2(以大的為主
    if (ra != rb)
        parent[ra] = rb;
}

// Ex:links = [[0, 1], [2, 3]]
int countIsolatedCommunicationGroups(vector<vector<int>> links, int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
  
    // 對 links 裡面的每一個元素，取出來叫做 link
    // 直接反射動作寫 auto& 就對了。
    for (auto& link : links)
      
        // for 迴圈每圈從 links 取出一個 [a,b]像是[0,1]去做unite
        unite(link[0], link[1]);

    int count = 0;
  
    // 計算有幾個root
    for (int i = 0; i < n; i++)
        if (find(i) == i) count++;

    return count;
}



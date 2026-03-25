n=4，連線是 [0,1] [1,2] [2,3]

第一步：初始化 parent
parent: [0, 1, 2, 3]

第二步：處理每條邊
第一圈 unite(0,1)
find(0) → parent[0]=0 等於0 → return 0
find(1) → parent[1]=1 等於1 → return 1
ra=0 != rb=1 → parent[0]=1
parent: [1, 1, 2, 3]
第二圈 unite(1,2)
find(1) → parent[1]=1 等於1 → return 1
find(2) → parent[2]=2 等於2 → return 2
ra=1 != rb=2 → parent[1]=2
parent: [1, 2, 2, 3]
第三圈 unite(2,3)
find(2) → parent[2]=2 等於2 → return 2
find(3) → parent[3]=3 等於3 → return 3
ra=2 != rb=3 → parent[2]=3
parent: [1, 2, 3, 3]

第三步：數 root
i=0：find(0)
  parent[0]=1 不等於0 → 繼續 find(1)
  parent[1]=2 不等於1 → 繼續 find(2)
  parent[2]=3 不等於2 → 繼續 find(3)
  parent[3]=3 等於3   → return 3
  ↑ 路徑壓縮：parent[0]=3, parent[1]=3, parent[2]=3
  find(0)=3 不等於0，不是root

i=1：find(1)
  parent[1]=3 → return 3（已壓縮）
  find(1)=3 不等於1，不是root

i=2：find(2)
  parent[2]=3 → return 3（已壓縮）
  find(2)=3 不等於2，不是root

i=3：find(3)
  parent[3]=3 等於3 → return 3
  find(3)=3 等於3，是root ✓ count=1

return 1 ✓
群組只有 {0,1,2,3}，全部串在一起，答案是 1。

*`find(0)` 呼叫過程，parent: [1, 2, 3, 3]**

**去的時候：**
```
find(0)：parent[0]=1 不等於0 → 呼叫 find(1)
  find(1)：parent[1]=2 不等於1 → 呼叫 find(2)
    find(2)：parent[2]=3 不等於2 → 呼叫 find(3)
      find(3)：parent[3]=3 等於3 → return 3
```

**回來的時候：**
```
      find(3) return 3
    find(2) 收到3 → parent[2]=3，return 3
  find(1) 收到3 → parent[1]=3，return 3
find(0) 收到3 → parent[0]=3，return 3
```




















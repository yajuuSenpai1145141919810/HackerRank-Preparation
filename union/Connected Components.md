第一步：初始化 parent
parent.resize(4)
for 迴圈跑完：
parent: [0, 1, 2, 3]

第二步：for 迴圈處理每條邊
第一圈 link = [0,1] → 呼叫 unite(0, 1)
跳去 unite：
  ra = find(0) → parent[0]=0 等於0 → return 0，ra=0
  rb = find(1) → parent[1]=1 等於1 → return 1，rb=1
  ra != rb → parent[0] = 1
parent: [1, 1, 2, 3]
第二圈 link = [1,2] → 呼叫 unite(1, 2)
跳去 unite：
  ra = find(1) → parent[1]=1 等於1 → return 1，ra=1
  rb = find(2) → parent[2]=2 等於2 → return 2，rb=2
  ra != rb → parent[1] = 2
parent: [1, 2, 2, 3]

第三步：數 root
i=0：find(0) → parent[0]=1 → parent[1]=2 → parent[2]=2 等於2 → return 2，不是root
      路徑壓縮：parent[0]=2，parent[1]=2
i=1：find(1) → parent[1]=2 → parent[2]=2 等於2 → return 2，不是root
i=2：find(2) → parent[2]=2 等於2 → return 2，是root ✓ count=1
i=3：find(3) → parent[3]=3 等於3 → return 3，是root ✓ count=2

return 2 ✓
群組是 {0,1,2} 和 {3}，所以答案是 2。

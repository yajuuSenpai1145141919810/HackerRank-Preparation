1. std::stack (堆疊) — 用於括號配對、DFS
特性：後進先出 (LIFO)。
s.push(x)：把 x 丟進去。
s.pop()：把最上面的拿掉（注意：它不會回傳值，純移除）。
s.top()：看最上面是誰（但不移除）。
s.empty()：檢查是不是空的（回傳 true/false）。
s.size()：現在有幾個。

2. std::vector (動態陣列) — 
特性：隨機存取、可變長度。
v.push_back(x)：在最後面加一個元素。
v.pop_back()：移除最後一個。
v.size()：長度。
v.clear()：清空。
v.begin(), v.end()：排序時用的迭代器（例如 sort(v.begin(), v.end())）。
v.back()：直接看最後一個元素是誰。

3.只要題目問「出現幾次」、「有沒有出現過」，先想 unordered_map
std::unordered_map (雜湊表) — 解決「找重複」、「計數」特性：查詢超快 $O(1)$。
m[key] = value：存入或更新。
m.count(key)：檢查這個 key 存在嗎（存在回傳 1，不存在回傳 0）。
m.find(key)：尋找，如果沒找到會回傳
m.end()。m.erase(key)：刪除。

4. std::queue (佇列) — 用於 BFS (找最短路徑)
特性：先進先出 (FIFO)。
推入,q.push(val),在隊伍 末端 加入一個元素。
彈出,q.pop(),移除隊伍 最前端 的元素（注意：這不回傳值）。
看隊頭,q.front(),回傳隊伍 最前端 的元素（不移除）。
看隊尾,q.back(),回傳隊伍 最末端 的元素。
檢查空,q.empty(),若 queue 是空的則回傳 true，否則 false。
看大小,q.size(),回傳目前 queue 裡有多少個元素。。

5. std::priority_queue (優先佇列/堆積) — 用於 Meeting Rooms II
特性：會自動排序，最上面的一定是最大（或最小）值。
pq.push(x)：丟進去，它會自動幫你排好。
pq.top()：看目前最強（最大/最小）的是誰。
pq.pop()：移走最強的

6.直接對 vector 用的：
sort(v.begin(), v.end())：由小到大排。
reverse(v.begin(), v.end())：反轉（例如字串反轉）。
max(a, b) / min(a, b)：比大小。
abs(x)：取絕對值。

7.函數名稱,功能：檢查該字元是否為...,例子
isalpha(c),"字母 (a-z, A-Z)",'a' → 是；'1' → 否
isdigit(c),數字 (0-9),'5' → 是；'x' → 否
isalnum(c),字母或數字 (Alphanumeric),"'A', '2' → 是；'#' → 否"
isspace(c),"空白字元 (空格, \n, \t)",' ' → 是
islower(c),小寫字母,'g' → 是
isupper(c),大寫字母,'G' → 是

8.
tolower(c)：把大寫轉小寫（如果已經是小寫，則不變）。
toupper(c)：把小寫轉大寫。

9.3. 字串 (String) 的常用語法
除了單個字元，std::string 本身的這些功能在考試中也極度高頻：
s.substr(pos, len)：切下子字串（從位置 pos 開始，長度為 len）。
s.find("abc")：找子字串。如果沒找到，會回傳 string::npos（這是考試常考的判斷點）。
stoi(s)：String to Integer。把字串 "123" 變成整數 123（非常常用！）。
to_string(num)：把整數變回字串

1. vector<T>：動態陣列 (最常用)
這是你在處理「一串資料」時的首選，比傳統陣列 int a[100] 好用一萬倍。
寫法： vector<int> nums; 或 vector<string> names;
必殺技： nums.push_back(10); (自動幫你增加長度)。
應用： 儲存會議時間、股價、學生成績。

2. queue<T>：佇列 (排隊)
跟 stack 相反，它是 先進先出 (FIFO)。
寫法： queue<int> q;
必殺技： q.push(x); (進去排隊), q.front(); (看第一個), q.pop(); (第一個離開)。
應用： 廣度優先搜尋 (BFS)、作業系統的任務排程。

3. unordered_map<Key, Value>：雜湊表 (字典)
這是面試中最容易拿到高分的工具。它能讓你用「鑰匙」去查「數值」。
寫法： unordered_map<string, int> scores;
範例： scores["Alice"] = 95;
應用： 統計單字出現次數、Two Sum 題目、快速查找資料

4. unordered_set<T>：集合 (不重複)
如果你只關心「有沒有出現過」，而不在乎出現幾次，就用這個。
寫法： unordered_set<int> seen;
必殺技： seen.insert(10); 如果再插入一次 10，它會自動忽略。
應用： 檢查資料是否重複、過濾重複的 ID






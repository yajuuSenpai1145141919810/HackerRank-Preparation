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
q.push(x)：排隊進去。
q.pop()：排第一個的離開。
q.front()：看排第一個的是誰。
q.empty()：檢查空了沒。

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




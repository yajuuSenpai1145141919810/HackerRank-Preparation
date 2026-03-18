//easy
//Maximum Number of Non-Overlapping Intervals
//Given an array of intervals where each interval has a start and end time, return the maximum number of non-overlapping intervals.\
//0 <= meetings.length <= 1000   0 <= meetings[i][0] < meetings[i][1] <= 10^9

//解題思路
//最大化不重疊數量 >>> Interval Scheduling  >>> Sort by End Time + Greedy

//如果是「最少移除」幾場？ return n-count
//如果會議有優先權 (Weight)？ 改用dp


//[[1,2], [3,4]]，meetings[0] 就是 [1,2]，而 meetings[0][0] 就是 1（開始時間）
int maximizeNonOverlappingMeetings(vector<vector<int>> meetings) {
    int n=meetings.size();
    int count=0;
  
    // record current end ,-1 because meeting can start at 0
    int last_end=-1;
    
    if(n==0){
        return 0;
    }
    
    //sort the meetings by end ,use lambda 注意這邊的語法 非常重要 這邊a[1 2],我們取a[1]就是end time
    //只要處理的資料不是簡單的數字（如 int, char, bool），而是複雜的物件（如 vector, string, struct），就一律加上 const &
    //加上 & 不產生複製，速度極快
    sort(meetings.begin(),meetings.end(),[](const vector<int> &a,const vector<int> &b)  { return a[1]<b[1]; });
    
    for(int i=0;i<n;i++){
        int start=meetings[i][0];
        int end=meetings[i][1];

        //只要我的開始時間>=目前的結束時間即可
        if(start>=last_end){
            count++;
            last_end=end;
        }
    }
    return count;
}


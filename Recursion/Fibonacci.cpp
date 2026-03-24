// Custom Fibonacci Sequence
// Given n (0-based indexing), return the n-th Fibonacci number where F(0) = 1, F(1) = 2, and F(n) = F(n-1) + F(n-2).
long getAutoSaveInterval(int n) {
    // 要設定成long
    long temp=0;
    long a=1;
    long b=2;
    if(n==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    for(int i=0;i<n-1;i++){
        temp=a+b;
        a=b;
        b=temp;
    }
    return temp;

}

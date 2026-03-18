//Min-Tracking Stack Implementation
//Implement a stack that supports push, pop, top, and getMin operations in O(1) time, where getMin returns the minimum element.

//主題是min track 且題目有說要O(1) 所以要選擇用Two Stacks去解決
//不能在呼叫 getMin 時才去找答案，你必須在 push 的那一刻就把「當下的最小值」存起來
//原本o(n)但因為開另一個stack,變成只需要pop() 所以變成o(1)

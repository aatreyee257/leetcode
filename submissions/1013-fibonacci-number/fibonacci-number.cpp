class Solution {
public:
    vector<int>memo;
    int solve(int n)
    {
        if(n<=1)
       {
        return n;
       }
       if(memo[n]!= -1)
       {
        return memo[n];
       }
       memo[n]= solve(n-1) + solve(n-2);
       return memo[n];
    }
    int fib(int n) 
    {
       memo = vector<int>(n+1,-1);
       return solve(n);
    }
};
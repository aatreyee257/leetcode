class Solution {
public:
    vector<int> memo;
    int solve(int n)
    {
        if(n ==1)
        {
            return n;
        }
        if(n == 2)
        {
            return n;
        }
        if(memo[n] != -1)
        {
            return memo[n];
        }
        memo[n] = solve(n-2)+ solve(n-1);
        return memo[n] ;
    }
    int climbStairs(int n) {
        memo = vector<int>(n+1,-1);
        return solve(n);
    }
};
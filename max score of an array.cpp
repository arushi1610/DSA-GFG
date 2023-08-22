class Solution
{
    public:
    
    long long fun(int i , int j ,vector<vector<int>> &mini,vector<int>&arr, vector<vector<long long>> &dp){
        
        if(i==j){
            return arr[i]+mini[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }        
        long long left = (long long )arr[i] *(long long)(j-i+1) +(long long) mini[i][j] + fun(i+1 , j , mini , arr , dp);
        long long right =(long long)arr[j] *(long long)(j-i+1) +(long long) mini[i][j] + fun(i , j-1 , mini , arr , dp); 
        
        return dp[i][j] = max(left, right);
        
        
    }
    long long MaxScore(int N, vector<int>&arr)
    {
        vector<vector<int>> mini(N , vector<int>(N));
        vector<vector<long long>> dp(N ,vector<long long>(N ,-1));
        
        for(int i=0;i<N;i++){
            int mn = INT_MAX;
            for(int j = i; j<N;j++){
                mn = min(mn , arr[j]);
                mini[i][j] = mn;
            }
        }
        return fun(0 , N-1 , mini ,arr , dp);
        // code here
    }
};
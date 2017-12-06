int lcs(VI & X,VI & Y)
{
    // Find lengths of two strings


    int m = X.size(),  n= Y.size();

    VVI dp(2,VI(n+1));


    // Binary index, used to index current row and
    // previous row.

    int cr,pr;

    for(int j=0;j<=n ;j++)
		dp[0][j]=0;

    for (int i=1; i<=m; i++)
    {
        // Compute current binary index
        cr = i&1;
        pr=	 1-cr;

        for (int j=1; j<=n; j++)
        {

            if(X[i-1] == Y[j-1])
                dp[cr][j] = dp[pr][j-1] + 1;

            else
                dp[cr][j] = max(dp[pr][j], dp[cr][j-1]);
        }
    }

    /* Last filled entry contains length of LCS
       for X[0..n-1] and Y[0..m-1] */
    return dp[cr][n];
}


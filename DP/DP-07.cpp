int f_TD(int day, int last, vector<vector<int>>&dp, vector<vector<int>>&points)
{
    if(day == 0)
    {
        int mx = 0;
        for(int task=0;task<3;task++)
        {
            if(task != last)
                mx = max(mx, points[0][task]);
        }
        return mx;
    }
    if(dp[day][last] != -1)
        return dp[day][last];
    int mx = 0;
    for(int task=0;task<3;task++)
    {
        if(task != last)
        {
            int pnts = points[day][task] + f_TD(day-1, task, dp, points);
            mx = max(mx, pnts);
        }
    }
    return dp[day][last] = mx;
}
int f_BU(vector<vector<int>>&points)
{
    int n = points.size();
    vector<vector<int>>dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            dp[day][last] = 0;
            for(int task=0;task<3;task++)
            {
                if (task != last) {
                  int pnts = points[day][task] + dp[day - 1][task];
                  dp[day][last] = max(dp[day][last], pnts);
                }
            }
        }
    }
    return dp[n-1][3];
}

int f_BU_SO(vector<vector<int>>&points)
{
    int n = points.size();
    vector<int>prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1;day<n;day++)
    {
        vector<int>tmp(4, 0);
        for(int last=0;last<4;last++)
        {
            tmp[last] = 0;
            for(int task=0;task<3;task++)
            {
                if (task != last) {
                    int pnts = points[day][task] + prev[task];
                    tmp[last] = max(tmp[last], pnts);
                }
            }
        }
        prev = tmp;
    }
    return prev[3];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // vector<vector<int>>dp(n, vector<int>(4, -1));
    // return f_TD(n-1, 3, dp, points);

    // return f_BU(points);

    return f_BU_SO(points);
}
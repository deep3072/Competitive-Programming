[Problem](https://leetcode.com/problems/longest-increasing-subsequence/) : Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the `ith` day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.


<details>
<summary>Code</summary>

```
class Solution 
{
        public:
        vector<int> dailyTemperatures(vector<int>& temp) 
        {
            stack<int>st;
            int i, n =temp.size();
            vector<int>ans(n, 0);
            for(i=0;i<n;i++)
            {
                while(!st.empty() && temp[st.top()] < temp[i])
                {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }    
            return ans;
        }
};

```
</details>
        
<details>
<summary>Bonus</summary>
        
- [Adding Soon]("Link")
</details>



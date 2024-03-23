// Alien Dictionary

class Solution
{
    public:
    string findOrder(string dict[], int n, int k) 
    {
        int i;
        // Find differenciating factor between two consecutive pairs;
        // After finding just add a directed edge from s1[a] to s2[b]
        vector<int>adj[k];
        vector<int>indegree(k, 0);
        for(i=0;i<n-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int a = 0, b = 0;
            while(a < s1.size() && b < s2.size())
            {
                if(s1[a] != s2[b])
                {
                    adj[s1[a] - 'a'].push_back(s2[b] - 'a');
                    indegree[s2[b] - 'a']++;
                    break;
                }
                a++, b++;
            }
        }
        
        // Now perform toposort
        queue<int>q1;
        for(i=0;i<k;i++)
        {
            if(indegree[i] == 0)
                q1.push(i);
        }
        string order;
        while(!q1.empty())
        {
            auto curr = q1.front();
            q1.pop();
            order.push_back(curr+'a');
            for(auto it:adj[curr])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q1.push(it);
            }
        }
        return order;
    }
}

// when the order is not possible: 2 cases
// 1. When there is a cycle: {aba, bat, ade}
// 2. {abcd, abc}; shorter string should be before larger if all char are matching
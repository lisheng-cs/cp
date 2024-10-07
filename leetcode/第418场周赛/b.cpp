/*
 * @Descripttion:
 * @Author: laidui
 * @version:
 * @Date: 2024-10-06 22:46:16
 * @LastEditors: lai dui
 * @LastEditTime: 2024-10-06 22:56:56
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> g(n), rg(n);
        vector<int> ans;
        for (auto t : invocations)
        {
            g[t[0]].push_back(t[1]);
            rg[t[1]].push_back(t[0]);
        }
        queue<int> q;
        q.push(k);
        vector<int> vis(n, 0);
        vis[k] = 1;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            for (int v : g[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1, q.push(v);
                }
            }
        }
        vector<int> vis2(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                q.push(i);
                vis2[i] = 1;
            }
        }
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            for (int v : rg[u])
            {
                if (!vis[v])
                {
                    for (int i = 0; i < n; i++)
                    {
                        ans.push_back(i);
                    }
                    return ans;
                }
                if (!vis2[v])
                {
                    vis2[v] = 1;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis2[i])
                ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    return 0;
}
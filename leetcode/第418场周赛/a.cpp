/*
 * @Descripttion:
 * @Author: laidui
 * @version:
 * @Date: 2024-10-06 22:45:54
 * @LastEditors: lai dui
 * @LastEditTime: 2024-10-06 22:47:14
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxGoodNumber(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        vector<int> arr{0, 1, 2};
        do
        {
            int cnt = 0, s = 0;
            for (int v : arr)
            {
                int t = nums[v];
                s += nums[v] * (1 << cnt);
                while (t)
                {
                    cnt++, t >>= 1;
                }
            }
            ans = max(ans, s);
        } while (next_permutation(arr.begin(), arr.end()));
        return ans;
    }
};
int mian()
{
    return 0;
}
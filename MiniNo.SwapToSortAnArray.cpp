#include <bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);

    vector<bool> vis(n, false);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i)
            continue;

        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
        // update ans. by adding current cycle
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 3, 5, 4};
    int n = (sizeof(arr) / sizeof(int));
    cout << minSwaps(arr, n);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
#include <climits>

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime)
{
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painters++;
            time = arr[i];
        }
    }
    return painters <= m;
}

int minTimeToPaint(vector<int> &arr, int n, int m)
{
    int sum = 0, maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, m;
cin >> n >> m;

vector<int> arr(n);

for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

    cout << minTimeToPaint(arr, n, m) << endl;
    return 0;
}
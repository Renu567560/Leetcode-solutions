#include <bits/stdc++.h>

using namespace std;

// Helper functions for HackerRank's default input reading
string ltrim(const string &str) {
    string s = str;
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    return s;
}

string rtrim(const string &str) {
    string s = str;
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

// --- AAPKA ACTUAL LOGIC ---

long long merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    long long invCount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
    return invCount;
}

long long mergeSort(vector<int> &arr, int st, int end) {
    if (st >= end) return 0;
    int mid = st + (end - st) / 2;
    long long count = 0;
    count += mergeSort(arr, st, mid);
    count += mergeSort(arr, mid + 1, end);
    count += merge(arr, st, mid, end);
    return count;
}

long countInversions(vector<int> arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string t_temp;
    getline(cin, t_temp);
    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);
        int n = stoi(ltrim(rtrim(n_temp)));
        string arr_temp_temp;
        getline(cin, arr_temp_temp);
        vector<string> arr_temp = split(rtrim(arr_temp_temp));
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);
            arr[i] = arr_item;
        }
        long result = countInversions(arr);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
 
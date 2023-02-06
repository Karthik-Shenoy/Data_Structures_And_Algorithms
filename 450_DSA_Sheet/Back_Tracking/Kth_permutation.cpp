#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string rec(int k, int fac, string ans, set<int> arr, int n)
{
    //cout << k << ' ' << fac << ' ' << "\n";
    if(k == 0 || n == 0)
    {
        while(arr.size())
        {
            set<int>::iterator itr = arr.end(); itr--;
            char x = '0' + *itr;
            arr.erase(*itr);
            ans += x;
        }
        return ans;
    }
    int index = k / fac + (k % fac == 0 ? 0 : 1), i = 1;
    auto itr = arr.begin();
    while(i < index && itr != arr.end())
    {
        itr++;
        i++;
    }
    ans += '0' + *itr;
    arr.erase(*itr);
    return rec(k - (k/fac) * fac, fac/n, ans, arr, n-1);
}
string kthPermutation(int n, int k)
{
    // code here
    set<int> arr;
    int fac = 1;
    for(int i = 1; i <= n; i++)
    {
        arr.insert(i);
        fac *= i;
    }
    fac /= n;
    string ret = rec(k, fac, "", arr, n-1);
    return ret;
}
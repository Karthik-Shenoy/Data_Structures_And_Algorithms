#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> solve(int index, string& str, map<string, bool>& dic)
{
    if(index >= str.length())
    {
        vector<string> ret;
        ret.push_back("");
        return  ret;
    }
    string temp = "";
    vector<string> ret;
    for(int i = index; i < str.length(); i++)
    {
        temp += str[i];
        if(dic[temp] == 1)
        {
            vector<string> arr = solve(i+1, str, dic);
            for(auto x:arr)
            {
                string curr = temp;
                if(x != "")
                    curr += " " + x;
                ret.push_back(curr);
            }
        }
    }
    return ret;
}
vector<string> wordBreak(int n, vector<string>& dict, string s)
{
    // code here
    map<string, bool> dic;
    for(auto x: dict)
        dic[x] = 1;
    return solve(0, s, dic);
}
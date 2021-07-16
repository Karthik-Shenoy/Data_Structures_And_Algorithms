#include<iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

long find_struct[100001];

long get(long a)
{
	long curr = a, set_name;
	vector<long> elements;
	while(curr >= 0)
	{
		set_name = curr;
		elements.push_back(set_name);
		curr = find_struct[curr];
	}
	for(int i = 0; i < elements.size() - 1; i++)
		find_struct[elements[i]] = set_name;
	return set_name;
}

void uni(long a,long b)
{
	long s1_name = get(a), s2_name = get(b);
	if(s1_name != s2_name)
	{
		if(find_struct[s1_name] < find_struct[s2_name])
        {
            long set_sz = find_struct[s2_name];
			find_struct[s2_name] = s1_name;
            find_struct[s1_name] += set_sz;
        }
		else
        {
            long set_sz = find_struct[s1_name];
			find_struct[s1_name] = s2_name;
            find_struct[s2_name] += set_sz;
        }
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long n, m;
	cin >> n >> m;
	memset(find_struct, -1, sizeof(find_struct));
	while(m)
	{
		long a,b;
		string oper;
		cin >> oper >> a >> b;
		if(oper == "union")
			uni(a,b);
		else
		{
			if(get(a) == get(b))
				cout << "YES";
			else
				cout << "NO";
            cout << endl;
		}
		m--;
	}
}

#include<iostream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

vector<long> parent, maxi, mini, set_size;

long get(long a)
{
	if(parent[a] == a) return a;
	//collapsing find to improve time complexity all nodes point to -> parent
	/*
	arr[0] = set_name;
	arr[3] = abs(find_struct[set_name][0]);
	arr[1] = find_struct[set_name][1];
	arr[2] = find_struct[set_name][2];
	*/
	return parent[a] = get(parent[a]);
}

void uni(long a,long b)
{
	long s1_name = get(a), s2_name = get(b);
	if(s1_name != s2_name)
	{
		if(set_size[s1_name] > set_size[s2_name])
        {
			parent[s2_name] = s1_name;
			mini[s1_name] = min(mini[s2_name], mini[s1_name]);
			maxi[s1_name] = max(maxi[s2_name], maxi[s1_name]);
            set_size[s1_name] += set_size[s2_name];
        }
		else
        {
            parent[s1_name] = s2_name;
			mini[s2_name] = min(mini[s2_name], mini[s1_name]);
			maxi[s2_name] = max(maxi[s2_name], maxi[s1_name]);
            set_size[s2_name] += set_size[s1_name];
        }
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long n, m;
	cin >> n >> m;
	set_size.resize(n+1);
	mini.resize(n+1);
	maxi.resize(n+1);
	parent.resize(n+1);
	for(int i=0; i <= n; i++)
	{
		set_size[i] = 1;
		mini[i] = i;
		maxi[i] = i;
		parent[i] = i;
	}
	while(m)
	{
		long a,b;
		string oper;
		cin >> oper;
		if(oper == "union")
		{
			cin >> a >> b;
			uni(a,b);
		}
		else
		{
			cin >> a;
			long s = get(a);
			cout << mini[s] << " " << maxi[s] << " " << set_size[s];
			cout << endl;
		}
		m--;
	}
}

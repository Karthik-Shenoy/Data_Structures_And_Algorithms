#include<iostream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

long find_struct[100001][3];

long get(long a)
{
	if(find_struct[a][0] < 0) return a;
	//collapsing find to improve time complexity all nodes point to -> parent
	/*
	arr[0] = set_name;
	arr[3] = abs(find_struct[set_name][0]);
	arr[1] = find_struct[set_name][1];
	arr[2] = find_struct[set_name][2];
	*/
	return find_struct[a][0] = get(find_struct[a][0]);
}

void uni(long a,long b)
{
	long s1_name = get(a), s2_name = get(b);
	if(s1_name != s2_name)
	{
		if(find_struct[s1_name][0] < find_struct[s2_name][0])
        {
            long set_sz = find_struct[s2_name][0];
			find_struct[s2_name][0] = s1_name;
			find_struct[s1_name][1] = min(find_struct[s2_name][1], find_struct[s1_name][1]);
			find_struct[s1_name][2] = max(find_struct[s2_name][2], find_struct[s1_name][2]);
            find_struct[s1_name][0] += set_sz;
        }
		else
        {
            long set_sz = find_struct[s1_name][0];
			find_struct[s1_name][0] = s2_name;
			find_struct[s2_name][1] = min(find_struct[s2_name][1], find_struct[s1_name][1]);
			find_struct[s2_name][2] = max(find_struct[s2_name][2], find_struct[s1_name][2]);
            find_struct[s2_name][0] += set_sz;
        }
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long n, m;
	cin >> n >> m;
	for(int i=0; i <= n; i++)
	{
		find_struct[i][0] = -1;
		find_struct[i][1] = i;
		find_struct[i][2] = i;
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
			cout << find_struct[s][1] << " " << find_struct[s][2] << " " << abs(find_struct[s][0]);
			cout << endl;
		}
		m--;
	}
}

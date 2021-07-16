#include<iostream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

long find_struct[100001][3];

long* get(long a, long *arr)
{
	long curr = a, set_name;
	while(curr >= 0)
	{
		set_name = curr;
		curr = find_struct[curr][0];
	}
	//collapsing find to improve time complexity all nodes point to -> parent
	arr[0] = set_name;
	arr[3] = abs(find_struct[set_name][0]);
	arr[1] = find_struct[set_name][1];
	arr[2] = find_struct[set_name][2];
	return arr;
}

void uni(long a,long b)
{
    long arr[4];
	long s1_name = get(a, arr)[0], s2_name = get(b, arr)[0];
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
			long arr[4];
			long *p = get(a, arr);
			cout << arr[1] << " " << arr[2] << " " << arr[3];
			cout << endl;
		}
		m--;
	}
}

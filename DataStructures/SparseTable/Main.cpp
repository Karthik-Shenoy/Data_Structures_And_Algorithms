#include<iostream>
#include<vector>
using namespace std;


int log(int n)
{
    int cnt = 0;
    while(n > 1)
    {
        n /= 2;
        cnt++;
    }
    return cnt;
}

vector<int> get_input()
{
    int n;
    cout << "enter the number of elements : ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter the elemets : \n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    return arr;
}

void fillSparseTable(vector<int>& arr, vector<vector<int>>& sparse_table)
{
    int size = sparse_table[0].size(), log_size = sparse_table.size();
    //init first row with the array elements
    for(int j = 0; j < size; j++)
        sparse_table[0][j] = arr[j];

    // start filling from the second row
    cout << '\n';
    for(int i = 1; i < log_size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            int pow_2_i = 1 << (i-1);
            if(j + pow_2_i < size) {
                sparse_table[i][j] = min(sparse_table[i-1][j], sparse_table[i-1][j+pow_2_i]);
            }
        }
    }
    cout << "\nSparse Table\n";
    for(int i = 0; i < log_size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << sparse_table[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // use the following array : 7 2 3 0 5 10 3 12 18
    vector<int> arr = get_input();
    // Create Sparse Table
    int size = arr.size(), nQueries, log_size = log(size) + 1;
    vector<vector<int>> sparse_table(log_size, vector<int>(size, 0));
    fillSparseTable(arr, sparse_table);

    // Run Queries
    cout << "the number of queries : ";
    cin >> nQueries;
    while(nQueries)
    {
        int left, right;
        cout << "enter the bounds to find min : \n";
        cin >> left >> right;
        int sub_array_size = right-left + 1, log_sub_array_size = log(sub_array_size); 
        int right_begin = right - (1 << log_sub_array_size) + 1;
        int sub_array_minima = min(sparse_table[log_sub_array_size][left], sparse_table[log_sub_array_size][right_begin]);
        cout << "minimum from Left to Right inclusive is " << sub_array_minima << "\n";
        nQueries--;
    }

    return 0;
}

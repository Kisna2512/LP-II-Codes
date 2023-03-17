#include <bits/stdc++.h>
using namespace std;
// e.g 7 8 2 1 3
void ssort(int arr[], int n)
{
    for (int pos = 0; pos <= n - 2; pos++)
    {
        int curr = arr[pos];
        int min_pos = pos;

        for (int j = pos; j < n; j++)
        {
            if (arr[j] < arr[min_pos])
            {
                min_pos = j;
            }
        }
        swap(arr[min_pos], arr[pos]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of an array:- " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements in array:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ssort(arr, n);
    cout << "The array after selection  sort is:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
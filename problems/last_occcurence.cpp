// make a recursive function to find the last occurence of a number in an arraye
// Time Complexity: O(n)

#include <iostream>
using namespace std;

int lastOcc(int arr[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }

    int i = lastOcc(arr + 1, n - 1, key);

    //arr+1 means we are passing the address of the next element of the array
    if (i == -1)
    {
        if (arr[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return i + 1;
}

int main()
{


    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    cout << lastOcc(arr, 7, 2) << endl;
    return 0;
}

#include <iostream>
#include <climits>

using namespace std;

void minMaxSearch(int arr[], int low, int high, int &minVal, int &maxVal)
{
    if (low == high)
    {
        minVal = arr[low];
        maxVal = arr[low];
        return;
    }

    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            minVal = arr[low];
            maxVal = arr[high];
        }
        else
        {
            minVal = arr[high];
            maxVal = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int minLeft, maxLeft, minRight, maxRight;

    minMaxSearch(arr, low, mid, minLeft, maxLeft);
    minMaxSearch(arr, mid + 1, high, minRight, maxRight);

    minVal = min(minLeft, minRight);
    maxVal = max(maxLeft, maxRight);
}

int main()
{
    int arr[] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minVal = INT_MAX, maxVal = INT_MIN;

    minMaxSearch(arr, 0, n - 1, minVal, maxVal);

    cout << "Minimum Value: " << minVal << endl;
    cout << "Maximum Value: " << maxVal << endl;

    return 0;
}

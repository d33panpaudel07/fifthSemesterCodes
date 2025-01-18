// This code was later updated by chatGPT which added counter to right place
// APPARENTLY EVEN CONDITION CHECKS FOR A LOOP IS ALSO A STEP THAT ADDS TO TIME COMPLEXITY
#include <iostream>
#include <climits>

using namespace std;

int counter = 0;

void minMaxSearch(int arr[], int low, int high, int &minVal, int &maxVal)
{
    counter++; // Increment for the function call itself
    if (low == high)
    {
        counter++; // For the condition check
        minVal = arr[low];
        maxVal = arr[low];
        counter += 2; // For the assignments
        return;
    }

    counter++; // For the second condition check
    if (high == low + 1)
    {
        counter++; // For the condition check inside the if
        if (arr[low] < arr[high])
        {
            minVal = arr[low];
            maxVal = arr[high];
            counter += 2; // For the assignments
        }
        else
        {
            minVal = arr[high];
            maxVal = arr[low];
            counter += 2; // For the assignments
        }
        return;
    }

    int mid = (low + high) / 2;
    counter++; // For the calculation of mid

    int minLeft, maxLeft, minRight, maxRight;

    minMaxSearch(arr, low, mid, minLeft, maxLeft);        // Recursive call 1
    minMaxSearch(arr, mid + 1, high, minRight, maxRight); // Recursive call 2

    minVal = min(minLeft, minRight);
    maxVal = max(maxLeft, maxRight);
    counter += 4; // For the two min and two max operations
}

int main()
{
    int arr[] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minVal = INT_MAX, maxVal = INT_MIN;

    minMaxSearch(arr, 0, n - 1, minVal, maxVal);

    cout << "Minimum Value: " << minVal << endl;
    cout << "Maximum Value: " << maxVal << endl;
    cout << "Steps: " << counter << endl;

    return 0;
}

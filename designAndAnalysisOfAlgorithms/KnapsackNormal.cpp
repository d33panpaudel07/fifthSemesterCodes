#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item
{
public:
    int itemId;
    int weight;
    int profit;
    float pByw; // profit/weight ratio
    float xi;   // Fraction of the item taken
};

void mergeRev(vector<Item> &arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int c = 0;
    int tempArrSize = high - low + 1;
    vector<Item> tempArr(tempArrSize);

    while (i <= mid && j <= high)
    {
        if (arr[i].pByw > arr[j].pByw)
        {
            tempArr[c++] = arr[i++];
        }
        else
        {
            tempArr[c++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        tempArr[c++] = arr[i++];
    }

    while (j <= high)
    {
        tempArr[c++] = arr[j++];
    }

    for (i = low, c = 0; i <= high; i++)
    {
        arr[i] = tempArr[c++];
    }
}

void mergeSortRev(vector<Item> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergeSortRev(arr, low, mid);
        mergeSortRev(arr, mid + 1, high);
        mergeRev(arr, low, mid, high);
    }
}

float fractionalKnapsack(vector<Item> &items, int n, int capacity)
{
    mergeSortRev(items, 0, n - 1);
    float profit = 0;
    int takenWeight = 0;

    for (int i = 0; i < n; i++)
    {
        if (takenWeight + items[i].weight <= capacity)
        {
            profit += items[i].profit;
            takenWeight += items[i].weight;
            items[i].xi = 1;
        }
        else
        {
            items[i].xi = (float)(capacity - takenWeight) / items[i].weight;
            takenWeight += items[i].xi * items[i].weight;
            profit += items[i].xi * items[i].profit;
            break;
        }
    }

    return profit;
}

int main()
{
    int n, knapsackCapacity;
    cout << "How many items? ";
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter itemId, weight, profit: ";
        cin >> items[i].itemId >> items[i].weight >> items[i].profit;
        items[i].pByw = (float)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack Capacity: ";
    cin >> knapsackCapacity;

    float totalProfit = fractionalKnapsack(items, n, knapsackCapacity);

    cout << "Total Profit = " << totalProfit << endl;

    return 0;
}
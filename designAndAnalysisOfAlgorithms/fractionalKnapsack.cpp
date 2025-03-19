#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool compare(struct Item, struct Item);
double fractionalKnapsack(int, struct Item[], int);

int main()
{
    cout << "-------------------- Fractional Knapsack --------------------" << endl;
    int W, n;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    struct Item arr[n];
    cout << "Enter the value and weight of each item: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i].value >> arr[i].weight;

    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);

    return 0;
}

bool compare(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}
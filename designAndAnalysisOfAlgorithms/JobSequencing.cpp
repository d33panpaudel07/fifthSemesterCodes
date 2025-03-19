#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed before or on deadline
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void JobSequencing(Job arr[], int n)
{
    sort(arr, arr + n, compare);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;
    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << "Following is the maximum profit sequence of jobs: ";
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
    cout << endl;
    cout << "Totatl Profit: " << totalProfit << endl;
}

int main()
{
    cout << "-------------------- Job Sequencing --------------------" << endl;
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter job details (id, deadline, profit) for each job:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Job " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> arr[i].id;
        cout << "Deadline: ";
        cin >> arr[i].deadline;
        cout << "Profit: ";
        cin >> arr[i].profit;
    }

    JobSequencing(arr, n);

    return 0;
}
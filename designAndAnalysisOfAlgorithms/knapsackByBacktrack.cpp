#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
    int weight;
    int profit;
    Node *takeWt;
    Node *skipWt;

public:
    Node() : weight(0), profit(0), takeWt(nullptr), skipWt(nullptr) {}
    Node(int wt, int pr) : weight(wt), profit(pr), takeWt(nullptr), skipWt(nullptr) {}

    int getWeight() const { return weight; }
    int getProfit() const { return profit; }
    Node *getTakeWt() const { return takeWt; }
    Node *getSkipWt() const { return skipWt; }

    void setTakeWt(Node *node) { takeWt = node; }
    void setSkipWt(Node *node) { skipWt = node; }
};

class KnapsackByBackTrack
{
private:
    std::vector<Node> object = {Node(2, 3), Node(3, 5), Node(4, 6), Node(5, 10)};
    int objIndex = 0;
    int maxWeight = 8;
    Node *current = nullptr;
    vector<int> bestSequence; // To store the optimal sequence

    Node *takeWeight(Node *parent)
    {
        if (objIndex >= object.size())
        {
            return nullptr;
        }

        int newWeight = parent->getWeight() + object[objIndex].getWeight();
        int newProfit = parent->getProfit() + object[objIndex].getProfit();

        if (newWeight > maxWeight)
        {
            return nullptr;
        }

        Node *newNode = new Node(newWeight, newProfit);
        objIndex++;
        newNode->setTakeWt(takeWeight(newNode));
        newNode->setSkipWt(skipWeight(newNode));
        objIndex--;
        return newNode;
    }

    Node *skipWeight(Node *parent)
    {
        if (objIndex >= object.size())
        {
            return nullptr;
        }

        Node *newNode = new Node(parent->getWeight(), parent->getProfit());
        objIndex++;
        newNode->setTakeWt(takeWeight(newNode));
        newNode->setSkipWt(skipWeight(newNode));
        objIndex--;
        return newNode;
    }

    // Modified helper function to find max profit and track sequence
    int findMaxProfit(Node *node, vector<int> &currentSequence, vector<int> &bestSequence, int &maxProfit)
    {
        if (node == nullptr)
        {
            return 0; // Null node has no profit
        }

        // If leaf node, evaluate its profit
        if (node->getTakeWt() == nullptr && node->getSkipWt() == nullptr)
        {
            int profit = node->getProfit();
            if (profit > maxProfit && node->getWeight() <= maxWeight)
            {
                maxProfit = profit;
                bestSequence = currentSequence; // Update best sequence
            }
            return profit;
        }

        // Recurse on take branch
        if (node->getTakeWt() != nullptr)
        {
            currentSequence.push_back(1); // Taking the item
            int takeProfit = findMaxProfit(node->getTakeWt(), currentSequence, bestSequence, maxProfit);
            currentSequence.pop_back(); // Backtrack
        }

        // Recurse on skip branch
        if (node->getSkipWt() != nullptr)
        {
            currentSequence.push_back(0); // Skipping the item
            int skipProfit = findMaxProfit(node->getSkipWt(), currentSequence, bestSequence, maxProfit);
            currentSequence.pop_back(); // Backtrack
        }

        return max(maxProfit, max(findMaxProfit(node->getTakeWt(), currentSequence, bestSequence, maxProfit),
                                  findMaxProfit(node->getSkipWt(), currentSequence, bestSequence, maxProfit)));
    }

public:
    void execute()
    {
        if (current == nullptr)
        {
            current = new Node(0, 0);
        }

        current->setTakeWt(takeWeight(current));
        current->setSkipWt(skipWeight(current));

        vector<int> currentSequence;
        int maxProfit = 0;
        bestSequence.resize(object.size(), 0); // Initialize with zeros
        int result = findMaxProfit(current, currentSequence, bestSequence, maxProfit);

        // Display results
        cout << "Maximum profit achievable: " << result << endl;
        cout << "Sequence of items (1 = take, 0 = skip): ";
        for (int i = 0; i < bestSequence.size(); i++)
        {
            cout << bestSequence[i] << " ";
        }
        cout << endl;

        // Verify weights and profits
        int totalWeight = 0, totalProfit = 0;
        for (int i = 0; i < bestSequence.size(); i++)
        {
            if (bestSequence[i] == 1)
            {
                totalWeight += object[i].getWeight();
                totalProfit += object[i].getProfit();
            }
        }
        cout << "Total weight: " << totalWeight << ", Total profit: " << totalProfit << endl;
    }

    void displayValues()
    {
        for (int i = 0; i < object.size(); i++)
        {
            cout << "Item " << i + 1 << " - Weight: " << object[i].getWeight()
                 << ", Profit: " << object[i].getProfit() << endl;
        }
    }
};

int main()
{
    KnapsackByBackTrack knapsack;
    cout << "Items available:" << endl;
    knapsack.displayValues();
    cout << "\nSolving knapsack problem with max weight 8...\n";
    knapsack.execute();
    return 0;
}
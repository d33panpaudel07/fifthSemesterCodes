#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

struct InputNode // for storing input characters and their frequencies
{
    char value;
    int frequency;

    // below is easy way to make constructors ╚(•⌂•)╝
    InputNode(char value, int frequency) : value(value), frequency(frequency) {}

    void getData()
    {
        cout << "Value: " << value << ", ";
        cout << "Frequency: " << frequency;
        return;
    }
};

struct Node // So Classes and Structures in Cpp are same with difference being
            //  that we cant use public, private, etc in Structures
{
    char alphabet;
    int freq; // Added frequency to the Huffman Node
    Node *left;
    Node *right;

    Node(char alphabet, int freq) : alphabet(alphabet), freq(freq), left(nullptr), right(nullptr) {} // Constructor
};

// Comparison to use in priority queue as we're building min-heap
struct Compare
{
    bool operator()(Node *l, Node *r)
    {
        return (l->freq > r->freq);
    }
};

// A map of type char as key and string as value it's like an object in java or
//  a dictionary in python apparently, this returns map containing Huffman Tree which looks like {"c":"string"}
map<char, string> buildHuffmanTree(vector<InputNode> &input)
// We take vector(known as dynamic array),
// InputNode is the node I created above
{
    // Node * tells pq that it has to store pointers to Node's instances
    // vector<Node *> tells pq that it has to use vector structure of type Node's
    //       pointers, so vector will hold pointers to Node
    //
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Insert nodes into the priority queue
    // auto allows compiler to adjust variable type automatically
    // not recommended and is a bad practice unless you'e a Javascript creep
    for (auto const &node : input)
    {
        pq.push(new Node(node.value, node.frequency));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('\0', left->freq + right->freq); // Internal node, frequency is sum
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    map<char, string> codes;
    function<void(Node *, string)> generateCodes =
        [&](Node *node, string code)
    {
        if (!node)
            return;

        if (node->alphabet != '\0')
        { // Leaf node (character)
            codes[node->alphabet] = code;
        }

        generateCodes(node->left, code + "0");
        generateCodes(node->right, code + "1");
    };

    generateCodes(pq.top(), "");

    return codes;
}

int main()
{
    cout << "--------------------Huffman Encoding--------------------" << endl;

    vector<InputNode> userInput;
    int n;

    cout << "Enter the number of characters: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char value;
        int frequency;
        cout << "Enter character " << i + 1 << " value: ";
        cin >> value;
        cout << "Enter character " << i + 1 << " frequency: ";
        cin >> frequency;
        userInput.push_back(InputNode(value, frequency));
    }

    for (auto &node : userInput)
    {
        node.getData();
        cout << endl;
    }

    map<char, string> codes = buildHuffmanTree(userInput);

    cout << "Huffman Codes:\n";
    for (auto const &[key, val] : codes)
    {
        cout << key << ": " << val << endl;
    }

    string input;
    cout << "Enter the string to encode: ";
    cin >> input;

    string encoded = "";
    for (char c : input)
    {
        encoded += codes[c];
    }
    cout << "Encoded string for '" << input << "': " << encoded << endl;
    return 0;
}
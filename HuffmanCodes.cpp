#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Function to build Huffman Tree and generate codes
Node* buildHuffmanTree(string text, unordered_map<char, string>& huffmanCode) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }
    
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    
    Node* root = pq.top();
    generateCodes(root, "", huffmanCode);
    return root;
}

// Function to encode text using Huffman Codes
string encode(string text, unordered_map<char, string>& huffmanCode) {
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }
    return encodedText;
}

// Function to decode text using Huffman Tree
string decode(Node* root, string encodedText) {
    string decodedText = "";
    Node* current = root;
    for (char bit : encodedText) {
        current = (bit == '0') ? current->left : current->right;
        if (!current->left && !current->right) {
            decodedText += current->ch;
            current = root;
        }
    }
    return decodedText;
}

int main() {
    string text = "huffman coding example";
    unordered_map<char, string> huffmanCode;
    Node* root = buildHuffmanTree(text, huffmanCode);
    
    string encodedText = encode(text, huffmanCode);
    cout << "Encoded Text:\n" << encodedText << endl;
    
    string decodedText = decode(root, encodedText);
    cout << "Decoded Text:\n" << decodedText << endl;
    
    return 0;
}
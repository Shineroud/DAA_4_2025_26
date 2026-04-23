#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void encode(Node* root, string str, map<char, string> &huffmanCode) {
    if (root == nullptr) return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text) {
    map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        Node* node = new Node('\0', sum);
        node->left = left;
        node->right = right;
        pq.push(node);
    }

    Node* root = pq.top();

    map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "--- Huffman Codes ---\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }
    cout << "\nEncoded String: " << str << endl;
    
    double originalSize = text.length() * 8;
    double compressedSize = str.length();
    cout << "Original Size: " << originalSize << " bits" << endl;
    cout << "Compressed Size: " << compressedSize << " bits" << endl;
    cout << "Efficiency: " << (100 * (originalSize - compressedSize) / originalSize) << "%" << endl;
}

int main() {
    string text = "hqas";
    buildHuffmanTree(text);
    return 0;
}
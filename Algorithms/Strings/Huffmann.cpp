#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

struct cmp
{
	bool operator()(Node* l, Node* r)
	{
		return l->freq > r->freq;
	}
};

void Encode(Node* root, string str,unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	Encode(root->left, str + "0", huffmanCode);
	Encode(root->right, str + "1", huffmanCode);
}

void Decode(Node* root, int &idx, string str)
{
	if (root == nullptr) {
		return;
	}

	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	idx++;

	if (str[idx] =='0')
		Decode(root->left, idx, str);
	else
		Decode(root->right, idx, str);
}

void Huffman_Tree(string text)
{

	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}
	priority_queue<Node*, vector<Node*>, cmp> pq;

	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1)
	{
		Node *left = pq.top();
        pq.pop();

		Node *right = pq.top();
		pq.pop();

		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}


	Node* root = pq.top();

	unordered_map<char, string> huffmanCode;
	Encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}

	cout << "\nOriginal string was :\n" << text << '\n';

	string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	cout << "\nEncoded string is :\n" << str << '\n';

	int idx = -1;
	cout << "\nDecoded string is: \n";
	while (idx < (int)str.size() - 2) {
		Decode(root, idx, str);
	}
}

int main()
{
	string security = "Eerie eyes seen near lake.";

	Huffman_Tree(security);
	cout << "\n";

	return 0;
}

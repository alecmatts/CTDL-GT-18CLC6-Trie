#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "7_Node.h"
using namespace std;

class Trie
{
	friend class Node;
private:
	Node* Root;
public:
	Trie();
	~Trie() {}

	Node* getRoot();

	void Insert(string data); 

	void TraversalTree(Node* Root, string& Data, string& CurrentString, vector<string>& WordList, int DataLength);
};

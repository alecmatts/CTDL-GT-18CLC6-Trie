#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class Trie
{
	friend class Node;
private:
	Node* Root;
public:
	Trie();
	~Trie() {}

	void Insert(string data); 
	bool Search(string data);
};
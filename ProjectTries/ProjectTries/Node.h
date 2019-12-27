#pragma once
#include "Trie.h"

class Node 
{
	friend class Trie;
private:
	char Character;
	bool EndOfWord;

	Node* Children[26]; // Lowercase character ASCII code (97 - 122)
public:
	Node();
	~Node() {}

	void setEndOfWord(bool LogicalValue);
	void setCharacter(char c);
};
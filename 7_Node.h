#pragma once
#include "7_Trie.h"

class Node 
{
	friend class Trie;
public:
	char Character;
	bool EndOfWord;

	Node* Children[26]; // Lowercase character ASCII code (97 - 122)
public:
	Node();
	~Node() {}

	void setEndOfWord(bool LogicalValue);
	void setCharacter(char c);

	bool isWord();
};
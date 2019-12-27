#include "Trie.h"

Trie::Trie()
{
	Root = new Node();
}

void Trie::Insert(string data)
{
	Node* temp = Root;

	for (size_t i = 0; i < data.length(); i++)
	{
		int ASCII = static_cast<int>(data[i]) - 97;
		
		if (temp->Children[ASCII] != nullptr)
			temp = temp->Children[ASCII];
		else
		{
			// Create new node
			temp->Children[ASCII] = new Node(); 
			temp = temp->Children[ASCII];

			//Insert char in new node
			temp->Character = data[i]; 
		}
	}
	temp->EndOfWord = true;
}

bool Trie::Search(string data) 
{
	Node* temp = Root;

	for (size_t i = 0; i < data.length(); i++) 
	{
		int ASCII = static_cast<int>(data[i]) - 97;

		temp = temp->Children[ASCII];

		if (temp == nullptr) 
			return false;
	}

	return temp->EndOfWord;
}
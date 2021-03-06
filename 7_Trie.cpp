#include "7_Trie.h"

Trie::Trie()
{
	Root = new Node();
}

Node* Trie::getRoot()
{
	return this->Root;
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

void Trie::TraversalTree(Node* Root, string& Data, string& CurrentString, vector<string>& ListOfWords, int DataLength)
{
	Node* Current = Root;

	if (Current->isWord() == true && CurrentString.length() >= 3)
	{
		ListOfWords.push_back(CurrentString);
		
		if (CurrentString.length() == DataLength) return;	
	}

	for (size_t i = 0; i < 26; i++)
	{
		if (Current->Children[i] != nullptr && 
		    Data.find(Current->Children[i]->Character) != -1 )
		{
			//string CurrentWord(1, Data[Data.find(Current->Children[i]->Character)]);
			// kiểu char sẽ chạy nhanh hơn
			char CurrentWord = Current->Children[i]->Character;
		
			CurrentString += CurrentWord;
			Data.erase(Data.find(CurrentWord), 1);

			(*this).TraversalTree(Current->Children[i], Data, CurrentString, ListOfWords, DataLength);

			CurrentString.pop_back();
			Data += CurrentWord;
		}
	}
}

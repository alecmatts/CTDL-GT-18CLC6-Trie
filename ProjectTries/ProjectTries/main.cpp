#include "Handle.h"

int main()
{
	Trie TrieTree = BuildTrie("Dic.txt");

	string data;
	cout << "Enter search query:" << endl;
	getline(cin, data); 

	data.erase(remove_if(data.begin(), data.end(), isspace), data.end());

	vector<string> WordList = generateWordList(TrieTree, data);
	WriteFile("output.txt", WordList);
	
	return 0;
}
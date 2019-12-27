#include "7_Handle.h"

int main()
{
	Trie TrieTree = BuildTrie("Dic.txt");

	string data = ReadFile("input.txt");

	vector<string> ListOfWOrds = generateListOfWOrds(TrieTree, data);

	WriteFile("output.txt", ListOfWOrds);
	
	return 0;
}

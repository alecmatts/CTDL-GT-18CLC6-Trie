#include "Handle.h"

int main()
{
	Trie TrieTree = BuildTrie("Dic.txt");

	string data = ReadFile("input.txt");

	vector<string> WordList = generateWordList(TrieTree, data);

	WriteFile("output.txt", WordList);
	
	return 0;
}
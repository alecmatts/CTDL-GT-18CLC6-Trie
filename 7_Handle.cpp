#include "7_Handle.h"

Trie BuildTrie(string FileName)
{
	Trie newTree;
	ifstream fin;
	fin.open(FileName);
	if (!fin.is_open())
	{
		cout << "Cannot open file to build." << endl;
		return newTree;
	}
	
	string data;

	while (!fin.eof()) {
		fin >> data;
		newTree.Insert(data);
	}

	fin.close();

	return newTree;
}

string ReadFile(string FileName)
{
	string data;
	ifstream fin;
	fin.open(FileName);
	if (!fin.is_open())
		return data;
	
	while (!fin.eof()) {
		string temp;
		fin >> temp;
		data.append(temp);
	}

	fin.close();

	return data;
}

vector<string> generateWordList(Trie Tree, string Data)
{
	vector<string> WordList;
	string CurrentString;	

	Tree.TraversalTree(Tree.getRoot(), Data, CurrentString, WordList, Data.length(), 3);

	return WordList;
}

void WriteFile(string FileName, vector<string> WordList)
{
	ofstream fout;
	fout.open(FileName);
	if (!fout.is_open())
	{
		cout << "Cannot open file to build." << endl;
		return;
	}

	fout << WordList.size() << endl;

	for (size_t i = 0; i < WordList.size(); i++) {
		fout << WordList[i] << endl;
	}

	fout.close();
}
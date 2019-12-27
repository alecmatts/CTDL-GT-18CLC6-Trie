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

vector<string> generateListOfWOrds(Trie Tree, string Data)
{
	vector<string> ListOfWOrds;
	string CurrentString;	

	Tree.TraversalTree(Tree.getRoot(), Data, CurrentString, ListOfWOrds, Data.length());

	return ListOfWOrds;
}

void WriteFile(string FileName, vector<string> ListOfWOrds)
{
	ofstream fout;
	fout.open(FileName);
	if (!fout.is_open())
	{
		cout << "Cannot open file to build." << endl;
		return;
	}

	fout << ListOfWOrds.size() << endl;

	for (size_t i = 0; i < ListOfWOrds.size(); i++) {
		fout << ListOfWOrds[i] << endl;
	}

	fout.close();
}

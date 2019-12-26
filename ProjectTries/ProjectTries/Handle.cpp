#include "Handle.h"

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

vector<string> findAllWordExist(Trie Tree, vector<string> Combination) {
	vector<string> WordList;

	for (size_t i = 0; i < Combination.size(); i++) {
		if (Tree.Search(Combination[i]))
			WordList.push_back(Combination[i]);
	}

	return WordList;
}

void Permutation(Trie Tree, vector<string> &WordList, string arr1, string arr2, int k, int r, int* temp)
{
	for (size_t i = 0; i < arr1.length(); i++)
	{
		if (temp[i] == 0)
		{
			arr2[k] = arr1[i];
			if (k == r - 1)
			{
				if (Tree.Search(arr2))
					WordList.push_back(arr2);
			}
			else
			{
				temp[i] = 1;
				Permutation(Tree, WordList, arr1, arr2, k + 1, r, temp);
				temp[i] = 0;
			}
		}
	}
}

vector<string> generateWordList(Trie Tree, string data)
{
	vector<string> WordList;
	int* temp = new int[data.length()]{ 0 };

	string arr = "";
	int r = 3;
	while (r <= data.length())
	{
		while (arr.length() < r) arr.append(" ");
		Permutation(Tree, WordList, data, arr, 0, r, temp);
		r++;
	}

	RemoveDuplicates(WordList);

	return WordList;
}

void RemoveDuplicates(vector<string> &WordList) { // O(n) complexity
	auto itr = WordList.begin();
	unordered_set<string> s;

	for (auto curr = WordList.begin(); curr != WordList.end(); ++curr) {
		if (s.insert(*curr).second)
			*itr++ = *curr;
	}

	WordList.erase(itr, WordList.end());
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
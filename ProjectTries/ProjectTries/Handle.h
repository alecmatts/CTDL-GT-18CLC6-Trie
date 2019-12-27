#pragma once
#include "Trie.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

Trie BuildTrie(string FileName);
string ReadFile(string FileName);
void Permutation(Trie Tree, vector<string> &WordList, string arr1, string arr2, int k, int r, int* temp);
vector<string> generateWordList(Trie Tree, string data);
void RemoveDuplicates(vector<string>& WordList);
void WriteFile(string FileName, vector<string> Wordlist);
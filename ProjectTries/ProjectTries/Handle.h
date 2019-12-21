#pragma once
#include "Trie.h"
#include <fstream>
#include <vector>
#include <algorithm>

Trie BuildTrie(string FileName);
void Permutation(Trie Tree, vector<string> &WordList, string arr1, string arr2, int k, int r, int* temp);
vector<string> generateWordList(Trie Tree, string data);
void WriteFile(string FileName, vector<string> Wordlist);
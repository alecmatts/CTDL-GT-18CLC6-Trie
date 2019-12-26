#pragma once
#include "Trie.h"
#include <fstream>
#include <vector>

Trie BuildTrie(string FileName);
string ReadFile(string FileName);
vector<string> generateWordList(Trie Tree, string data);
void WriteFile(string FileName, vector<string> Wordlist);
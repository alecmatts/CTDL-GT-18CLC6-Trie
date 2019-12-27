#pragma once
#include "7_Trie.h"
#include <fstream>
#include <vector>

Trie BuildTrie(string FileName);
string ReadFile(string FileName);
vector<string> generateListOfWOrds(Trie Tree, string data);
void WriteFile(string FileName, vector<string> ListOfWOrds);

#include "Node.h"

Node::Node()
{
	this->setCharacter('\0');
	this->setEndOfWord(false);

	for (int i = 0; i < 26; i++)
	{
		this->Children[i] = nullptr;
	}
}
void Node::setEndOfWord(bool LogicalValue) 
{ 
	this->EndOfWord = LogicalValue;
}

void Node::setCharacter(char c) 
{ 
	this->Character = c;
}

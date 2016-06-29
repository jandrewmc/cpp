#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

struct node
{
	unsigned long frequency;
	char value;
	node *leftChild;
	node *rightChild;
};

const int MAX_SIZE = 256;
string encTable[256];
node *root;

void inorder(node *curNode, string curStr)
{
	if (curNode != nullptr)
	{
		inorder(curNode->leftChild, curStr + "0");
		inorder(curNode->rightChild, curStr + "1");
		encTable[curNode->value] = curStr;
	}
}

void initializeFromFile(string filename)
{
	int treecount[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		treecount[i] = 0;

	ifstream myfile;

	myfile.open(filename);

	//count the number of occurences of the character
	char c;
	while (myfile.get(c)) treecount[c]++;

	myfile.close();

	//create a node for each character and set its value and frequency
	node *array[MAX_SIZE];
	for (int i = 0; i < 256; i++)
		array[i] = nullptr;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (treecount[i] != 0)
		{
			array[i] = new node();
			array[i]->value = i;
			array[i]->frequency = treecount[i];
			array[i]->leftChild = nullptr;
			array[i]->rightChild = nullptr;
		}
	}


	int arraySize = 2;
	while (arraySize != 1)
	{
		int maxFreq = 0;
		for (int i = 0; i < 256; i++)
		{
			if (array[i] != nullptr)
				if (array[i]->frequency > maxFreq) maxFreq = array[i]->frequency;
		}
		maxFreq++;

		int firstMinimum = maxFreq;
		int firstMinimumIndex = -1;
		for (int i = 0; i < 256; i++)
		{
			if (array[i] != nullptr && array[i]->frequency < firstMinimum)
			{
				firstMinimum = array[i]->frequency;
				firstMinimumIndex = i;
			}
		}

		int secondMinimum = maxFreq;
		int secondMinimumIndex = -1;
		for (int i = 0; i < 256; i++)
		{
			if (array[i] != nullptr && i != firstMinimumIndex && array[i]->frequency < secondMinimum)
			{
				secondMinimum = array[i]->frequency;
				secondMinimumIndex = i;
			}
		}

		node *parent = new node();

		parent->frequency = firstMinimum + secondMinimum;
		parent->leftChild = array[firstMinimumIndex];
		parent->rightChild = array[secondMinimumIndex];
		parent->value = 0;

		array[firstMinimumIndex] = nullptr;
		array[secondMinimumIndex] = parent;

		arraySize = 0;
		for (int i = 0; i < 256; i++)
		{
			if (array[i] != nullptr)
			{
				arraySize++;

				if (arraySize == 2) break;			
			}
		}
	}


	for (int i = 0; i < 256; i++)
	{
		if (array[i] != nullptr)
		{
			root = array[i];
		}
	}

	string curStr = "";

	inorder(root, curStr);
}	

void encode(string inputFilename, string outputFilename)
{
	ifstream myfile;
	myfile.open(inputFilename);

	ofstream out(outputFilename);

	char x;
	string buffer;	
	while (myfile.get(x)) 
	{
		buffer += encTable[x];
		while (buffer.length() >= 8)
		{
			char o = 0;
			for (int i = 0; i < 8; i++)
			{
				//de-asciitizes char
				char t = buffer.at(i) - 48;		
				o ^= t << (7 - i);	
			}
			out << o;
			buffer = buffer.substr(8, string::npos);
		}
	}

	myfile.close();
	out.close();
}

void decode(string inputFilename, string outputFilename)
{
	ifstream myfile;
	myfile.open("Shakespeare.enc");

	ofstream out("ShakespareDecoded.txt");

	char b;
	node *curNode = root;

	while(myfile.get(b))
	{
		for (int i = 7; i >= 0; i--)
		{
			if (b & (1 << i))
			{
				curNode = curNode->rightChild;	
			}
			else
			{
				curNode = curNode->leftChild;	
			}

			if (curNode->value != 0)
			{
				out << curNode->value;
				
				curNode = root;
			}
		}
	}
	out.close();
	myfile.close();
}

int main()
{
	time_t result = time(nullptr);

	initializeFromFile("Shakespeare.txt");
	encode("Shakespeare.txt", "Shakespeare.enc");
	decode("Shakespeare.enc", "ShakespeareDecoded.txt");

	cout << "Run time: " << time(nullptr) - result << endl;
}

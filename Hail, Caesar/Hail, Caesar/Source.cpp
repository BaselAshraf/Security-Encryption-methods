#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int find (char a[], char value)
{
	for (int i = 0 ; i < 26; i++)
	{
		if (a[i]==value) return i;
	}
}

int main()
{
	int key;
	again: cin >> key; 

	if (key <0 || key >99999999999) 
	{
		cout  << "Enter right key!" << endl; 
		goto again;
	}

	cin.ignore();

	string input;
	getline(cin, input);
	vector<char> Ci;
	
	char alpha[26];
	int First=65;
	for (int y = 0; y < 26; y++)
	{
		alpha[y]= (char)First;
		First++;
	}

	for (int i=0; i<input.length(); i++)
	{		
		int x;
		x= find(alpha,input[i]) + key;

		if (x > 25) { x = x % 26; }

		Ci.push_back( alpha[x]); 
	}
	for (int k=0; k<Ci.size();k++)
	{
		cout << Ci[k];
	}
	cout << endl;
	return 0;
}

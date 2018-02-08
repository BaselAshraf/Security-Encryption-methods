#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string TOUPPER (string Sm){
	string Kap;
	int temp=0;
	Kap=Sm;
	for (int i=0; i<Sm.length(); i++){
		if ((int)Sm[i]>=97){
		temp=(int)Sm[i] - 32;
		Kap[i]=(char)temp;}
		else{continue;}
	}
	return Kap;
}

template <class T>
string Int_to_String(T t, ios_base & (*f)(ios_base&))
{
  ostringstream oss;
  oss << f << t;
  return oss.str();
}

int main ()
{
	string Vernam;
	vector<char> Ci,temp;
	vector<int> ci;
	int First=65;
	for (int y = 0; y < 26; y++)
	{
		temp.push_back((char)First);
		First++;
	}
	char Alpha[26][26];
	int l;
	for (int i=0; i<26; i++){
		l=i;
		for (int j=0; j<26; j++){
			if (l==26){l=0;}
			Alpha[i][j]=temp[l];
			l++;
		}
	}

	string key,KEY;
	//vector<char> KEY;
	again: cin >> key; 
	if (key.length() <1 || key.length() >10000) 
	{
		cout  << "Enter right key!" << endl; 
		goto again;
	}
	key = TOUPPER(key);

	KEY=key;
	cin.ignore();

	string input;
	agin: cin >> input;
	
	if (input.length() <1 || input.length() >10000) 
	{
		cout  << "Enter right plaintext!" << endl; 
		goto agin;
	}
	input = TOUPPER(input);
	int Te=0, length=key.length();
	if (key.length() != input.length())
	{
		for (int i=0; i<(input.length()-length); i++)
		{
			if (Te >= length) {Te = 0;}
			KEY += key[Te];
			Te++;
		}		
	}
	int In,Ke;
	for (int L=0; L<input.length(); L++){
		for (int k=0; k<26; k++)
		{
			if (temp[k]==KEY[L]) {Ke=k;}
			if (temp[k]==input[L]) {In=k;}
		}
		Ci.push_back(Alpha[Ke][In]);
	}
	cout << "Vigenere: ";
	for (int k=0; k<Ci.size();k++)
	{
		cout << Ci[k];
	}
	cout << endl;

	int in,ke;
	for (int sec=0; sec<input.length(); sec++)
	{
		in=(int)input[sec];
		ke=(int)KEY[sec];
		ci.push_back(in^ke);		 
	}
	 string temperory;
	cout << "Vernam: ";
	for (int k=0; k<ci.size();k++)
	{
		temperory = Int_to_String<int>(ci[k], hex);
		if (temperory.length() != 2) {temperory.insert(0, "0");}
		Vernam += temperory;
	}
	Vernam = TOUPPER(Vernam);
	cout << Vernam;
	cout << endl;

	cout << "One-Time Pad: ";
	if (key.length()==input.length())
	{ cout << "YES"; }
	else {cout << "NO";}
	cout << endl;

	//system("pause");
}
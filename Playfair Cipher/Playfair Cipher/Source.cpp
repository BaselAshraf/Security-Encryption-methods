#include<cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

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

int main()
{
	string key;
	vector<char> KEY;
	again: cin >> key; 
	if (key.length() <0 || key.length() >1000) 
	{
		cout  << "Enter right key!" << endl; 
		goto again;
	}
	key = TOUPPER(key);

	for (int y=0; y<key.length(); y++){
		if (key[y]!=key[y+1]){
			if (key[y] == 'J') {continue;}
			KEY.push_back(key[y]);}
		else {continue;}
	}
	char Mp = KEY[0];
	
	for (int y=1; y<KEY.size(); y++){
		for (int k=y; k<KEY.size(); k++){
		if (KEY[k]==Mp){KEY.erase(KEY.begin()+k);}
		}
		Mp=KEY[y];
	}

	cin.ignore();

	string input;
	cin >> input;
	
	if (input.length() <0 || input.length() >1000) 
	{
		cout  << "Enter right plaintext!" << endl; 
		goto again;
	}
	input = TOUPPER(input);
	for (int u=0; u<input.length(); u++){
		if (input[u] == 'J') {input[u]='I';}
	}
	for (int y=0; y<input.length(); y++){

		if (input[y]==input[y+1]) {
			if ((y%2) == 0){
				if (input[y]=='X') {
					input.insert((input.begin()+ y+1),'V');
					if ((input.length()%2) != 0 && input[input.length()]=='X') 
					{input.push_back('V');}
				}
				else {input.insert((input.begin()+ y+1),'X');
				if ((input.length()%2) != 0) {input.push_back('X');}
				}}
			else {if (input[y]=='X') {input.insert((input.begin()+ y+1),'V');
			if ((input.length()%2) != 0) {input.push_back('X');}}
			}
	}
		if (y==(input.length()-1)) {
			if ((input.length()%2) != 0) {input.push_back('X');}
		}
	}


	vector<char> Ci,temp;

	
	
	char Alpha[5][5];
	int First=65;
	for (int y = 0; y < 26; y++)
	{
		
		if ((char)First == 'J') {First++; continue;}
		temp.push_back((char)First);
		First++;
	}
	int l=0;
	for (int i =0; i<5; i++){
		for(int j=0; j<5; j++){
			if (l<=(KEY.size()-1)){
				Alpha[i][j] = KEY[l];
				for (int te=0; te<temp.size();te++){
					if (temp[te]==KEY[l]){
						temp.erase(temp.begin() + te);}}
			}
			else{
				if (temp.size()==0) continue;
				Alpha[i][j] = temp[0];
				temp.erase(temp.begin());
			}

			l++;
		}
	}
	int row1,row2,col1,col2;
	int In1=0,In2=1;
	for (int k=0; k<(input.length()/2); k++){
		for (int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if (input[In1]==Alpha[i][j]) {row1=i; col1=j;}
				if (input[In2]==Alpha[i][j]) {row2=i; col2=j;}
			}
		}

		if (row1==row2 || col1==col2){
			if (row1==row2)
			{
				if (col1<4)	col1+=1;
				else {col1=0;}
				if (col2<4) col2+=1;
				else {col2=0;}

				Ci.push_back(Alpha[row2][col1]);
				Ci.push_back(Alpha[row1][col2]);
			}
			
			if (col1==col2)
			{
				if (row1<4)	row1+=1;
				else {row1=0;}
				if (row2<4) row2+=1;
				else {row2=0;}

				Ci.push_back(Alpha[row1][col2]);
				Ci.push_back(Alpha[row2][col1]);
			}
			In1+=2;
			In2+=2;
			continue;
		}
		Ci.push_back(Alpha[row1][col2]);
		Ci.push_back(Alpha[row2][col1]);
		In1+=2;
		In2+=2;
	}
	
	for (int k=0; k<Ci.size();k++)
	{
		cout << Ci[k];
	}
	cout << endl;
	//system("pause");
	return 0;
}
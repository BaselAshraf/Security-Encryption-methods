#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>
#define mod 0x1B

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

int multi(int x, int y){
	int result =0;
	int Result[8];
	string temp1,temp2;
	int Temp=0;
	result = x ;
	Result[0]=x;
	for (int i=1; i<8; i++){
		result = result << 1;
		
		
		temp1 = bitset<9>(result).to_string();

		if (temp1[0]=='1'){
			for (int j=1; j<9; j++)
				temp2 += temp1[j];
			Temp = bitset<8>(temp2).to_ulong();
			result = Temp^mod;
		}
		temp1="";
		temp2="";
		Result[i]=result;
	}

	temp1 = bitset<8>(y).to_string();
	result=0;
	for (int i=7; i>=0; i--)
	{
		if (temp1[i]=='1')
			result=Result[7-i]^result;
	}

	return result;
}

void main(){
	int M,N;
	loop: cin >> hex >> M >> hex >> N;
	if (M > 255 || N>255)
		goto loop;
	int R1=0;
	int R2=0;
	
	R1= M^N;
	
	if (M>N){
		R2 = multi(M,N);
	}else{
		R2 = multi(N,M);
	}



	string r1 = Int_to_String(R1,hex);
	r1 = TOUPPER(r1);
	if (r1.length() != 2) {r1.insert(0, "0");}
	
	
	string r2 = Int_to_String(R2,hex);
	r2 = TOUPPER(r2);
	if (r2.length() != 2) {r2.insert(0, "0");}
	

	cout << r1 << " " << r2 << endl;
	//system("pause");
}

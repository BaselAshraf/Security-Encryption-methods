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
int b3=0;
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
int longdiv (int x, int y){
	string temp1,temp2,temp3,Result;
	int TEMP1,TEMP2;
	int first, sec,res=0;
	int result[12],Temporary[12]={0};
	for (int i=0; i<12; i++)
		result[i]=15;
	temp1=bitset<12>(y).to_string();
	temp2=bitset<12>(x).to_string();
	temp3=bitset<12>(0).to_string();
	Result=bitset<12>(0).to_string();

		for(int j=0; j<12; j++){
			if (temp1[j]=='1'){
				first=j;break;}}

		for(int j=0; j<12; j++){
			if (temp2[j]=='1'){
				sec=j;break;}}
		
	while((11-sec)>(11-first)){

		temp2=bitset<12>(x).to_string();

		for(int j=0; j<12; j++){
			if (temp2[j]=='1'){
				sec=j;break;}
		}

		int tem=0;
		if ((11-sec)>=(11-first)){
			tem = (11-sec)-(11-first);

		result[res]=tem;

		temp3[11-tem]='1';
		TEMP1=bitset<12>(temp3).to_ulong();
		if(temp2[3]=='1')
			x=multi(y,TEMP1);
		else{
			TEMP2=multi(y,TEMP1);
			x = x^TEMP2;}
		}
		temp3=bitset<12>(0).to_string();
		res++;
	}

	for (int i=0; i<12; i++)
	{
		if (result[i]!=15)
			Result[11-result[i]]='1';
	}


	b3=x;
	return bitset<12>(Result).to_ulong();




}
void main(){

	int M,N;
	int addative=0;
	int multiplicative=0;
	int T1=0, T2=0, T3=0;
	string add,m;
	
	cin >> hex >> M ;

	
	N=0x11B;


	addative=M;
	long long A1=1, A2=0, A3=N, B1=0, B2=1, B3=M, Q=0;


	while (B3!=0){
		if (B3==1)
		{
			multiplicative=B2;
			break;
		}

		Q=longdiv(A3,B3);
		T1=A1^multi(Q,B1);
		T2=A2^multi(Q,B2);
		T3=b3;
		A1=B1;
		A2=B2;
		A3=B3;
		B1=T1;
		B2=T2;
		B3=T3;
	}

	m=Int_to_String(multiplicative,hex);
	m= TOUPPER(m);
	if (m.length() != 2) {m.insert(0, "0");}

	add=Int_to_String(addative,hex);
	add= TOUPPER(add);
	if (add.length() != 2) {add.insert(0, "0");}

	cout  << add << " " << m << endl;
}
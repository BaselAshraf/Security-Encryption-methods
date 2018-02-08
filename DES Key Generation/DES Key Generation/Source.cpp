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

void main()
{
	unsigned long long in,outL1,outL2,outL3,outR1,outR2,outR3;

	cin >> hex >> in;

	string PC1_in;
	PC1_in = bitset<64>(in).to_string();

	int PC1[56]={ 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 
		51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 
		62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
	
	char PC1_out[56],SH_out[56],PC2_out[48];

	int PC2[48]={ 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 
		16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 
		39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };

	int Rotations[16]={ 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

	for (int i=0; i<56; i++){
		for(int j=0; j<64; j++){
			if (PC1[i]==(j+1))
				PC1_out[i]=PC1_in[j];

		}
	}

	char K_L[28], K_R[28], LSH_L[28], LSH_R[28];
	string SH[16],key[16];

	for (int i=0; i<28; i++)
	{
		K_L[i]=PC1_out[i];
	}
	int k=0;
	for (int i=28; i<56; i++)
	{
		K_R[k]=PC1_out[i];
		k++;
	}
	for (int round=0; round<16; round++){
		if (round>0){
			for (int i=0; i<28; i++)
			{
				K_L[i]=SH_out[i];
			}
			int k=0;
			for (int i=28; i<56; i++)
			{
				K_R[k]=SH_out[i];
				k++;
			}
		}
		for (int i=0; i<28; i++)
		{
			int bit=(i+Rotations[round])%28;
			LSH_L[i]=K_L[bit];
			LSH_R[i]=K_R[bit];
		}

		for (int i=0; i<28; i++)
		{
			SH_out[i]=LSH_L[i];
		}
		int k=0;
		for (int i=28; i<56; i++)
		{
			SH_out[i]=LSH_R[k];
			k++;
		}

		for (int i=0; i<48; i++){
			for(int j=0; j<56; j++){
				if (PC2[i]==(j+1))
					PC2_out[i]=SH_out[j];

			}
		}
		for(int i=0; i<56; i++){
			SH[round]+=SH_out[i];
		}
		for (int i=0; i<48; i++)
		{
			key[round]+=PC2_out[i];
		}
	}
	string KL1,KL2,KL3,KR1,KR2,KR3;
	for (int i=0; i<16; i++)
	{
		for (int z=0; z<8; z++)
		{
			KL1+=key[i][z];
		}
		for (int z=8; z<16; z++)
		{
			KL2+=key[i][z];
		}
		for (int z=16; z<24; z++)
		{
			KL3+=key[i][z];
		}
		for (int z=24; z<32; z++)
		{
			KR1+=key[i][z];
		}
		for (int z=32; z<40; z++)
		{
			KR2+=key[i][z];
		}
		for (int z=40; z<48; z++)
		{
			KR3+=key[i][z];
		}

		outL1 = bitset<8>(KL1).to_ulong();
		outL2= bitset<8>(KL2).to_ulong();
		outL3 = bitset<8>(KL3).to_ulong();
		outR1 = bitset<8>(KR1).to_ulong();
		outR2 = bitset<8>(KR2).to_ulong();
		outR3 = bitset<8>(KR3).to_ulong();

		string OutL1,OutL2,OutL3,OutR1,OutR2,OutR3;
		
		OutL1=Int_to_String(outL1,hex);
		OutL2=Int_to_String(outL2,hex);
		OutL3=Int_to_String(outL3,hex);
		OutL1=TOUPPER(OutL1);
		OutL2=TOUPPER(OutL2);
		OutL3=TOUPPER(OutL3);
		if (OutL1.length() != 2) {OutL1.insert(0, "0");}
		if (OutL2.length() != 2) {OutL2.insert(0, "0");}
		if (OutL3.length() != 2) {OutL3.insert(0, "0");}

		OutR1=Int_to_String(outR1,hex);
		OutR2=Int_to_String(outR2,hex);
		OutR3=Int_to_String(outR3,hex);
		OutR1=TOUPPER(OutR1);
		OutR2=TOUPPER(OutR2);
		OutR3=TOUPPER(OutR3);
		if (OutR1.length() != 2) {OutR1.insert(0, "0");}
		if (OutR2.length() != 2) {OutR2.insert(0, "0");}
		if (OutR3.length() != 2) {OutR3.insert(0, "0");}


		cout << hex << OutL1 << OutL2 << OutL3 << OutR1 << OutR2 << OutR3 << endl;
		KL1="";
		KR1="";
		KL2="";
		KR2="";
		KL3="";
		KR3="";
	}


}
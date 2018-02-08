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
#include <cstdlib>

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
string Key[16];
void Key_Generation(unsigned long long in)
{
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
	string SH[16];

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
			Key[round]+=PC2_out[i];
		}
	}



}



string S_box_funcion(unsigned long long in){
	string In1 = bitset<48>(in).to_string();
	string in2, row, column, out, result;
	int Row, Column,Out;

	int S1[4][16]={{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
				{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
				{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
				{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};

	int S2[4][16]={{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
				{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
				{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
				{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}};

	int S3[4][16]={{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
				{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
				{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
				{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}};
	
	int S4[4][16]={{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
				{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
				{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
				{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}};
	
	int S5[4][16]={{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
				{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
				{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
				{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}};

	int S6[4][16]={{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
				{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
				{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
				{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}};

	int S7[4][16]={{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
				{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
				{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
				{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}};

	int S8[4][16]={{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
				{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
				{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
				{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};


	int temp=1;
	for (int i=0; i<48; i+=6)
	{
		in2=In1.substr(i,6);
		row = in2.substr(0,1)+in2.substr(5,1);
		column =  in2.substr(1,4);

		Row = stoi(row,0,2);
		Column = stoi(column,0,2);
		switch (temp){
			case 1:
				Out = S1[Row][Column];
				break;
			case 2:
				Out = S2[Row][Column];
				break;
			case 3:
				Out = S3[Row][Column];
				break;
			case 4:
				Out = S4[Row][Column];
				break;
			case 5:
				Out = S5[Row][Column];
				break;
			case 6:
				Out = S6[Row][Column];
				break;
			case 7:
				Out = S7[Row][Column];
				break;
			case 8:
				Out = S8[Row][Column];
				break;
			default:
				Out = 0;
				break;
		}
		temp++;
		out = bitset<4>(Out).to_string();
		result += out;
		row="";
		column="";
		out="";
		in2="";
	}

	return result;
}

void main()
{
	unsigned long long key, text, Eout_int, Pout_int, key_out, S_in, IP_L_int, Round_out_R, Round_out_L;
	unsigned long long Cipher;
	int N,type;
	cin >> hex >> key >> text;
	cin.ignore();
	cin >> dec >> N;

	//type 0 Encrypion 
	//type 1 Decrypion
	type=0;


	Key_Generation(key);
	Cipher=text;

	string enc_key[16],dec_key[16];


	for (int i=0; i<16; i++){
		enc_key[i]=Key[i];
	}
	int z=0;
	for (int i=15; i>=0; i--){
		dec_key[z]=Key[i];
		z++;
	}


	string IP_in, IIP_in, E_in,  P_in, E_Out, S_out, P_Out, IP_L_s, Round_Out_R, Round_Out_L;
	string rounds_out_R,rounds_out_L,cipher,ciphertext;
	int IP[64]={ 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 
		46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 
		9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };
	
	char IP_out[64],IIP_out[64],E_out[48], P_out[32];

	int IIP[64]={ 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 
		14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 
		35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };

	int E[48]={ 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 
		17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };

	int P[32]={ 16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 
		31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };
	
	
	char IP_L[32], IP_R[32], LSH_L[28], LSH_R[28];
	

	for (int n=0; n<N; n++){
		if (n>0)
		{
			text=Cipher;
			cipher="";
			IP_in="", IIP_in="";
		}
		IP_in = bitset<64>(text).to_string();


		//initial permutation IP
		for (int i=0; i<64; i++){
			for(int j=0; j<64; j++){
				if (IP[i]==(j+1))
					IP_out[i]=IP_in[j];

			}
		}

		for (int i=0; i<32; i++)
		{
			IP_L[i]=IP_out[i];
		}
		int k=0;
		for (int i=32; i<64; i++)
		{
			IP_R[k]=IP_out[i];
			k++;
		}
		for (int round=0; round<16; round++){

			if (round>0){
				for (int i=0; i<32; i++)
				{
					IP_L[i]=Round_Out_L[i];
				}
				for (int i=0; i<32; i++)
				{
					IP_R[i]=Round_Out_R[i];
				}
			}

			E_in="",  P_in="", E_Out="", S_out="", P_Out="", IP_L_s="", Round_Out_R="", Round_Out_L="";

			for (int i=0; i<32; i++){
				E_in += IP_R[i];
			}

			//expansion permutation E
			for (int i=0; i<48; i++){
				for(int j=0; j<32; j++){
					if (E[i]==(j+1))
						E_out[i]=E_in[j];

				}
			}

			for (int i=0; i<48; i++){
				E_Out += E_out[i];
			}
	

			Eout_int = stoull(E_Out,0,2);

			switch (type){
			
				case 0:
					key_out = stoull(enc_key[round],0,2); 
					break;
				
				case 1:
					key_out = stoull(dec_key[round],0,2); 
					break;
			}

			S_in = Eout_int ^ key_out;

			S_out = S_box_funcion(S_in);

			P_in = S_out;
		
			//permutation P
			for (int i=0; i<32; i++){
				for(int j=0; j<32; j++){
					if (P[i]==(j+1))
						P_out[i]=P_in[j];

				}
			}
		
			for (int i=0; i<32; i++){
				P_Out += P_out[i];
			}

			for (int i=0; i<32; i++){
				IP_L_s += IP_L[i];
			}

			IP_L_int = stoull(IP_L_s,0,2);
			Pout_int = stoull(P_Out,0,2);

			Round_out_R = IP_L_int ^ Pout_int;

			Round_Out_R = bitset<32>(Round_out_R).to_string();

			for (int i=0; i<32; i++){
				Round_Out_L += IP_R[i];
			}

			if (round==15){
				rounds_out_L=Round_Out_R;
				rounds_out_R=Round_Out_L;
			}

		}
	
		for (int i=0; i<32; i++)
		{
			IIP_in += rounds_out_L[i];
		}
		for (int i=0; i<32; i++)
		{
			IIP_in += rounds_out_R[i];
		}

		//inverse initial permutation IIP
		for (int i=0; i<64; i++){
			for(int j=0; j<64; j++){
				if (IIP[i]==(j+1))
					IIP_out[i]=IIP_in[j];

			}
		}

		for (int i=0; i<64; i++){
			cipher += IIP_out[i];
		}

		Cipher = stoull(cipher,0,2);

	}


	
	ciphertext = Int_to_String(Cipher,hex);
	ciphertext = TOUPPER(ciphertext);
	if (ciphertext.length() != 16) {
		int tem = (16-ciphertext.length());
		for (int i=0; i<tem; i++)
			ciphertext.insert(0, "0");
	}
	cout << hex << ciphertext << endl;
	//system("pause");
}
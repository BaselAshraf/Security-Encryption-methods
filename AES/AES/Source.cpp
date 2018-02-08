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
string Key[11];

string substitution (string in){
	string out ;

	string AES_S_box[16][16]={
		{"63","7C","77","7B","F2","6B","6F","C5","30","01","67","2B","FE","D7","AB","76"},//0
		{"CA","82","C9","7D","FA","59","47","F0","AD","D4","A2","AF","9C","A4","72","C0"},//1
		{"B7","FD","93","26","36","3F","F7","CC","34","A5","E5","F1","71","D8","31","15"},//2
		{"04","C7","23","C3","18","96","05","9A","07","12","80","E2","EB","27","B2","75"},//3
		{"09","83","2C","1A","1B","6E","5A","A0","52","3B","D6","B3","29","E3","2F","84"},//4
		{"53","D1","00","ED","20","FC","B1","5B","6A","CB","BE","39","4A","4C","58","CF"},//5
		{"D0","EF","AA","FB","43","4D","33","85","45","F9","02","7F","50","3C","9F","A8"},//6
		{"51","A3","40","8F","92","9D","38","F5","BC","B6","DA","21","10","FF","F3","D2"},//7
		{"CD","0C","13","EC","5F","97","44","17","C4","A7","7E","3D","64","5D","19","73"},//8
		{"60","81","4F","DC","22","2A","90","88","46","EE","B8","14","DE","5E","0B","DB"},//9
		{"E0","32","3A","0A","49","06","24","5C","C2","D3","AC","62","91","95","E4","79"},//A
		{"E7","C8","37","6D","8D","D5","4E","A9","6C","56","F4","EA","65","7A","AE","08"},//B
		{"BA","78","25","2E","1C","A6","B4","C6","E8","DD","74","1F","4B","BD","8B","8A"},//C
		{"70","3E","B5","66","48","03","F6","0E","61","35","57","B9","86","C1","1D","9E"},//D
		{"E1","F8","98","11","69","D9","8E","94","9B","1E","87","E9","CE","55","28","DF"},//E
		{"8C","A1","89","0D","BF","E6","42","68","41","99","2D","0F","B0","54","BB","16"}//F
	};

	unsigned int in1,in2;
	stringstream ss;

	ss << hex << in[0];
	ss >> in1;
	
	stringstream ss1;

	
	ss1 << hex << in[1];
	ss1 >> in2;

	out = AES_S_box[in1][in2];
	



	return out;
}

string Isubstitution (string in){
	string out ;

	string AES_S_box[16][16]={
		{"63","7C","77","7B","F2","6B","6F","C5","30","01","67","2B","FE","D7","AB","76"},//0
		{"CA","82","C9","7D","FA","59","47","F0","AD","D4","A2","AF","9C","A4","72","C0"},//1
		{"B7","FD","93","26","36","3F","F7","CC","34","A5","E5","F1","71","D8","31","15"},//2
		{"04","C7","23","C3","18","96","05","9A","07","12","80","E2","EB","27","B2","75"},//3
		{"09","83","2C","1A","1B","6E","5A","A0","52","3B","D6","B3","29","E3","2F","84"},//4
		{"53","D1","00","ED","20","FC","B1","5B","6A","CB","BE","39","4A","4C","58","CF"},//5
		{"D0","EF","AA","FB","43","4D","33","85","45","F9","02","7F","50","3C","9F","A8"},//6
		{"51","A3","40","8F","92","9D","38","F5","BC","B6","DA","21","10","FF","F3","D2"},//7
		{"CD","0C","13","EC","5F","97","44","17","C4","A7","7E","3D","64","5D","19","73"},//8
		{"60","81","4F","DC","22","2A","90","88","46","EE","B8","14","DE","5E","0B","DB"},//9
		{"E0","32","3A","0A","49","06","24","5C","C2","D3","AC","62","91","95","E4","79"},//A
		{"E7","C8","37","6D","8D","D5","4E","A9","6C","56","F4","EA","65","7A","AE","08"},//B
		{"BA","78","25","2E","1C","A6","B4","C6","E8","DD","74","1F","4B","BD","8B","8A"},//C
		{"70","3E","B5","66","48","03","F6","0E","61","35","57","B9","86","C1","1D","9E"},//D
		{"E1","F8","98","11","69","D9","8E","94","9B","1E","87","E9","CE","55","28","DF"},//E
		{"8C","A1","89","0D","BF","E6","42","68","41","99","2D","0F","B0","54","BB","16"}//F
	};
	unsigned int in1,in2;

	for (int i=0; i<16; i++){
		for (int j=0; j<16; j++){
			if (AES_S_box[i][j]==in)
			{
				in1=i;
				in2=j;
			}
		}
	}


	
	

	out = Int_to_String(in1,hex) + Int_to_String(in2,hex);
	out = TOUPPER(out);



	return out;
}


string g_generation(string key, int round){
	string temp1[4],temp2[4],temp3[4],temp4[4];
	int k=0;
	for (int i=0; i<8; i+=2)
	{
		temp1[k]=key.substr(i,2);
		k++;
	}

	temp2[0] = temp1[1];
	temp2[1] = temp1[2];
	temp2[2] = temp1[3];
	temp2[3] = temp1[0];

	temp3[0] = substitution(temp2[0]);
	temp3[1] = substitution(temp2[1]);
	temp3[2] = substitution(temp2[2]);
	temp3[3] = substitution(temp2[3]);

	string RCON[10]={"01", "02", "04", "08", "10", "20", "40", "80", "1B", "36"};
	int RC;
	stringstream ss1;
	ss1 << hex << RCON[round];
	ss1 >> RC;

	int Temp3;
	stringstream ss;
	ss << hex << temp3[0];
	ss >> Temp3;

	int result = RC ^ Temp3;

	temp4[0] = Int_to_String(result,hex);
	temp4[0] = TOUPPER(temp4[0]);
	if (temp4[0].length() != 2) {temp4[0].insert(0,"0");}

	temp4[1] = temp3[1];
	temp4[2] = temp3[2];
	temp4[3] = temp3[3];

	string out = temp4[0].substr(0,2) + temp4[1].substr(0,2) + temp4[2].substr(0,2) + temp4[3].substr(0,2);

	return out;
}
void Key_Generation(string in)
{
	Key[0]=in;
	string key1[4],key2[4],temp;
	int k=0;
	for (int i=0; i<32; i+=8){
		key1[k]=in.substr(i,8);
		k++;
	}
	string g;

	unsigned int KEY1[4],KEY2[4],G;



	for (int round=0; round<10; round++){
		
		g = g_generation(key1[3],round);

		for (int i=0; i<4; i++){
			stringstream ss;
			ss << hex << key1[i];
			ss >> KEY1[i];
		}
	
		stringstream ss1;
		ss1 << hex << g;
		ss1 >> G;

		KEY2[0] = KEY1[0] ^ G;
		KEY2[1] = KEY1[1] ^ KEY2[0];
		KEY2[2] = KEY1[2] ^ KEY2[1];
		KEY2[3] = KEY1[3] ^ KEY2[2];


		for (int i=0; i<4; i++){
			key2[i] = Int_to_String(KEY2[i],hex);
			key2[i] = TOUPPER(key2[i]);
			if (key2[i].length() != 8) {
				int tem = (8-key2[i].length());
				for (int j=0; j<tem; j++)
					key2[i].insert(0,"0");}
		}
		
		
		temp = key2[0].substr(0,8) + key2[1].substr(0,8) + key2[2].substr(0,8) + key2[3].substr(0,8);

		Key[round+1] = temp;
		for (int i=0; i<4; i++){
			key1[i] = key2[i];
			key2[i]="";
		}
		
		
	}




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

string mixcolumns(string in[16], int type) {
	//type 0 for encryption
	//type 1 for decryption
	int mix[16];
	switch (type){
	case 0:
		mix[0]=2, mix[1]=1, mix[2]=1, mix[3]=3,
		mix[4]=3, mix[5]=2, mix[6]=1, mix[7]=1,
		mix[8]=1, mix[9]=3, mix[10]=2, mix[11]=1,
		mix[12]=1, mix[13]=1, mix[14]=3, mix[15]=2;
		break;
	case 1:
		mix[0]=14, mix[1]=9, mix[2]=13, mix[3]=11,
		mix[4]=11, mix[5]=14, mix[6]=9, mix[7]=13,
		mix[8]=13, mix[9]=11, mix[10]=14, mix[11]=9,
		mix[12]=9, mix[13]=13, mix[14]=11, mix[15]=14;
		break;
	}

	int IN[16], OUT[16];
	string out[16],result;

	for (int i=0; i<16; i++){
		stringstream ss;
		ss << hex << in[i];
		ss >> IN[i];
	}

	

	OUT[0] = multi(mix[0], IN[0]) ^ multi(mix[4], IN[1]) ^ multi(mix[8], IN[2]) ^ multi(mix[12], IN[3]); // 0
	OUT[1] = multi(mix[1], IN[0]) ^ multi(mix[5], IN[1]) ^ multi(mix[9], IN[2]) ^ multi(mix[13], IN[3]); // 1
	OUT[2] = multi(mix[2], IN[0]) ^ multi(mix[6], IN[1]) ^ multi(mix[10], IN[2]) ^ multi(mix[14], IN[3]); // 2
	OUT[3] = multi(mix[3], IN[0]) ^ multi(mix[7], IN[1]) ^ multi(mix[11], IN[2]) ^ multi(mix[15], IN[3]); // 3

	OUT[4] = multi(mix[0], IN[4]) ^ multi(mix[4], IN[5]) ^ multi(mix[8], IN[6]) ^ multi(mix[12], IN[7]); // 4
	OUT[5] = multi(mix[1], IN[4]) ^ multi(mix[5], IN[5]) ^ multi(mix[9], IN[6]) ^ multi(mix[13], IN[7]); // 5
	OUT[6] = multi(mix[2], IN[4]) ^ multi(mix[6], IN[5]) ^ multi(mix[10], IN[6]) ^ multi(mix[14], IN[7]); // 6
	OUT[7] = multi(mix[3], IN[4]) ^ multi(mix[7], IN[5]) ^ multi(mix[11], IN[6]) ^ multi(mix[15], IN[7]); // 7

	OUT[8] = multi(mix[0], IN[8]) ^ multi(mix[4], IN[9]) ^ multi(mix[8], IN[10]) ^ multi(mix[12], IN[11]); // 8
	OUT[9] = multi(mix[1], IN[8]) ^ multi(mix[5], IN[9]) ^ multi(mix[9], IN[10]) ^ multi(mix[13], IN[11]); // 9
	OUT[10] = multi(mix[2], IN[8]) ^ multi(mix[6], IN[9]) ^ multi(mix[10], IN[10]) ^ multi(mix[14], IN[11]); // 10
	OUT[11] = multi(mix[3], IN[8]) ^ multi(mix[7], IN[9]) ^ multi(mix[11], IN[10]) ^ multi(mix[15], IN[11]); // 11

	OUT[12] = multi(mix[0], IN[12]) ^ multi(mix[4], IN[13]) ^ multi(mix[8], IN[14]) ^ multi(mix[12], IN[15]); // 12
	OUT[13] = multi(mix[1], IN[12]) ^ multi(mix[5], IN[13]) ^ multi(mix[9], IN[14]) ^ multi(mix[13], IN[15]); // 13
	OUT[14] = multi(mix[2], IN[12]) ^ multi(mix[6], IN[13]) ^ multi(mix[10], IN[14]) ^ multi(mix[14], IN[15]); // 14
	OUT[15] = multi(mix[3], IN[12]) ^ multi(mix[7], IN[13]) ^ multi(mix[11], IN[14]) ^ multi(mix[15], IN[15]); // 15


	for (int i=0; i<16; i++){
		out[i] = Int_to_String(OUT[i],hex);
		out[i] = TOUPPER(out[i]);
		if (out[i].length() != 2) {out[i].insert(0,"0");}
	}

	for (int i=0; i<16; i++){
		result += out[i].substr(0,2);
	}

	return result;
}






void main()
{
	string key, key1[4], text, text1[4], text2[16], out1[4], temp1, out2[16], out3[16], temp2;
	unsigned int KEY[4], TEXT[4], OUT1[4];
	string Cipher;
	int N,type;
	cin >> key >> text;
	cin.ignore();
	cin >> dec >> N;

	//type 0 Encrypion 
	//type 1 Decrypion
	type=1;


	

	Key_Generation(key);
	Cipher=text;

	string enc_key[11],dec_key[11],ciphertext;
	

	for (int i=0; i<11; i++){
		enc_key[i]=Key[i];
	}
	int z=0;
	for (int i=10; i>=0; i--){
		dec_key[z]=Key[i];
		z++;
	}
	for (int n=0; n<N; n++){
		text = Cipher;
		for (int round=0; round<11; round++){
		
			if (round == 0){
				int k=0;
				for (int i=0; i<32; i+=8){
					switch (type){
					case 0:
						key1[k]=enc_key[round].substr(i,8);
						break;
					case 1:
						key1[k]=dec_key[round].substr(i,8);
						break;
					}
					k++;
				}

				k=0;
				for (int i=0; i<32; i+=8){
					text1[k]=text.substr(i,8);
					k++;
				}

				for (int i=0; i<4; i++){
					stringstream ss;
					ss << hex << key1[i];
					ss >> KEY[i];
				}

				for (int i=0; i<4; i++){
					stringstream ss;
					ss << hex << text1[i];
					ss >> TEXT[i];
				}

				for (int i=0; i<4; i++){
					OUT1[i] = KEY[i] ^ TEXT[i];
				}

				for (int i=0; i<4; i++){
					out1[i] = Int_to_String(OUT1[i],hex);
					out1[i] = TOUPPER(out1[i]);
					if (out1[i].length() != 8) {
						int tem = (8-out1[i].length());
						for (int j=0; j<tem; j++)
							out1[i].insert(0,"0");}
				}

				temp1 = out1[0].substr(0,8) + out1[1].substr(0,8) + out1[2].substr(0,8) + out1[3].substr(0,8);
				continue;
			}

			text = temp1;
			//substitution
			int k=0;
			for (int i=0; i<32; i+=2){
				text2[k]=text.substr(i,2);
				k++;
			}

			for (int i=0; i<16; i++)
			{
				switch (type){
				case 0:
					out2[i] = substitution(text2[i]);
					break;
				case 1:
					out2[i] = Isubstitution(text2[i]);
					break;
				}
			}

			//shift rows
			switch (type){
			case 0:
				out3[0]=out2[0];  out3[4]=out2[4];  out3[8]=out2[8];  out3[12]=out2[12];
				out3[1]=out2[5];  out3[5]=out2[9];  out3[9]=out2[13]; out3[13]=out2[1];
				out3[2]=out2[10]; out3[6]=out2[14]; out3[10]=out2[2]; out3[14]=out2[6];
				out3[3]=out2[15]; out3[7]=out2[3];  out3[11]=out2[7]; out3[15]=out2[11];
				break;
			case 1:
				out3[0]=out2[0];  out3[4]=out2[4];  out3[8]=out2[8];  out3[12]=out2[12];
				out3[1]=out2[13];  out3[5]=out2[1];  out3[9]=out2[5]; out3[13]=out2[9];
				out3[2]=out2[10]; out3[6]=out2[14]; out3[10]=out2[2]; out3[14]=out2[6];
				out3[3]=out2[7]; out3[7]=out2[11];  out3[11]=out2[15]; out3[15]=out2[3];
				break;
			}

			text = ""; 
			if (round<10){
				text = mixcolumns(out3, type);}
			else {
				for (int i=0; i<16; i++){
					text += out3[i]; 
				}
			}

			//add round key
			k=0;
				for (int i=0; i<32; i+=8){
					switch (type)
					{
						case 0:
							key1[k]=enc_key[round].substr(i,8);
							break;
						case 1:
							key1[k]=dec_key[round].substr(i,8);
							break;
					}
					k++;
				}


				k=0;
				for (int i=0; i<32; i+=8){
					text1[k]=text.substr(i,8);
					k++;
				}

				switch (type){
				case 0:
					for (int i=0; i<4; i++){
						stringstream ss;
						ss << hex << key1[i];
						ss >> KEY[i];
					}

					for (int i=0; i<4; i++){
						stringstream ss;
						ss << hex << text1[i];
						ss >> TEXT[i];
					}

					for (int i=0; i<4; i++){
						OUT1[i] = KEY[i] ^ TEXT[i];
					}
					break;
				case 1:
					if (round < 10){
						string key_dec, key_dec_1[16];
						for (int i=0; i<4; i++){
							key_dec += key1[i]; }

						int k=0;
						for (int i=0; i<32; i+=2){
							key_dec_1[k]=key_dec.substr(i,2);
							k++;
						}

						temp2 = mixcolumns(key_dec_1, type); 

						k=0;
						for (int i=0; i<32; i+=8){
							key1[k]=temp2.substr(i,8);
							k++;
						}

						for (int i=0; i<4; i++){
							stringstream ss;
							ss << hex << key1[i];
							ss >> KEY[i];
						}

						for (int i=0; i<4; i++){
							stringstream ss;
							ss << hex << text1[i];
							ss >> TEXT[i];
						}

						for (int i=0; i<4; i++){
							OUT1[i] = KEY[i] ^ TEXT[i];
						}
						break;
					}
					else {
						for (int i=0; i<4; i++){
							stringstream ss;
							ss << hex << key1[i];
							ss >> KEY[i];
						}

						for (int i=0; i<4; i++){
							stringstream ss;
							ss << hex << text1[i];
							ss >> TEXT[i];
						}

						for (int i=0; i<4; i++){
							OUT1[i] = KEY[i] ^ TEXT[i];
						}
						break;
					}
				}
			

				for (int i=0; i<4; i++){
					out1[i] = Int_to_String(OUT1[i],hex);
					out1[i] = TOUPPER(out1[i]);
					if (out1[i].length() != 8) {
						int tem = (8-out1[i].length());
						for (int j=0; j<tem; j++)
							out1[i].insert(0,"0");}
				}

				temp1 = out1[0].substr(0,8) + out1[1].substr(0,8) + out1[2].substr(0,8) + out1[3].substr(0,8);
			
				text="";
				for (int i=0; i<4; i++){
					text1[i] = "";
					out1[i]= "";
				}

				for (int i=0; i<16; i++){
					text2[i] = "";
					out2[i]= "";
					out3[i]= "";
				}
				if (round == 10)
				{
					Cipher = temp1;
				}
		}

	}

	
	

	cout << Cipher << endl;
	system("pause");
}
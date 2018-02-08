#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void main(){

	int in1,in2;

	cin >> in1 >> in2;

	int temp;
	if (in2>in1)
	{
		temp=in1;
		in1=in2;
		in2=temp;
	}
	temp = in1 % in2;
	int result = 0;
	while ((temp != 0))
	{
		if (temp == 1){
			result=in2;
			break;
		}
		temp = in1 % in2;
		in1=in2;
		in2=temp;
		result=in1;
	}
	cout << result<<endl;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Node
{
public:
	char data;
	Node* left;
	Node* right;

public:
	Node()
	{
		data = 'a';
		left = NULL;
		right = NULL;
	}
};
Node Array1[26];
Node Array2[26];
Node Array3[26];
Node Array4[26];
Node Array5[26];
Node Array6[26];
Node Array7[26];
Node Keyboard[26];
Node Lampboard[26];
void keyboard()
{
	for (int i = 0; i < 26; i++)
	{
		Keyboard[i].data = 65 + i;//65 = A
	}
}
void lampboard()
{
	for (int i = 0; i < 26; i++)
	{
		Lampboard[i].data = 65 + i;
	}
}
int InitializeKeyBoard(char a)
{
	Node x1;
	for (int k = 0; k < 26; k++)
	{
		if (Keyboard[k].data == a)
		{
			x1 = Keyboard[k]; return k;
		}
	}
}
Node InitializeLampBoard(int a)
{
	Node x1;
	x1 = Lampboard[a]; 
	return x1;
}
void InitializeRotor1()
{

	for (int i = 0; i < 26; i++)
	{
		Array1[i].data = 65 + i;
	}

	for (int i = 0; i < 26; i++)
	{
		Array2[i].data = 65 + i;
	}
	//Building rotor's internal structure
	int i = 0; int j = 25;
	while ((i<26) && (j>-1))
	{
		Array1[i].left = &(Array2[j]);
		i++; j--;
	}
	//reverse path
	int i2 = 0; int j2 = 25;
	while ((i2<26) && (j2>-1))
	{
		Array2[i2].right = &(Array1[j2]);
		i2++; j2--;
	}

}
int Forward_R1(int a)
{
	Node x1;
	x1 = Array1[a];
	for (int k = 0; k < 26; k++)
	{
		if (x1.left == &(Array2[k]))
		{
			return k; 
		}
	}
}
void InitializeRotor2()
{

	for (int i = 0; i < 26; i++)
	{
		Array3[i].data = 65 + i;
	}

	for (int i = 0; i < 26; i++)
	{
		Array4[i].data = 65 + i;
	}
	//Building rotor's internal structure
	int i = 0; int j = 25;
	while ((i<26) && (j>-1))
	{
		Array3[i].left = &(Array4[j]);
		i++; j--;
	}
	//reverse path
	int i2 = 0; int j2 = 25;
	while ((i2<26) && (j2>-1))
	{
		Array4[i2].right = &(Array3[j2]);
		i2++; j2--;
	}

}
int Forward_R2(int a)
{
	Node x1;
	x1 = Array3[a];
	for (int k = 0; k < 26; k++)
	{
		if (x1.left == &(Array4[k]))
		{
			return k; 
		}
	}
}
void InitializeRotor3()
{

	for (int i = 0; i < 26; i++)
	{
		Array5[i].data = 65 + i;
	}

	for (int i = 0; i < 26; i++)
	{
		Array6[i].data = 65 + i;
	}
	//Building rotor's internal structure
	int i = 0; int j = 25;
	while ((i<26) && (j>-1))
	{
		Array5[i].left = &(Array6[j]);
		Array6[j].right = Array5[i].left;
		i++; j--;
	}
	//reverse path
	int i2 = 0; int j2 = 25;
	while ((i2<26) && (j2>-1))
	{
		Array6[i2].right = &(Array5[j2]);
		i2++; j2--;
	}

}
int Forward_R3(int a)
{
	Node x1;
	x1 = Array5[a];
	for (int k = 0; k < 26; k++)
	{
		if (x1.left == &(Array6[k]))
		{
			return k; cout << "k value from Forward R3 " << k << endl;
		}
	}
}
int Reflector(int a)
{

	for (int i = 0; i < 26; i++)
	{
		Array7[i].data = 65 + i;
	}
	//Building reflector's internal structure
	//INTERNAL STRUCTURE
	Array7[0].left = &(Array7[2]); Array7[2].left = &(Array7[0]);
	Array7[1].left = &(Array7[4]); Array7[4].left = &(Array7[1]);
	Array7[3].left = &(Array7[6]); Array7[6].left = &(Array7[3]); 
	Array7[5].left = &(Array7[9]); Array7[9].left = &(Array7[5]);
	Array7[7].left = &(Array7[8]); Array7[8].left = &(Array7[7]);
	Array7[10].left = &(Array7[15]); Array7[15].left = &(Array7[10]);
	Array7[11].left = &(Array7[18]); Array7[18].left = &(Array7[11]);
	Array7[12].left = &(Array7[14]); Array7[14].left = &(Array7[12]);
	Array7[13].left = &(Array7[16]); Array7[16].left = &(Array7[13]);
	Array7[17].left = &(Array7[25]); Array7[25].left = &(Array7[17]);
	Array7[19].left = &(Array7[22]); Array7[22].left = &(Array7[19]);
	Array7[20].left = &(Array7[24]); Array7[24].left = &(Array7[20]);
	Array7[21].left = &(Array7[23]); Array7[23].left = &(Array7[21]);
	Node x1;
	x1 = Array7[a];
	for (int k = 0; k < 26; k++)
	{
		if (&(Array7[k]) == x1.left)
		{
			return k;
		}
	}

}
int Backward_R3(int a)
{
	Node x1;
	x1 = Array6[a];
	for (int k = 0; k < 26; k++)
	{
		if (x1.right == &(Array5[k]))
		{
			return k; 
		}
	}
}
int Backward_R2(int a)
{
	Node x1;
	x1 = Array4[a];
	for (int k = 0; k < 26; k++)
	{
		if (x1.right == &(Array3[k]))
		{
			return k;
		}
	}
}
int Backward_R1(int a)
{
	Node x1;
	x1 = Array2[a];
	for (int k = 0; k < 26; k++)
	{
		if (x1.right == &(Array1[k]))
		{
			return k; 
		}
	}
}
char CIPHER(char X, int spin,int spin2,int spin3)
{
	int K = InitializeKeyBoard(X);
	int val_out = K + spin;
	if (val_out < 26)
	{
		K = val_out;
	}
	else
	{
		K = val_out - 26;
	}
	int F1 = Forward_R1(K);
	int val_out_r2 = F1 + spin2;
	if (val_out_r2 < 26)
	{
		F1 = val_out_r2;
	}
	else
	{
		F1 = val_out_r2 - 26;
	}
	int F2 = Forward_R2(F1);
	int val_out_R3 = F2 + spin3;
	if (val_out_R3 < 26)
	{
		F2 = val_out_R3;
	}
	else
	{
		F2 = val_out_R3 - 26;
	}
	int F3 = Forward_R3(F2);
	int R = Reflector(F3);
	int val_out_RF = R + spin3;
	if (val_out_RF < 26)
	{
		R = val_out_RF;
	}
	else
	{
		R = val_out_RF - 26;
	}
	int B3 = Backward_R3(R);
	int val_out_b3 = B3 + spin2;
	if (val_out_b3 < 26)
	{
		B3 = val_out_b3;
	}
	else
	{
		B3 = val_out_b3 - 26;
	}
	int B2 = Backward_R2(B3);
	int val_out2 = B2 + spin;
	if (val_out2 < 26)
	{
		B2 = val_out2;
	}
	else
	{
		B2 = val_out2 - 26;
	}
	int B1 = Backward_R1(B2);
	Node L = InitializeLampBoard(B1);
	char Result = L.data;
	return Result;
}
string removeSpaces(string str, int size)
{
	string str_without_spaces;
	for (int i = 0; i<size; i++)
	{
		if (str[i] != ' ')
		{
			str_without_spaces.push_back(str[i]);                       
		}
	}
	return str_without_spaces;
}
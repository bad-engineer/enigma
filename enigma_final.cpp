#include "enigma_header.h"
int main()
{
	bool again = 1;
	do
	{
		int spin;
		cout << "Enter the first rotor's spin" << endl;
		cin >> spin;
		if (spin > 25)
		{
			int scale = spin / 26;
			spin = spin -scale*26;
		}
		cout << "Enter the second rotor's spin" << endl;
		int spin2;
		cin >> spin2;
		if (spin2 > 25)
		{
			int scale = spin2 / 26;
			spin2 = spin2 - scale * 26;
		}
		cout << "Enter the third rotor's spin" << endl;
		int spin3;
		cin >> spin3;
		if (spin3 > 25)
		{
			int scale = spin3 / 26;
			spin3 = spin3 - scale * 26;
		}
		cout << "Enter the word to encode" << endl << endl;
		keyboard();
		lampboard();
		InitializeRotor1();
		InitializeRotor2();
		InitializeRotor3();
		cin.ignore();
		string word;
		getline(cin, word);
		cout << word << endl;
		int size2 = word.size();
		word = removeSpaces(word, size2);
		cout << word << endl;
		for (auto & c : word) c = toupper(c);//converting to uppercase
		int size = word.size();
		vector<char> cipher;
		for (int k = 0; k < size; k++)
		{ 
			cipher.push_back(CIPHER(word[k], spin,spin2,spin3));
			spin++;
			if (spin > 25)
			{
				spin = 0;
				spin2++;
			}
			if (spin2 > 25)
			{
				spin2 = 0;
				spin3++;
			}
			if (spin3 > 25)
			{
				spin3 = 0;
				spin2 = 0;
				spin = 0;
			}
		}
		cout << endl << "CIPHER TEXT: " << endl << endl;
		for (int k = 0; k < size; k++)
		{
			cout << cipher[k] << " ";
		}
		cout << endl << endl;
	} while (again = 1);
	return 0;
}
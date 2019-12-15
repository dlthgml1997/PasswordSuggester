// CPP code to suggest strong password 
#include <bits/stdc++.h> 

using namespace std;

// make powerfull string 
string suggester(int l, int u, int d, int s, int t)
{
	string str;

	// all digits, lower case, uppercase and special characters 
	string num = "0123456789";
	string low_case = "abcdefghijklmnopqrstuvwxyz";
	string up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string spl_char = "@#$_()!";

	// position at which place a character 
	int pos = 0;

	// out_of_range를 방지하기 위해 str 0번째에 난수 삽입

	// generate random integer under 26 for indexing of a to z 
	str.insert(pos, 1, low_case[rand() % 26]);
	for (int i = 1; i < l; i++) {
		pos = rand() % str.length();
		str.insert(pos, 1, low_case[rand() % 26]);
	}

	// add upper case char
	for (int i = 0; i < u; i++) {
		pos = rand() % str.length();
		str.insert(pos, 1, up_case[rand() % 26]);
	}

	// add digit
	for (int i = 0; i < d; i++) {
		pos = rand() % str.length();
		str.insert(pos, 1, num[rand() % 10]);
	}

	// add special character
	for (int i = 0; i < s; i++) {
		pos = rand() % str.length();
		str.insert(pos, 1, spl_char[rand() % 7]);
	}

	return str;
}

int main()
{
	string suggest;

	int l = 0, u = 0, d = 0, s = 0, t = 0;

	srand(time(NULL));

	do{
	cout << "Enter total length num: " << endl;
	cin >> t;

	cout << "Enter number num: " << endl;
	cin >> d;

	cout << "Enter low case num: " << endl;
	cin >> l;

	cout << "Enter up case num: " << endl;
	cin >> u;

	cout << "Enter spl char num: " << endl;
	cin >> s;

	if((d + l + u + s) != t)
		cout << " Enter Again !! " << endl;
	} while ((d+l+u+s) != t);

	if ((d + l + u + s) == t) {
		/*suggest t strong strings */
		suggest = suggester(l, u, d, s, t);
		cout << suggest << endl;
	}
	return 0;
}

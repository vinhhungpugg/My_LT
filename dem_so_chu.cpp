#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

// Ham` random chuoi~ ki' tu. ngau~ nhien (CHỮ)
void randText(int length, char *result) {
	char char_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < length; i++)
	{
		result[i] = char_set[rand() % sizeof(char_set)];
	}
	result[length] = '\0';
}

// Ham` random chuoi~ ki' tu. ngau~ nhien (SỐ)
void randnumber(int length, char *result) {
	char char_number[] = "1234567890~!@#$%^&*()";
	for (int i = 0; i < length; i++)
	{
		result[i] = char_number[rand() % sizeof(char_number)];
	}
	result[length] = '\0';
}

// Ham` check de^m' chuoi~ ki' tu (chu~ cai', so', ki' tu. đb)
void checkText(char *a) {
	int chucai = 0, chuso = 0, dacbiet = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		if (isdigit(a[i])) {
			++chuso;
		}
		else if (isalpha(a[i])) {
			++chucai;
		}
		else {
			++dacbiet;
		}
	}
	cout << "So luong chu so : " << chuso << endl;
	cout << "So luong chu cai :" << chucai << endl;
	cout << "So luong chu dac biet : " << dacbiet << endl;
}

int main() {
	cout << "Nhap do dai chuoi : ";
	int length;
	cin >> length;
	char *result = new char[length + 1];
	char *results = new char[length + 1];
	srand(time(NULL));
	randText(length, result);
	randnumber(length, results);
	cout << result;
	cout << endl;
	cout << results;
	cout << endl;
	checkText(result);
	checkText(results);
	delete[]result;
	delete[]results;
	system("pause");
	return 0;
}
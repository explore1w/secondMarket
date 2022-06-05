#include <iostream>
#include<stdio.h>
using namespace std;

void add(char num1[], char num2[], char res[]);

int get_len(char num[]);

int get_integer(char num[]);

int get_dot(char num[]);

int get_decimal_len(char num[]);

int get_integer_len(int x);

int char_to_int(char num[], int begin, int len);

void int_to_char(char res[], int x);

void get_decimal(char num1[], char num2[]);

char decimal[128] = {0};

int main() {

	char num1[128] = {0}, num2[128] = {0}, res[128] = {0};

	float f1,f2;// 

	cout << "Float1:";
	cin >> f1;

	cout << "Float2:";
	cin >> f2;

	if (cin.good() && cin.good()) {
		sprintf(num1, "%f", f1);
		sprintf(num2, "%f", f2);
		add(num1, num2, res);
		cout << res << endl;
	} else {
		cout << "输入的数据类型错误\n";
	}



	return 0;

}


int get_dot(char num[]) {

	int i;

	for (i = 0; num[i] != '\0'; ++i) {

		if (num[i] == '.') {

			return i;

		}

	}

	return i;

}


int char_to_int(char num[], int begins, int len) {

	int integer = 0, l = get_decimal_len(num);

	if (l < len) {

		for (int j = l; j <= len; ++j) {

			num[begins + j + 1] = '0';

		}

	}

	for (int i = 0; i < len; ++i) {

		integer = integer * 10 + num[begins + i + 1] - '0';

	}

	return integer;

}



void int_to_char(char res[], int x) {

	int i, l = get_integer_len(x);

	for (i = l - 1; i >= 0; --i) {

		res[i] = x % 10 + '0';

		x /= 10;

	}

	res[l + 1] = '\0';

}



int get_integer(char num[]) {

	int integer = 0, x = get_dot(num);

	for (int i = 0; i <= x - 1; ++i) {

		integer = integer * 10 + num[i] - '0';

	}

	return integer;

}


int get_decimal_len(char num[]) {

	int x = get_dot(num), len = 0;

	for (int i = x + 1; num[i] != '\0'; ++i)len++;

	return len;

}


int get_integer_len(int x) {

	int integer_len = 0;

	if (x == 0)return 1;

	while (x > 0) {

		x /= 10;

		integer_len++;

	}

	return integer_len;

}



int get_len(char num[]) {

	int sum = 0;

	for (int i = 0; num[i] != '\0'; ++i) sum++;

	return sum;

}



void get_decimal(char num1[], char num2[]) {

	int decimal_len = get_decimal_len(num1) > get_decimal_len(num2) ? get_decimal_len(num1) : get_decimal_len(num2);

	int decimal_sum = char_to_int(num1, get_dot(num1), decimal_len) + char_to_int(num2, get_dot(num2), decimal_len);

	int_to_char(decimal, decimal_sum);

	if (decimal_len < get_integer_len(decimal_sum)) {

		for (int i = 0; decimal[i] != '\0'; ++i) {

			decimal[i] = decimal[i + 1];

		}

	}

}

void add(char num1[], char num2[], char res[]) {

	bool flag = false, zero_flag = false;

	int i;

	int l1 = get_len(num1), l2 = get_len(num2);

	get_decimal(num1, num2);

	int decimal_len = get_decimal_len(num1) > get_decimal_len(num2) ? get_decimal_len(num1) : get_decimal_len(num2);

	int decimal_sum = char_to_int(num1, get_dot(num1), decimal_len) + char_to_int(num2, get_dot(num2), decimal_len);

	if (decimal_len < get_integer_len(decimal_sum)) {

		flag = true;

	}

	int sum_int = get_integer(num1) + get_integer(num2) + flag;

	int_to_char(res, sum_int);

	*(res + get_integer_len(sum_int)) = '.';

	for (i = 1; decimal[i - 1] != '\0'; ++i) {

		*(res + get_integer_len(sum_int) + i) = decimal[i - 1];

	}

	for (i = get_dot(res) + 1; res[i] != '\0'; ++i) {

		if (res[i] != '0') {

			zero_flag = true;

		}

	}

	if (!zero_flag) {

		res[get_dot(res)] = '\0';

	} else {

		for (i = get_len(res) - 1; i > get_dot(res); --i) {

			if (res[i] == '0') {

				res[i] = '\0';

				break;

			}

			break;

		}

	}

	num1[l1] = '\0', num2[l2] = '\0';

}

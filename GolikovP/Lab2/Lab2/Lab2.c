#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"

int main() {
	int n_count=0, w_count=0;
	char c;
	int n_flag=0, w_flag=0;
	printf("Enter random pure words and pure numbers:");
	while (scanf("%c", &c) == 1 && c != '\n') {
		int let = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
		int dig = (c >= '0' && c <= '9');

		if (let) {
			if (w_flag == 0 && n_flag == 0) {
				w_flag = 1;
			}
		}
		else if (dig) {
			if (w_flag == 0 && n_flag == 0) {
				n_flag = 1;
			}
		}
		else {
			if (w_flag == 1) {
				w_count += 1;
				w_flag = 0;
			}
			else if (n_flag == 1) {
				n_count += 1;
				n_flag = 0;
			}
		}
	}
	if (w_flag = 1) {
		w_count += 1;
	}
	else if (n_flag = 1) {
		n_count += 1;
	}

	printf("Count of words and numbers:%d, %d", w_count, n_count);
	return 0;
}
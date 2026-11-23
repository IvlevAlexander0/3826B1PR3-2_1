#include <stdio.h>
int main() {
	int c;
	int f = 0,w = 0, n = 0;
	while ((c = getchar()) != '\n') {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			if (f != 1) {
				w += 1;
				f = 1;
			}
		}
		else if ((c >= '0' && c <= '9') || (c >= '0' && c <= '9')) {
			if (f != 2) {
				n += 1;
				f = 2;
			}
		}
		else {
			f = 0;
		}
	}
	printf("words: %d\nnumbers: %d\n", w, n);
	return 0;
}
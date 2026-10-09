#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"

void main() {

	int figure;
	printf("Choose the figure to move from position 1 to position 2 (1 - King, 2 - Queen, 3 - Knight, 4 - Bishop, 5 - Rook):");
	scanf("%d", &figure);

	if (figure > 5 || figure < 1) {
		printf("Number must be 1-5");
		return 0;
	}
	int pos_n1, pos_n2;
	char pos_c1, pos_c2;
	int pos_cn1 = 0, pos_cn2 = 0;
	printf("Choose the first position with letter A-H and number 1-8:");
	scanf(" %c %d", &pos_c1, &pos_n1);

	if (pos_c1 == 'A' || pos_c1 == 'a') pos_cn1 = 1;
	else if (pos_c1 == 'B' || pos_c1 == 'b') pos_cn1 = 2;
	else if (pos_c1 == 'C' || pos_c1 == 'c') pos_cn1 = 3;
	else if (pos_c1 == 'D' || pos_c1 == 'd') pos_cn1 = 4;
	else if (pos_c1 == 'E' || pos_c1 == 'e') pos_cn1 = 5;
	else if (pos_c1 == 'F' || pos_c1 == 'f') pos_cn1 = 6;
	else if (pos_c1 == 'G' || pos_c1 == 'g') pos_cn1 = 7;
	else if (pos_c1 == 'H' || pos_c1 == 'h') pos_cn1 = 8;

	printf("Choose the second position with letter A-H and number 1-8:");
	scanf(" %c %d", &pos_c2, &pos_n2);

	if (pos_c2 == 'A' || pos_c2 == 'a') pos_cn2 = 1;
	else if (pos_c2 == 'B' || pos_c2 == 'b') pos_cn2 = 2;
	else if (pos_c2 == 'C' || pos_c2 == 'c') pos_cn2 = 3;
	else if (pos_c2 == 'D' || pos_c2 == 'd') pos_cn2 = 4;
	else if (pos_c2 == 'E' || pos_c2 == 'e') pos_cn2 = 5;
	else if (pos_c2 == 'F' || pos_c2 == 'f') pos_cn2 = 6;
	else if (pos_c2 == 'G' || pos_c2 == 'g') pos_cn2 = 7;
	else if (pos_c2 == 'H' || pos_c2 == 'h') pos_cn2 = 8;
	if (pos_n1 > 8 || pos_n2 > 8 || pos_n1 < 1 || pos_n2 < 1 || pos_cn1 == 0 || pos_cn2 == 0) {
		printf("Letter must be A-H and number must be 1-8");
		return 0;
	}
	if (pos_n1 == pos_n2 && pos_cn1 == pos_cn2) {
		printf("Thats the same position");
	}
	
	int min_n = fabs(pos_n1 - pos_n2), min_cn = fabs(pos_cn1 - pos_cn2);

	if ((min_n == min_cn) && (min_n > 1 && min_cn > 1)) {
		if (figure == 2) printf("Queen can do this. Also bishop can do this.");
		else if (figure == 4) printf("Bishop can do this. Also queen can do this.");
		else printf("This figure can't do this. This can do bishop and queen.");
	}

	else if ((min_n == 1 && min_cn == 0) || (min_n == 0 && min_cn == 1)) {
		if (figure == 1) printf("King can do this. Also queen and rook can do this.");
		else if (figure == 2) printf("Queen can do this. Also king and rook can do this.");
		else if (figure == 5) printf("Rook can do this. Also king and queen can do this.");
		else printf("This figure can't do this. This can do king, queen and rook.");
	}
	else if (min_n == 1 && min_cn == 1){
		if (figure == 1) printf("King can do this. Also queen and bishop can do this.");
		else if (figure == 2) printf("Queen can do this. Also king and bishop can do this.");
		else if (figure == 4) printf("Bishop can do this. Also king and queen can do this.");
		else printf("This figure can't do this. This can do king, queen and bishop.");
	}
	else if ((pos_n1 == pos_n2 || pos_cn1 == pos_cn2) && (min_cn > 1 || min_n > 1)) {
		if (figure == 2) printf("Queen can do this. Also rook can do this.");
		else if (figure == 5) printf("Rook can do this. Also queen can do this.");
		else printf("This figure can't do this. This can do queen and rook.");
	}
	else if ((min_n == 2 && min_cn == 1) || (min_n == 1 && min_cn == 2)) {
		if (figure == 3) printf("Knight can do this");
		else printf("This figure can't do this. This can do knight");
	}
}
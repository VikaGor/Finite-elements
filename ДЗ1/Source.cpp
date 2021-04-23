#include <math.h>
#include "node_splitting.h"
#include "GridMethod.h"
#include <iostream>
#include <conio.h>


using namespace std;

int main() {
	setlocale(0, "Russian");

	int kol_ = 64;
	int * number_ = new int[kol_];
	int * type_ = new int[kol_];
	int * right_ = new int[kol_];
	int * left_ = new int[kol_];
	int * top_ = new int[kol_];
	int * bottom_ = new int[kol_];
	double * right_length_ = new double[kol_];
	double * left_length_ = new double[kol_];
	double * top_length_ = new double[kol_];
	double * bottom_length_ = new double[kol_];

	for (int i = 0; i < kol_; i++) {
		number_[i]=i;
	}

	type_[0] = 4;   type_[1] = 1;   type_[2] = 1;   type_[3] = 1;   type_[4] = 1;   type_[5] = 1;   type_[6] = 4;
	type_[7] = 3;   type_[8] = 0;   type_[9] = 0;   type_[10] = 0;  type_[11] = 0;  type_[12] = 0;  type_[13] = 3;
	type_[14] = 3;  type_[15] = 0;  type_[16] = 0;  type_[17] = 0;  type_[18] = 0;  type_[19] = 0;  type_[20] = 3;
	type_[21] = 3;  type_[22] = 0;  type_[23] = 0;  type_[24] = 4;  type_[25] = 2;  type_[26] = 2;  type_[27] = 4;
	type_[28] = 3;  type_[29] = 0;  type_[30] = 0;  type_[31] = 2;
	type_[32] = 3;  type_[33] = 0;  type_[34] = 0;  type_[35] = 2;
	type_[36] = 3;  type_[37] = 0;  type_[38] = 0;  type_[39] = 4;  type_[40] = 2;  type_[41] = 2;  type_[42] = 4;
	type_[43] = 3;  type_[44] = 0;  type_[45] = 0;  type_[46] = 0;  type_[47] = 0;  type_[48] = 0;  type_[49] = 3;
	type_[50] = 3;  type_[51] = 0;  type_[52] = 0;  type_[53] = 0;  type_[54] = 0;  type_[55] = 0;  type_[56] = 3;
	type_[57] = 4;  type_[58] = 1;  type_[59] = 1;  type_[60] = 1;  type_[61] = 1;  type_[62] = 1;  type_[63] = 4;



	left_[0] = -1;  left_[1] = 0;   left_[2] = 1;   left_[3] = 2;   left_[4] = 3;   left_[5] = 4;   left_[6] = 5;
	left_[7] = -1;  left_[8] = 7;   left_[9] = 8;   left_[10] = 9;  left_[11] = 10; left_[12] = 11; left_[13] = 12;
	left_[14] = -1; left_[15] = 14; left_[16] = 15; left_[17] = 16; left_[18] = 17; left_[19] = 18; left_[20] = 19;
	left_[21] = -1; left_[22] = 21; left_[23] = 22; left_[24] = 23; left_[25] = 24; left_[26] = 25; left_[27] = 26;
	left_[28] = -1; left_[29] = 28; left_[30] = 29; left_[31] = 30;
	left_[32] = -1; left_[33] = 32; left_[34] = 33; left_[35] = 34;
	left_[36] = -1; left_[37] = 36; left_[38] = 37; left_[39] = 38; left_[40] = 39; left_[41] = 40; left_[42] = 41;
	left_[43] = -1; left_[44] = 43; left_[45] = 44; left_[46] = 45; left_[47] = 46; left_[48] = 47; left_[49] = 48;
	left_[50] = -1; left_[51] = 50; left_[52] = 51; left_[53] = 52; left_[54] = 53; left_[55] = 54; left_[56] = 55;
	left_[57] = -1; left_[58] = 57; left_[59] = 58; left_[60] = 59; left_[61] = 60; left_[62] = 61; left_[63] = 62;



	right_[0] = 1;   right_[1] = 2;   right_[2] = 3;   right_[3] = 4;   right_[4] = 5;   right_[5] = 6;   right_[6] = -1;
	right_[7] = 8;   right_[8] = 9;   right_[9] = 10;  right_[10] = 11; right_[11] = 12; right_[12] = 13; right_[13] = -1;
	right_[14] = 15; right_[15] = 16; right_[16] = 17; right_[17] = 18; right_[18] = 19; right_[19] = 20; right_[20] = -1;
	right_[21] = 22; right_[22] = 23; right_[23] = 24; right_[24] = 25; right_[25] = 26; right_[26] = 27; right_[27] = -1;
	right_[28] = 29; right_[29] = 30; right_[30] = 31; right_[31] = -1;
	right_[32] = 33; right_[33] = 34; right_[34] = 35; right_[35] = -1;
	right_[36] = 37; right_[37] = 38; right_[38] = 39; right_[39] = 40; right_[40] = 41; right_[41] = 42; right_[42] = -1;
	right_[43] = 44; right_[44] = 45; right_[45] = 46; right_[46] = 47; right_[47] = 48; right_[48] = 49; right_[49] = -1;
	right_[50] = 51; right_[51] = 52; right_[52] = 53; right_[53] = 54; right_[54] = 55; right_[55] = 56; right_[56] = -1;
	right_[57] = 58; right_[58] = 59; right_[59] = 60; right_[60] = 61; right_[61] = 62; right_[62] = 63; right_[63] = -1;



	top_[0] = -1;  top_[1] = -1;  top_[2] = -1;  top_[3] = -1;  top_[4] = -1;  top_[5] = -1;  top_[6] = -1;
	top_[7] = 0;   top_[8] = 1;   top_[9] = 2;   top_[10] = 3;  top_[11] = 4;  top_[12] = 5;  top_[13] = 6;
	top_[14] = 7;  top_[15] = 8;  top_[16] = 9;  top_[17] = 10; top_[18] = 11; top_[19] = 12; top_[20] = 13;
	top_[21] = 14; top_[22] = 15; top_[23] = 16; top_[24] = 17; top_[25] = 18; top_[26] = 19; top_[27] = 20;
	top_[28] = 21; top_[29] = 22; top_[30] = 23; top_[31] = 24;
	top_[32] = 28; top_[33] = 29; top_[34] = 30; top_[35] = 31;
	top_[36] = 32; top_[37] = 33; top_[38] = 34; top_[39] = 35; top_[40] = -1; top_[41] = -1; top_[42] = -1;
	top_[43] = 36; top_[44] = 37; top_[45] = 38; top_[46] = 39; top_[47] = 40; top_[48] = 41; top_[49] = 42;
	top_[50] = 43; top_[51] = 44; top_[52] = 45; top_[53] = 46; top_[54] = 47; top_[55] = 48; top_[56] = 49;
	top_[57] = 50; top_[58] = 51; top_[59] = 52; top_[60] = 53; top_[61] = 54; top_[62] = 55; top_[63] = 56;

	
	bottom_[0] = 7;   bottom_[1] = 8;   bottom_[2] = 9;   bottom_[3] = 10;  bottom_[4] = 11;  bottom_[5] = 12;  bottom_[6] = 13;
	bottom_[7] = 14;  bottom_[8] = 15;  bottom_[9] = 16;  bottom_[10] = 17; bottom_[11] = 18; bottom_[12] = 19; bottom_[13] = 20;
	bottom_[14] = 21; bottom_[15] = 22; bottom_[16] = 23; bottom_[17] = 24; bottom_[18] = 25; bottom_[19] = 26; bottom_[20] = 27;
	bottom_[21] = 28; bottom_[22] = 29; bottom_[23] = 30; bottom_[24] = 31; bottom_[25] = -1; bottom_[26] = -1; bottom_[27] = -1;
	bottom_[28] = 32; bottom_[29] = 33; bottom_[30] = 34; bottom_[31] = 35;
	bottom_[32] = 36; bottom_[33] = 37; bottom_[34] = 38; bottom_[35] = 39;
	bottom_[36] = 43; bottom_[37] = 44; bottom_[38] = 45; bottom_[39] = 46; bottom_[40] = 47; bottom_[41] = 48; bottom_[42] = 49;
	bottom_[43] = 50; bottom_[44] = 51; bottom_[45] = 52; bottom_[46] = 53; bottom_[47] = 54; bottom_[48] = 55; bottom_[49] = 56;
	bottom_[50] = 57; bottom_[51] = 58; bottom_[52] = 59; bottom_[53] = 60; bottom_[54] = 61; bottom_[55] = 62; bottom_[56] = 63;
	bottom_[57] = -1; bottom_[58] = -1; bottom_[59] = -1; bottom_[60] = -1; bottom_[61] = -1; bottom_[62] = -1; bottom_[63] = -1;


	right_length_[0] = 10;  right_length_[1] = 10;  right_length_[2] = 10;  right_length_[3] = 10;  right_length_[4] = 10;  right_length_[5] = 10;  right_length_[6] = 0;
	right_length_[7] = 10;  right_length_[8] = 10;  right_length_[9] = 10;  right_length_[10] = 10; right_length_[11] = 10; right_length_[12] = 10; right_length_[13] = 0;
	right_length_[14] = 10; right_length_[15] = 10; right_length_[16] = 10; right_length_[17] = 10; right_length_[18] = 10; right_length_[19] = 10; right_length_[20] = 0;
	right_length_[21] = 10; right_length_[22] = 10; right_length_[23] = 10; right_length_[24] = 10; right_length_[25] = 10; right_length_[26] = 10; right_length_[27] = 0;
	right_length_[28] = 10; right_length_[29] = 10; right_length_[30] = 10; right_length_[31] = 0;
	right_length_[32] = 10; right_length_[33] = 10; right_length_[34] = 10; right_length_[35] = 0;
	right_length_[36] = 10; right_length_[37] = 10; right_length_[38] = 10; right_length_[39] = 10; right_length_[40] = 10; right_length_[41] = 10; right_length_[42] = 0;
	right_length_[43] = 10; right_length_[44] = 10; right_length_[45] = 10; right_length_[46] = 10; right_length_[47] = 10; right_length_[48] = 10; right_length_[49] = 0;
	right_length_[50] = 10; right_length_[51] = 10; right_length_[52] = 10; right_length_[53] = 10; right_length_[54] = 10; right_length_[55] = 10; right_length_[56] = 0;
	right_length_[57] = 10; right_length_[58] = 10; right_length_[59] = 10; right_length_[60] = 10; right_length_[61] = 10; right_length_[62] = 10; right_length_[63] = 0;


	left_length_[0] = 0;  left_length_[1] = 10;  left_length_[2] = 10;  left_length_[3] = 10;  left_length_[4] = 10;  left_length_[5] = 10;  left_length_[6] = 10;
	left_length_[7] = 0;  left_length_[8] = 10;  left_length_[9] = 10;  left_length_[10] = 10; left_length_[11] = 10; left_length_[12] = 10; left_length_[13] = 10;
	left_length_[14] = 0; left_length_[15] = 10; left_length_[16] = 10; left_length_[17] = 10; left_length_[18] = 10; left_length_[19] = 10; left_length_[20] = 10;
	left_length_[21] = 0; left_length_[22] = 10; left_length_[23] = 10; left_length_[24] = 10; left_length_[25] = 10; left_length_[26] = 10; left_length_[27] = 10;
	left_length_[28] = 0; left_length_[29] = 10; left_length_[30] = 10; left_length_[31] = 10;
	left_length_[32] = 0; left_length_[33] = 10; left_length_[34] = 10; left_length_[35] = 10;
	left_length_[36] = 0; left_length_[37] = 10; left_length_[38] = 10; left_length_[39] = 10; left_length_[40] = 10; left_length_[41] = 10; left_length_[42] = 10;
	left_length_[43] = 0; left_length_[44] = 10; left_length_[45] = 10; left_length_[46] = 10; left_length_[47] = 10; left_length_[48] = 10; left_length_[49] = 10;
	left_length_[50] = 0; left_length_[51] = 10; left_length_[52] = 10; left_length_[53] = 10; left_length_[54] = 10; left_length_[55] = 10; left_length_[56] = 10;
	left_length_[57] = 0; left_length_[58] = 10; left_length_[59] = 10; left_length_[60] = 10; left_length_[61] = 10; left_length_[62] = 10; left_length_[63] = 10;
	

	top_length_[0] = 0;   top_length_[1] = 0;   top_length_[2] = 0;   top_length_[3] = 0;   top_length_[4] = 0;  top_length_[5] = 0;  top_length_[6] = 0;
	top_length_[7] = 6;   top_length_[8] = 6;   top_length_[9] = 6;   top_length_[10] = 6;  top_length_[11] = 6; top_length_[12] = 6; top_length_[13] = 6;
	top_length_[14] = 6;  top_length_[15] = 6;  top_length_[16] = 6;  top_length_[17] = 6;  top_length_[18] = 6; top_length_[19] = 6; top_length_[20] = 6;
	top_length_[21] = 6;  top_length_[22] = 6;  top_length_[23] = 6;  top_length_[24] = 6;  top_length_[25] = 6; top_length_[26] = 6; top_length_[27] = 6;
	top_length_[28] = 12; top_length_[29] = 12; top_length_[30] = 12; top_length_[31] = 12;
	top_length_[32] = 12; top_length_[33] = 12; top_length_[34] = 12; top_length_[35] = 12;
	top_length_[36] = 12; top_length_[37] = 12; top_length_[38] = 12; top_length_[39] = 12; top_length_[40] = 0; top_length_[41] = 0; top_length_[42] = 0;
	top_length_[43] = 6;  top_length_[44] = 6;  top_length_[45] = 6;  top_length_[46] = 6;  top_length_[47] = 6; top_length_[48] = 6; top_length_[49] = 6;
	top_length_[50] = 6;  top_length_[51] = 6;  top_length_[52] = 6;  top_length_[53] = 6;  top_length_[54] = 6; top_length_[55] = 6; top_length_[56] = 6;
	top_length_[57] = 6;  top_length_[58] = 6;  top_length_[59] = 6;  top_length_[60] = 6;  top_length_[61] = 6; top_length_[62] = 6; top_length_[63] = 6;


	bottom_length_[0] = 6;   bottom_length_[1] = 6;   bottom_length_[2] = 6;   bottom_length_[3] = 6;   bottom_length_[4] = 6;  bottom_length_[5] = 6;  bottom_length_[6] = 6;
	bottom_length_[7] = 6;   bottom_length_[8] = 6;   bottom_length_[9] = 6;   bottom_length_[10] = 6;  bottom_length_[11] = 6; bottom_length_[12] = 6; bottom_length_[13] = 6;
	bottom_length_[14] = 6;  bottom_length_[15] = 6;  bottom_length_[16] = 6;  bottom_length_[17] = 6;  bottom_length_[18] = 6; bottom_length_[19] = 6; bottom_length_[20] = 6;
	bottom_length_[21] = 12; bottom_length_[22] = 12; bottom_length_[23] = 12; bottom_length_[24] = 12; bottom_length_[25] = 0; bottom_length_[26] = 0; bottom_length_[27] = 0;
	bottom_length_[28] = 12; bottom_length_[29] = 12; bottom_length_[30] = 12; bottom_length_[31] = 12;
	bottom_length_[32] = 12; bottom_length_[33] = 12; bottom_length_[34] = 12; bottom_length_[35] = 12;
	bottom_length_[36] = 6;  bottom_length_[37] = 6;  bottom_length_[38] = 6;  bottom_length_[39] = 6;  bottom_length_[40] = 6; bottom_length_[41] = 6; bottom_length_[42] = 6;
	bottom_length_[43] = 6;  bottom_length_[44] = 6;  bottom_length_[45] = 6;  bottom_length_[46] = 6;  bottom_length_[47] = 6; bottom_length_[48] = 6; bottom_length_[49] = 6;
	bottom_length_[50] = 6;  bottom_length_[51] = 6;  bottom_length_[52] = 6;  bottom_length_[53] = 6;  bottom_length_[54] = 6; bottom_length_[55] = 6; bottom_length_[56] = 6;
	bottom_length_[57] = 0;  bottom_length_[58] = 0;  bottom_length_[59] = 0;  bottom_length_[60] = 0;  bottom_length_[61] = 0; bottom_length_[62] = 0; bottom_length_[63] = 0;

	GridMethod TEST(kol_, number_, type_, left_, right_, top_, bottom_, left_length_, right_length_, top_length_, bottom_length_);
	calculator(TEST);
	// ??????
	//cout << TEST;

	_getch();
	return 1;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fstream>
#include <Windows.h>
#include <algorithm>

using namespace std;

bool extension(string file_name);

const off_t SIZE_001 = 2;
const off_t SIZE_002 = 7;
unsigned char search_001[] = { 0x44, 0x89 };
unsigned char replace_001[] = { 0x89,0x88,0x40,0xB0,0x7D,0xB0,0x00 };

string filename;

typedef istream_iterator<unsigned char> input_iter_t;
typedef ostream_iterator<unsigned char> output_iter_t;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <propsys.h>
#include <mfidl.h>


using namespace std;

string extension(string file_name);


//========.webm hex==========
const off_t SIZE_001 = 2;
const off_t SIZE_002 = 7;
unsigned char search_001[] = { 0x44, 0x89 };
unsigned char replace_001[] = { 0x89,0x88,0x40,0xB0,0x7D,0xB0,0x00 };
//========.mp4 hex==========
const off_t SIZEMP4_001 = 4;
const off_t SIZEMP4_002 = 8;
unsigned char searchmp4_001[] = { 0x6D, 0x76, 0x68, 0x64 };
unsigned char replacemp4_001[] = { 0x00,0x00,0x03,0xE8,0x00,0x00,0x13,0x88 };

string filename;

typedef istream_iterator<unsigned char> input_iter_t;
typedef ostream_iterator<unsigned char> output_iter_t;
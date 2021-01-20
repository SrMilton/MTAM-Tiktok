#include "main.h"

int main()
{

	cout << "File name or path: ";
	cin >> filename;
	filename.erase(remove(filename.begin(), filename.end(), '"'), filename.end());//Removing "
	cout << filename;


	if (strcmp(extension(filename).c_str(), "webm")==0 && strcmp(extension(filename).c_str(), "mp4")==0)
	{
		cout << "Please try again with a .webm/.mp4 video (You can use a online video converter)." << endl;
		system("pause");
		system("cls");
		main();
	}
	
	fstream binaryFile(filename, ios::in | ios::out | ios::binary);

	if (binaryFile.is_open())
	{
		while (!binaryFile.eof()) 
		{
			if (!strcmp(extension(filename).c_str(), "webm")) //Converter WEBM
			{
				if (search(input_iter_t(binaryFile), input_iter_t(), search_001, search_001 + SIZE_001) != input_iter_t())
				{
					cout << "Address Found!" << endl;
						cout << "Applying exploit.." << endl;
						binaryFile.seekp(-SIZE_001, ios::cur);
						binaryFile.write(reinterpret_cast<const char*>(replace_001), SIZE_002);
						cout << "Sucessfull!" << endl;
						break;
				}
				else
				{
					cout << "Address not find. Make sure your file is not corrupted or try convert to .webm again." << endl;
				}
			}
			else if (!strcmp(extension(filename).c_str(), "mp4")) //Converter MP4
			{
				if (search(input_iter_t(binaryFile), input_iter_t(), searchmp4_001, searchmp4_001 + SIZEMP4_001) != input_iter_t())
				{
					cout << "Address Found!" << endl;
					cout << "Applying exploit.." << endl;
					binaryFile.seekp(+11, ios::cur);
					binaryFile.write(reinterpret_cast<const char*>(replacemp4_001), SIZEMP4_002);
					cout << "Sucessfull!" << endl;
					break;
				}
				else
				{
					cout << "Address not find. Make sure your file is not corrupted or try convert to .mp4 again." << endl;
				}
			}
		}
	}
	else
	{
		cout << "File not find!" << endl;
		system("pause");
		return 0;
	}
		binaryFile.clear();		
		system("pause");
		return 0;

	
	return 0;
}

string extension(string file_name)
{
	int position = file_name.find_last_of(".");
	string result = file_name.substr(position + 1);
	return result;
}
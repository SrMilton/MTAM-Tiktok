#include "main.h"

int main()
{

	cout << "File name(without the extension): ";
	cin >> filename;

	//filename = filename + ".webm";

	if (!extension(filename))
	{
		cout << "Please try again with a .webm video (You can use a online video converter)." << endl;
		system("pause");
		system("cls");
		main();
	}
	
	fstream binaryFile(filename, ios::in | ios::out | ios::binary);

	if (binaryFile.is_open())
	{
		while (!binaryFile.eof()) 
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
		binaryFile.clear();		
		system("pause");
		return 0;
	}
	else
	{
		cout << "File not find!" << endl;
		system("pause");
		return 0;
	}
	
	return 0;
}

bool extension(string file_name)
{
	int position = file_name.find_last_of(".");
	string result = file_name.substr(position + 1);
	if (strcmp(result.c_str(), "webm"))
	{
		return false;
	}
	else return true;
}
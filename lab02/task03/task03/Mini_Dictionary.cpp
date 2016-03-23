#include "Mini_Dictionary.h"



map<string, string> ReadDictFromFile(const string & nameFile)
{
	ifstream dictFile(nameFile);

	map<string, string> dictionary;
	if (!dictFile.is_open())
	{
		cout << "Dictionary not found!" << endl;
		cout << "Create new dictionary!" << endl;
		return dictionary;
	}

	if (!CheckEmptyFile(nameFile))
	{
		cout << "empty dictionary" << endl;
		cout << "Create new dictionary!" << endl;
		return dictionary;
	}
	string dictStr;
	string wordSource;
	string wordTranlated;
	int posStart = 0;
	int posEnd = 0;
	while (!dictFile.eof())
	{
		posStart = 0;
		getline(dictFile, dictStr);
		wordSource = "";
		posEnd = dictStr.find(":");
		wordSource.append(dictStr, posStart, posEnd);
		posStart = posEnd;

		wordTranlated = "";
		wordTranlated.append(dictStr, posStart + 1);

		dictionary.insert(pair<string, string>(wordSource, wordTranlated));
	}
	return dictionary;
}

string FindWord(map<string, string> & dict, const string & wordKey)
{
	map<string, string>::iterator it;
	it = dict.find(wordKey);
	if (it != dict.end())
	{
		return it->second;
	}
	return "";
}

void SaveDictToFile(map<string, string> & dictionary, const string & nameFile)
{
	ofstream outFile(nameFile);
	for (auto it : dictionary)
	{
		outFile << it.first << ":" << it.second << endl;
	}
}


bool SaveWordInDict(map<string, string> & dict, const string & wordKey, const string & wordValue)
{
	if (wordValue != "")
	{
		dict.insert(pair<string, string>(wordKey, wordValue));
		return true;
	}
	return false;
}

bool CheckEmptyFile(const string & nameFile)
{
	struct stat file;
	stat(nameFile.c_str(), &file);
	return (file.st_size > 0);
}

void ProgramDialogue(map<string, string> & dictionary)
{
	string answer;
	string askUser = "";
	string askUserTranslate = "";
	map<string, string>::iterator it;
	cout << ">";
	getline(cin, askUser);
	while (askUser != "...")
	{
		if (askUser != "")
		{
			answer = FindWord(dictionary, askUser);

			if 	(answer == "")
			{
				cout << "Неизвестное слово \"" << askUser << "\". Введите перевод или пустую строку для отказа" << endl;
				cout << ">";
				getline(cin, askUserTranslate);
				if (SaveWordInDict(dictionary, askUser, askUserTranslate))
				{
					cout << "Слово \"" << askUser << "\" сохранено в словаре как \"" << askUserTranslate << "\"" << endl;
				}
				else
				{
					cout << "Слово \"" << askUser << "\" проигнорировано" << endl;
				}

			}
			else
			{
				cout << answer << endl;
			}
		}
		cout << ">";
		getline(cin, askUser);
	}
	cout << "В словарь были внесены изменения.Введите Y или y для сохранения перед выходом" << endl;
	cout << ">";
	getline(cin, askUser);
	if (askUser == "y" || askUser == "Y")
	{
		SaveDictToFile(dictionary, NAME_DICTIONARY_FILE);
		cout << "Изменения сохранены. До свидания." << endl;
	}
}

void Translating()
{
	map<string, string> dictionary;
	dictionary = ReadDictFromFile(NAME_DICTIONARY_FILE);
	ProgramDialogue(dictionary);
}
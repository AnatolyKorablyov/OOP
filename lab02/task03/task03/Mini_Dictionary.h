#pragma once
#include "stdafx.h"

using namespace std;

static const string NAME_DICTIONARY_FILE = "dict.txt";

map<string, string> ReadDictFromFile(const string & nameFile);
void SaveDictToFile(map<string, string> & dictionary, const string & nameFile);

bool CheckEmptyFile(const string & nameFile);

string FindWord(map<string, string> & dict, const string & wordKey);
bool SaveWordInDict(map<string, string> & dict, const string & wordKey, const string & wordValue);
void Translating();
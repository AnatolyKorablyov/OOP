#include "stdafx.h"

using namespace std;

string FindAndReplace(const string & subject, const string & searchString, const string & replaceString)
{
	if (searchString.empty())
	{
		return subject;
	}
	string newSubject;

	size_t position = 0;
	size_t afterChangingPosition = 0;

	while ((position = subject.find(searchString, position)) != string::npos)
	{
		newSubject.append(subject, afterChangingPosition, position - afterChangingPosition).append(replaceString);
		position += searchString.length();
		afterChangingPosition = position;
	}
	newSubject.append(subject, afterChangingPosition);
	return newSubject;
}

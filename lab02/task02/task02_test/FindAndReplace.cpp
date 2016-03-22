#include "FindAndReplace.h"

string FindAndReplace(const string & subjectStr, const string & searchStr, const string & replaceStr)
{
	if (searchStr.empty())
	{
		return subjectStr;
	}
	string localStr;

	size_t posLastEnd = 0;

	size_t posStart = subjectStr.find(searchStr);

	while (posStart != string::npos)
	{
		localStr.append(subjectStr, posLastEnd, posStart - posLastEnd);
		localStr.append(replaceStr);
		posStart += searchStr.length();
		posLastEnd = posStart;
		posStart = subjectStr.find(searchStr, posStart);
	}
	localStr.append(subjectStr, posLastEnd);
	return localStr;
}
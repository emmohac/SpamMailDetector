#include "Mail.h"

Mail::Mail()
{
}

void Mail::checkSpamMail(string filename, string trigger)
{
	fileName = filename;
	triggerWord = trigger;
	int wordCount = 0;
	ifstream input(fileName);
	if (!input)
		cout << "Failed to open file" << endl;
	string word;
	while (input >> word)
	{
		word += word;
		if (word.find(triggerWord) != string::npos)
			spamMailTriggerWord++;
		wordCount++;
	}
	totalSpamMailWordCount += wordCount;
}

void Mail::checkNonSpamMail(string filename, string trigger)
{
	fileName = filename;
	triggerWord = trigger;
	int wordCount = 0;
	ifstream input(fileName);
	if (!input)
		cout << "Failed to open file" << endl;
	string word;
	while (input >> word)
	{
		word += word;
		if (word.find(triggerWord) != string::npos)
			mailTriggerWord++;
		wordCount++;
	}
	totalMailWordCount += wordCount;
}

int Mail::getMailWordCount() const
{
	return totalMailWordCount;
}

int Mail::getMailTriggerWord() const
{
	return mailTriggerWord;
}

int Mail::getSpamMailWordCount() const
{
	return totalSpamMailWordCount;
}

int Mail::getSpamMailTriggerWord() const
{
	return spamMailTriggerWord;
}

Mail::~Mail()
{
}

#ifndef MAIL_H
#define MAIL_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Mail
{
public:
	Mail();
	void checkSpamMail(string filename, string trigger);
	void checkNonSpamMail(string filename, string trigger);
	int getMailWordCount() const;
	int getMailTriggerWord() const;
	int getSpamMailWordCount() const;
	int getSpamMailTriggerWord() const;
	~Mail();

private:
	string fileName;
	string triggerWord;
	double mailWordCount = 1.0;
	double spamMailWordCount = 1.0;
	double spamMailTriggerWord = 1.0;
	double mailTriggerWord = 1.0;
	double totalSpamMailWordCount = 1.0;
	double totalMailWordCount = 1.0;
};
#endif // !MAIL_H

#include <iostream>
#include <string>
#include <fstream>
#include "Mail.h"
using namespace std;

int main()
{
	cout << "\t \t \t----------Spam Filter----------" << endl;
	cout << "The purpose of this program is to classify the email as either spam or not spam. "<< endl;
	cout << "The email will be classified as spam if a certain word appears too many time in the email." << endl;
	cout << endl;
	const double SPAM_MAIL_PROBABILITY = 0.25;
	const double NON_SPAM_MAIL_PROBABILITY = 0.75;

	string trigger;
	Mail myMail;
	cout << "Which word is contained in the mystery email? ";
	cin >> trigger;
	cout << endl;

	myMail.checkNonSpamMail("email1.txt", trigger);
	myMail.checkNonSpamMail("email2.txt", trigger);
	myMail.checkNonSpamMail("email3.txt", trigger);
	myMail.checkNonSpamMail("email4.txt", trigger);
	myMail.checkNonSpamMail("email5.txt", trigger);
	myMail.checkSpamMail("spam1.txt", trigger);
	myMail.checkSpamMail("spam2.txt", trigger);
	myMail.checkSpamMail("spam3.txt", trigger);
	myMail.checkSpamMail("spam4.txt", trigger);
	myMail.checkSpamMail("spam5.txt", trigger);

	double nonSpamTrigger = myMail.getMailTriggerWord();
	double nonSpamWordCount = myMail.getMailWordCount();
	double spamTrigger = myMail.getSpamMailTriggerWord();
	double spamWordCount = myMail.getSpamMailWordCount();
	double totalProb = nonSpamTrigger / nonSpamWordCount * NON_SPAM_MAIL_PROBABILITY + spamTrigger / spamWordCount * SPAM_MAIL_PROBABILITY;
	double bayernSpam = spamTrigger / spamWordCount * SPAM_MAIL_PROBABILITY / totalProb;
	double bayernNonSpam = nonSpamTrigger / nonSpamWordCount * NON_SPAM_MAIL_PROBABILITY / totalProb;

	cout << "Probability of a spam email containing the word " << trigger << ": " << spamTrigger / spamWordCount << endl;
	cout << "Probability of a non-spam email containing the word " << trigger << ": " << nonSpamTrigger / nonSpamWordCount << endl;
	cout << "Probability the email is spam: " << bayernSpam << endl;
	cout << "Probability the email is not spam: " << bayernNonSpam << endl;
	cout << endl;
	
	if (bayernNonSpam > bayernSpam)
		cout << "Your message is not spam!" << endl;
	else
		cout << "Your message is spam!" << endl;

	cout << endl;
	system("pause");
	return 0;
}
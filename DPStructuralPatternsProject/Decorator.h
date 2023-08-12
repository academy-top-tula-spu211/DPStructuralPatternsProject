#pragma once
#include <iostream>

using namespace std;

// Component
class IMessage
{
protected:
	string from;
	string to;
	string text;
public:
	IMessage() : from{ "" }, to{ "" }, text{ "" } {}

	IMessage(string from, string to, string text)
		: from{ from }, to{ to }, text{ text } {}
	
	string& From() { return from; }
	string& To() { return to; }
	string& Text() { return text; }

	virtual void Send() = 0;
};

// Concrete Components
class MessangerMessage : public IMessage
{
	string stick;
public:
	MessangerMessage(string from, string to, string text, string stick)
		: IMessage(from, to, text), stick{ stick } {};

	string& Stick() { return stick; }

	void Send() override
	{
		cout << "Messanger send message:\n"
			<< "\tfrom: " << from << "\n"
			<< "\tto: " << to << "\n"
			<< "\ttext: " << text << "\n"
			<< "\tstick: " << stick << "\n";
	}
};

class EmailMessage : public IMessage
{
	string subject;
public:
	EmailMessage(string from, string to, string text, string subject)
		: IMessage(from, to, text), subject{ subject } {};

	string& Subject() { return subject; }

	void Send() override
	{
		cout << "Messanger send message:\n"
			<< "\tfrom: " << from << "\n"
			<< "\tto: " << to << "\n"
			<< "\tsubject: " << subject << "\n"
			<< "\ttext: " << text << "\n";
	}
};

// Decorator
class IMessageDecorator : public IMessage
{
protected:
	IMessage* message;
public:
	IMessageDecorator(IMessage* message)
		: message{ message } {}

	IMessage*& Message() { return message; }
};

// Concrete Decorators
class FileMessage : public IMessageDecorator
{
	string file;
public:
	FileMessage(IMessage* message, string file)
		: IMessageDecorator(message), file{ file } {}

	void Send() override
	{
		message->Send();
		cout << "\twith file: " << file << "\n";
	}
};

class ContactMessage : public IMessageDecorator
{
	string contact;
public:
	ContactMessage(IMessage* message, string contact)
		: IMessageDecorator(message), contact{ contact } {}

	void Send() override
	{
		message->Send();
		cout << "\twith contact: " << contact << "\n";
	}
};



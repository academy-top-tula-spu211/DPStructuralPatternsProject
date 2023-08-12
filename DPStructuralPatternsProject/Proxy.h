#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Page
{
	int number;
	string text;
public:
	Page(int number, string text)
		: number{ number }, text{ text } {};

	friend bool operator==(const Page page1, const Page page2)
	{
		return page1.number == page2.number;
	}

	int& Number() { return number; }
	string& Text() { return text; }
};

class IBook
{
public:
	virtual Page* GetPage(int number) = 0;
};

class BookStore : public IBook
{
	map<int, Page*> book;
public:
	BookStore(map<int, Page*> book) : book{ book } {}

	Page* GetPage(int number) override
	{
		Page* page = book[number];
		cout << "page from store ";
		return page;
	}
};

class BookStoreProxy : public IBook
{
	map<int, Page*> pages;
	BookStore* store;
public:
	BookStoreProxy(BookStore* store) 
		: store{ store }{}

	Page* GetPage(int number) override
	{
		Page* page{ nullptr };

		page = pages[number];

		if (page == nullptr)
		{
			page = store->GetPage(number);
			pages[number] = page;
		}
		else
			cout << "page from proxy ";

		return page;
	}
};


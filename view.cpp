#include <iostream>
#include "view.h"
#include "article.h"

//using namespace std;

std::string View::drawSearch()
{
	std::string searchQuery;
	char buffer[256];
	std::cin.ignore();
	std::cout << "\n";
	std::cout << "Enter a wikipedia topic and press return\n";
	std::cin.getline(buffer, 256);
	searchQuery = buffer;
	return searchQuery;
}

void View::drawArticle(Article *article)
{
	std::cout << "Article\n";
	cout << "Title:" << article->title << "\n";
	std::cout << "Body:" << article->body << "\n";
	std::cout << "------------------------------\n";
}

std::string View::drawMenu()
{
	static std::string options [] = {"memory", "assembly", "compiler", "custom"};
	for(int i = 0; i < 4; i++) 
	{
		std::cout << "\t" << i+1 << " " << options[i] << std::endl;
	}	
	std::cout << "Select a menu option:\n";

	int choice = 1;
	do {
		if(std::cin.fail() || choice <= 0 || choice > 4)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Select a menu option:\n";
		}
		std::cin >> choice
	} while(choice <= 0 || choice > 4);

	return options[-1];
}

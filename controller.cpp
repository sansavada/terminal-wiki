#include "controller.h"
#include "repository.h"

using namespace std;

Controller::Controller()
{
	view = new View();
}

Controller::~Controller()
{
	delete view;
}

void Controller::displaySearch()
{
	query = view->drawSearch();
}

void Controller::displayArticle()
{
	Repository repository;
	Article article = repository.getArticleForQuery(query);
	view->drawArticle(&article);
}

void Controller::displayMenu()
{
	query = view->drawMenu();
	if(query == "custom")
	{
		displaySearch();
		displayArticle();
	}
	else 
	{
		displayArticle();
	}
}

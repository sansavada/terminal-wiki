#include "view.h"

class Controller {
public:
	Controller();
	~Controller();
	void displaySearch(); 
	void displayArticle();
	void displayMenu();
private:
	View *view;
	std::string query;
};

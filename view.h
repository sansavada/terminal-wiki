#include <string>

class Article;

class View {
public:
	std::string drawSearch();
	void drawArticle(Article *article);
	std::string drawMenu();
};

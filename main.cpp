#include "controller.h"

int main() {
	// Create Controller Instance
	Controller *controller = new Controller();

	while(1) {
		controller->displayMenu();
	}

	// Cleanup
	delete controller;

	return 0;
}

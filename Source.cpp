#include<iostream>
using namespace std;

struct collatzNode {
	int item; //item of node
	collatzNode* link; //link to another node
};

int main() {
	//declarations
	int itemCollatz;
	int counter = 1;

	//creates the initial node for the head node
	collatzNode* head = new collatzNode; //points to the head node
	head->item = 9;
	head->link = nullptr;

	//creates an initial link list of collatz based on user input
	//get user input
	collatzNode* nextCollatzNode = new collatzNode;
	nextCollatzNode = head; //nextCollatzNode is first node

	cout << "Enter an integer 100 or less: ";
	cin >> itemCollatz;

	//calculations
	nextCollatzNode->link = new collatzNode; //creates a node at the end of the list
	nextCollatzNode = nextCollatzNode->link;
	nextCollatzNode->link = nullptr;
	nextCollatzNode->item = itemCollatz;

	while (itemCollatz != 1)
	{
		if (itemCollatz % 2 == 0) {
			nextCollatzNode->link = new collatzNode; //creates a node at the end of the list
			nextCollatzNode = nextCollatzNode->link;
			nextCollatzNode->link = nullptr;
			counter++;

			itemCollatz = itemCollatz / 2;
			nextCollatzNode->item = itemCollatz;

		}

		else if (itemCollatz % 2 == 1) {
			nextCollatzNode->link = new collatzNode; //creates a node at the end of the list
			nextCollatzNode = nextCollatzNode->link;
			nextCollatzNode->link = nullptr;
			counter++;

			itemCollatz = ((3 * itemCollatz) + 1);
			nextCollatzNode->item = itemCollatz;

		}

	}

	//output
	//traverse the linked list and display output
	nextCollatzNode = head->link;
	cout << "The number " << nextCollatzNode->item << " produces the longest Collatz sequence of " << counter << " terms." << endl;
	cout << "Here are those terms " << endl;
	while (nextCollatzNode != nullptr) {
		cout << nextCollatzNode->item;
		nextCollatzNode = nextCollatzNode->link;
		if (nextCollatzNode != nullptr) {
			cout << "->";
		}
	}
	cout << endl;

	//delete the head node from the free store memory
	delete nextCollatzNode;
	nextCollatzNode = nullptr;

	delete head;
	head = nullptr;

	return 0;
}
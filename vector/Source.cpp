#include <iostream>
#include "vector.h"


using namespace std;


int menu(bool j);


int main()
{
	setlocale(LC_ALL, "Russian");

	unsigned int pos;
	int val;
	unsigned int count;
	vector <int> A;
	vector<int>::iterator myIterator, it;

	int variant = menu(0);

	while (variant != 22)
	{
		switch (variant)
		{

		case 1:
			A.show();
			break;

		case 2:
			cout << "Size:" << endl;
			cout << A.size() << endl;
			break;

		case 3:
			cout << "Capacity:" << endl;
			cout << A.capacity() << endl;

			break;

		case 4:
			cout << A.empty() << endl;
			break;

		case 5:
			cout << "Enter value for insert: ";
			cin >> val;
			A.push_back(val);
			break;

		case 6:
			A.pop_back();
			break;

		case 7:
			cout << "Enter item number: ";
			cin >> pos;
			cout << A[pos];
			break;

		case 8:
			cout << "Enter new capacity:";
			cin >> count;
			A.reserve(count);
			break;

		case 9:
			cout << "Enter value for insert: ";
			cin >> val;
			cout << "Enter position: ";
			cin >> pos;
			A.insert(A.begin() + pos, val);
			break;

		case 10:

			cout << "Enter value for insert: ";
			cin >> val;
			cout << "Enter position: ";
			cin >> pos;
			cout << "Enter count: ";
			cin >> count;
			A.insert(A.begin() + pos, count, val);
			break;
		case 11:
			A.shrink_to_fit();
			break;

		case 12:
			cout << "Enter number for erase: ";
			cin >> pos;
			A.erase(A.begin() + pos);
			break;
		case 13:
			A.clear();
			break;
		case 14:
			cout << "Enter position: ";
			cin >> pos;
			try {
				cout << A.at(pos) << endl;
			}
			catch (VectorException &exception) {
				std::cerr << "Exception on vector (" << exception.what() << ")\n";
			}
			break;
		case 15:
			myIterator = A.begin();
			break;

		case 16:
			myIterator = A.end();
			break;

		case 17:
			myIterator++;
			break;

		case 18:
			myIterator--;
			break;

		case 19:
			cout << *myIterator << endl;
			break;
		case 20:
			cout << "Is the iterator standing on the rend?: ";
			it = A.rend();
			cout << (myIterator == it) << endl;
			break;

		case 21:
			cout << "Is the iterator standing on the rbegin?: ";
			it = A.rbegin();
			cout << (myIterator != it) << endl;
			break;
		}
		variant = menu(1);
	}
	return 0;
}

int menu(bool j)
{
	int variant;
	if (j == 0)
	{
		std::cout << "___________Vector_____________" << std::endl;
		std::cout << "Select an action:" << std::endl;
		std::cout << "1. Show vector on console\n"
			<< "2. Vector's size\n"
			<< "3. Vector's capacity\n"
			<< "4. Empty\n"
			<< "5. Push back\n"
			<< "6. Pop back\n"
			<< "7. []\n"
			<< "8. reserve\n"
			<< "9. insert(position,value)\n"
			<< "10. insert(position,value, count)\n"
			<< "11. shrink_to_fit\n"
			<< "12. erase(*pos)\n"
			<< "13. clear\n"
			<< "14. at(position)\n"
			<< "Iterator\n"
			<< "15. iterator = begin())\n"
			<< "16. iterator = end()\n"
			<< "17. iterator++\n"
			<< "18. iterator--\n"
			<< "19. *iterator\n"
			<< "20. iterator.op==\n"
			<< "21. iterator.op!=\n"
			<< "22. Exit\n";
	}

	std::cout << std::endl << "command > ";
	std::cin >> variant;
	return variant;
}


#include <iostream>
#include <limits>
#include "task3,4,5.hpp"

using namespace std;

// ///task2//////
template<typename _CharT, typename _Traits> inline std::basic_ostream<_CharT, _Traits>& endll(std::basic_ostream<_CharT, _Traits>& __os) {
	return flush((__os.put(__os.widen('\n'))).put(__os.widen('\n')));
}

int main()
{
	// ///task1/////
	int a;

	while (true)
	{
		cout << "Enter an integer: ";
		cin >> a;

		if (cin.good() && cin.peek() == '\n')
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cout << "Incorrect number..." << endl << "Try again. ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Number " << a << " is correct!" << endll;

	std::cout << "First line" << endll << "Second line";
}

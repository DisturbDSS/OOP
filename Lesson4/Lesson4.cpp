
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <optional>


// /////task1///////////
class ArrayInt
{
private:
	int* m_data;
	int m_length;

	void swap(int& a, int& b) {
		int x = a;
		a = b;
		b = x;
	}
	void sort(int first, int last) {
		int i = first;
		int j = last;

		int x = m_data[(first + last) / 2];

		do
		{
			while (m_data[i] < x) i++;
			while (m_data[j] > x) j--;

			if (i <= j)
			{
				swap(m_data[i], m_data[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (i < last) sort(i, last);
		if (first < j) sort(first, j);
	}
public:
	ArrayInt() : m_length(0), m_data(nullptr) { }

	ArrayInt(int length) : m_length(length) {
		assert(length >= 0);

		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	int getSize() {
		return m_length;
	}
	void remove() {
		delete[] m_data;

		m_data = nullptr;
		m_length = 0;
	}
	void resize(int newLength) {
		if (newLength == m_length)
			return;

		if (newLength <= 0)
		{
			remove();
			return;
		}

		int* data = new int[newLength];

		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;

			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}
	void insertBefore(int value, int index) {
		assert(index >= 0 && index <= m_length);

		int* data = new int[m_length + 1];

		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];

		data[index] = value;

		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];

		delete[] m_data;
		m_data = data;
		++m_length;
	}
	void push_back(int value) {
		insertBefore(value, m_length);
	}
	void pop_back() {
		if (m_length == 0)
			return;

		resize(m_length - 1);
	}
	void pop_front() {
		if (m_length == 0)
			return;

		if (m_length - 1 == 0)
		{
			remove();
			return;
		}

		int* data = new int[m_length - 1];

		for (int index = 1; index < m_length; ++index)
			data[index - 1] = m_data[index];

		delete[] m_data;
		m_data = data;
		--m_length;
	}
	void sort() {
		sort(0, m_length - 1);
	}
	~ArrayInt() {
		delete[] m_data;
	}
	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	friend std::ostream& operator<<(std::ostream&, ArrayInt&);
};

std::ostream& operator<<(std::ostream& s, ArrayInt& f) {
	int length = f.getSize();

	for (int i = 0; i < length; ++i)
		s << f[i] << (((length == 1) || (length - 1 == i)) ? "" : ", ");

	return s;
}
// ////task2//////
//below
// ////task3/////
class Card {
private:
	enum class rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum class suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	rank m_rank;
	suit m_suit;
	bool m_isFaceUp;
public:
	int GetValue() const {
		int value = 0;
		if (m_isFaceUp)
		{
			value = (int)m_rank;
			if (value > 10)
			{
				value = 10;
			}
		}
		return value;
	}
	Card(Card::rank rank, Card::suit suit, bool isfup = true) : m_rank(rank), m_suit(suit), m_isFaceUp(isfup) { }
	void Flip() {
		m_isFaceUp = !m_isFaceUp;
	}
};
class Hand {
protected:
	//std::vector<std::string> v = { "ACE",  "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING" };
	std::vector<Card*>::iterator m_Cards;
public:
	void Add(Card* pCard);
	void Clear();
	int GetTotal() const;
	//to be continued
};


int main()
{

	// ///task1////////
	ArrayInt arr;

	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(2);
	arr.push_back(9);
	arr.push_back(2);

	std::cout << "Your array: " << arr << std::endl;

	arr.sort();

	std::cout << "Sorted array: " << arr << std::endl;

	arr.pop_front();

	std::cout << "Removed front: " << arr << std::endl;

	arr.pop_back();

	std::cout << "Removet back: " << arr << std::endl;

	// ///task2//////////
	{
		std::vector<int> v = { 0, 15, 3, -5, 4, -15, -1, 12, 12 };
		std::cout << "Array: ";
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl << "Array has " << v.size() << " numbers" << std::endl;
		std::set<int> c(v.begin(), v.end());
		std::cout << "Different numbers: "  << c.size() << ", same: " << v.size()  - c.size() <<  std::endl;
	}	

};
#include <iostream>
#include <vector>
#define PI 3.1415

using namespace std;

//////task1////////////////////////////////////////
float getRadian(float degree) {
	return PI / 180 * degree;
}

class Figure { /////////
public:
	virtual float area() = 0;
	virtual ~Figure() { };
};

class Parallelogram : public Figure { ////////
private:
	float m_side_a;
	float m_height;
protected:
	float getSideA() const {
		return m_side_a;
	}
	float getHeight() const {
		return m_height;
	}
public:
	Parallelogram(float side_a, float height)
		: m_side_a(side_a), m_height(height) { }

	float area() {
		float area = m_side_a * m_height;
		cout << "Parallelogram area: " << area << endl;

		return area;
	}
};

class Circle : public Figure { //////
private:
	float m_radius;
public:
	Circle(float radius) : m_radius(radius) { }
	float area() {
		float area = PI * pow(m_radius, 2);
		cout << "Circle area: " << area << endl;

		return area;
	}
};

class Rectangle : public Parallelogram { //////
public:
	Rectangle(float side_a, float height) : Parallelogram(side_a, height) { }

	float area() {
		float area = getSideA() * getHeight();
		cout << "Rectangle area: " << area << endl;

		return area;
	}
};

class Square : public Parallelogram { //////
public:
	Square(float side_a) : Parallelogram(side_a, side_a) { }

	float area() {
		float area = getSideA() * getSideA();
		cout << "Square area: " << area << endl;

		return area;
	}
};

class Rhombus : public Parallelogram { //////
public:
	Rhombus(float side_a, float height) : Parallelogram(side_a, height) { }

	float area() {
		float area = getSideA() * getHeight();
		cout << "Rhombus formula: " << area << endl;

		return area;
	}
};

/////////task2/////////////////////////////////////////
class Car {// ///////
private:
	std::string m_company;
	std::string m_model;
protected:
	std::string getCompany() const {
		return m_company;
	}
	std::string getModel() const {
		return m_model;
	}
public:
	Car(const std::string company, std::string model) : m_company(company), m_model(model) {
		cout << "Vehicle " + getCompany() + ", model " + getModel() << endl;
	}
};

class PassengerCar : virtual  public Car {// /////
public:
	PassengerCar(std::string company, std::string model) : Car(company, model) {
		cout << "Passenger Car " + getCompany() + ", model " + getModel() << endl;
	}
};

class Bus : virtual public Car {// /////
public:
	Bus(std::string company, std::string model) : Car(company, model) {
		cout << "Bus " + getCompany() + ", model " + getModel() << endl;
	}
};

class Minivan : public PassengerCar, public Bus {// ///
public:
	Minivan(std::string company, std::string model) : Car(company, model), PassengerCar(company, model), Bus(company, model) {
		cout << "Minivan " + getCompany() + ", model " + getModel() << endl;
	}
};

////////task3/////////////////////////////////////////
//Here could be task 3

/////////////task4/////////////////
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

int main()
{
	/////task1////////
	{
		vector<reference_wrapper<Figure>> f;

		Parallelogram parallelogram(4.6, 6);
		Circle circle(5.55);
		Rectangle rectangle(8, 4.4);
		Square square(10);
		Rhombus rhombus(17.4, 13.2);
		f.push_back(parallelogram);
		f.push_back(circle);
		f.push_back(rectangle);
		f.push_back(square);
		f.push_back(rhombus);

		for (reference_wrapper<Figure> c : f)
			c.get().area(); cout << endl;
	}
	//////task2///////
	{
		Minivan minivan("Toyota", "Sienna");
		Bus bus("Volvo", "8700");
		PassengerCar("Fiat", "Punto");
	}

}
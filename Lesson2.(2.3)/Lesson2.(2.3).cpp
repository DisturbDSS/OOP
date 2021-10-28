
#include <iostream>

//task2//
class Fruit 
{
private:
	std::string Name;
	std::string Color;
public:
	void setName(std::string name) {
		Name = name;
	}
	void setColor(std::string color) {
		Color = color;
	}
	const std::string& getName() const {
		return Name;
	}
	const std::string& getColor() const {
		return Color;
	}
};

class Apple : public Fruit {
public:
	Apple(std::string color = "") {
		if (color == "")
			color = "green";
		setName("apple");
		setColor(color);
	}
};

class Banana : public Fruit {
public:
	Banana(std::string color = "") {
		if (color == "")
			color = "yellow";
		setName("banana");
		setColor(color);
	}
};

class GrannySmith : public Apple {
public:
	GrannySmith() {
		setName("Granny Smith " + Apple::getName());
	}
};

int main()
{	//task2//
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
};
/*//Task3//
Реализация игры "Blackjack" потребует следующие обьекты:

	1-Игрок
	2-Дилер
	3-Карты

Ориентировочно, потребуется несколько классов:

	1-Персонаж (абстрактный класс)
		- Игрок (наследует абстрактный класс Игрок)
		- Дилер (наследует абстрактный класс Игрок)
	2-Карта
		- номинал
		- масть
	3-Колода
		- Массив ссылок на объекты класса Карта
	4-Рука (полученные карты)
		- массив ссылок на карты персонажей
	5-Игра
		- текущая Колода
		- текущий Дилер
		- текущий Игрок	
*/
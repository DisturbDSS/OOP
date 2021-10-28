
#include <iostream>
#include <cstdint>

class Power { //task1
private:
    int first;
    int second;
public:
    void set(int f, int s) {
        first = f;
        second = s;
    }

    void calculate() {
        std::cout << first << "^" << second << "= " << pow(first, second) << std::endl;
    }

};

class RGBA { //task2
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) { //constructor default
    }
    RGBA (int r, int g, int b, int a) { //constructor
        m_red = r;
        m_green = g;
        m_blue = b;
        m_alpha = a;
    }
    void print() {
        std::cout << "R= " << int(m_red) << std::endl
                  << "G= " << int(m_green) << std::endl
                  << "B= " << int(m_blue) << std::endl
                  << "A= " << int(m_alpha) << std::endl;
    }
};


class Stack {
private:
    size_t length;
    const static size_t size = 10;
    int array[size];
public:
    void reset() {
        for (int i = 0; i < size; i++) {
            array[i] = 0;
        }
        length = 0;
    };
    bool push(int val) {
        if (length < size)
        {
            array[length] = val;
            length++;
            return true;
        }
        return (false);
    };
    int pop() {
        if (length > 0)
        {
            int last = array[length];
            array[length] = 0;
            length--;
            return(last);
        }
        std::cout << "Stack is empty!" << std::endl;
    }; 
    void print() {
        for (int i = 0; i < length; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    };
};

void message() {
    std::cout << "Enter number: ";
};

int main()
{
    //task1
    int f, s;
    message();
    std::cin >> f;
    message();
    std::cin >> s;
    Power name; //object
    name.set(f, s);
    name.calculate();

    //tasl2
    RGBA light1(10, 20, 50, 210);
    light1.print();

    //task3
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;

}

#include <iostream>
#include <vector>

using namespace std;
// ///task1/////
template <typename T>
class Pair1 {
private:
    T m_first;
    T m_second;
public:
    Pair1(const T& first, const T& second) : m_first(first), m_second(second) { }

    const T& first() const;
    const T& second() const;
};

template <typename T>
const T& Pair1<T>::first() const {
    return m_first;
}

template <typename T>
const T& Pair1<T>::second() const {
    return m_second;
}

// ///task2/////
template <typename T1, typename T2>
class Pair {
private:
    T1 m_first;
    T2 m_second;
public:
    Pair(const T1& first, const T2& second) : m_first(first), m_second(second) { }

    const T1& first() const;
    const T2& second() const;
};

template <typename T1, typename T2>
const T1& Pair<T1, T2>::first() const {
    return m_first;
}

template <typename T1, typename T2>
const T2& Pair<T1, T2>::second() const {
    return m_second;
}

// ///task3/////
template <typename T2>
class StringValuePair : public Pair<std::string, T2> {
public:
    StringValuePair(const std::string& first, const T2& second) : Pair<std::string, T2>(first, second) {}
};

// ///task4/////
class Card {
public:
    enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
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
    std::vector<Card*> m_cards;
public:
    Hand() {
        m_cards.reserve(7);
    }

    virtual ~Hand() {
        Clear();
    }

    void Add(Card* pCard) {
        m_cards.push_back(pCard);
    }

    void Clear() {
        std::vector<Card*>::iterator itr = m_cards.begin();
        for (itr = m_cards.begin(); itr != m_cards.end(); ++itr)
        {
            delete* itr;
            *itr = nullptr;
        }

        m_cards.clear();
    }

    int GetTotal() const {
        if (m_cards.empty() || m_cards[0]->GetValue() == 0)
            return 0;

        int total = 0;
        std::vector<Card*>::const_iterator iter;

        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
            total += (*iter)->GetValue();

        bool containsAce = false;
        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
            if ((*iter)->GetValue() == Card::ACE)
                containsAce = true;

        if (containsAce && total <= 11) total += 10;

        return total;
    }
};
class GenericPlayer : public Hand {
protected:
    string m_name;
private:
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
    GenericPlayer(const string& name = "") : m_name(name) { }
    virtual ~GenericPlayer();

    virtual bool IsHitting() const = 0;

    bool IsBusted() const {
        return (GetTotal() > 21);
    }

    void Bust() const {
        cout << m_name << "Busted..." << endl;
    }
};



int main()
{
    // ///task1/////
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    /*Pair: 6 9
    Pair: 3.4 7.8*/

    // ///task2/////
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    /*Pair: 6 7.8
    Pair: 3.4 5*/

    // ///task3/////
    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}


#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ///task5/////
ostream& operator<<(ostream& os, const Card& a_Card) {
    const string Ranks[] = { "0" "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const string Suits[] = { "C", "D", "H", "S" };

    if (a_Card.m_isFaceUp)
        os << Ranks[a_Card.m_rank] << Suits[a_Card.m_suit];
    else
        os << "XX";

    return os;
}
// ///BlackJack/////
// ///task3,4 are below///
class Card {
public:
    enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
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

        if (containsAce && total <= 11) total = total + 10;

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
// ///task3/////
class Player : public GenericPlayer {
public:
    Player(const string& name = "") : GenericPlayer(m_name) { }

    virtual ~Player() { }

    virtual bool IsHitting() const {
        cout << m_name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }
    void Win() const {
        cout << m_name << " wins.\n";
    }
    void Lose() const {
        cout << m_name << " loses.\n";
    }
    void Push() const {
        cout << m_name << " pushes.\n";
    }
};
// ///task4/////
class House : public GenericPlayer {
public:
    House(const string& name = "House") : GenericPlayer(name) { }

    virtual ~House() { }
    virtual bool IsHitting() const {
        return (GetTotal() <= 16);
    }
    void FlipFirstCard()
    {
        if (!(m_cards.empty()))
            m_cards[0]->Flip();
        else
            cout << "None card to flip" << endl;
    }
};


#ifndef CARD_H
#define CARD_H

#include <QtGlobal>

class Card {
public:
    enum Value : quint8 { Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, ValueEnd };
    enum Suit : quint8 { Hearts, Clubs, Diamonds, Spades, SuitEnd };
private:
    Value value;
    Suit suit;
public:
    Card();
    Card(Value v, Suit s);
    Suit getSuit() const;
    Value getValue() const;
    quint8 getScore() const;
    QString getString() const;
};

Card::Value& operator++(Card::Value &value);
Card::Suit& operator++(Card::Suit &suit);

#endif // CARD_H

#include <QTextStream>
#include "card.h"

Card::Card() : value(Value::Ace), suit(Suit::Hearts) {

}

Card::Card(Value v, Suit s) : value(v), suit(s) {
    if (suit > Spades) {
        QString errMsg;
        errMsg += "Card(): suit '" + QString::number(suit) + "' out of range";
        throw std::range_error(errMsg.toStdString());
    } else if (value < Ace || value > King) {
        QString errMsg;
        errMsg += "Card(): value '" + QString::number(value) + "' out of range";
        throw std::range_error(errMsg.toStdString());
    }
}

Card::Suit Card::getSuit() const {
    return suit;
}

Card::Value Card::getValue() const {
    return value;
}

quint8 Card::getScore() const {
    if (value >= 10) {
        return 0;
    } else {
        return value;
    }
}

QString Card::getString() const {
    static const char valChar[] = { '\0', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
    static const char suitChar[] = { 'H', 'C', 'D', 'S' };
    QString str;
    str += valChar[value];
    str += suitChar[suit];
    return str;
}

Card::Value& operator++(Card::Value &value) {
    return value = Card::Value( static_cast<int>(value) + 1 );
}

Card::Suit& operator++(Card::Suit &suit) {
    return suit = Card::Suit( static_cast<int>(suit) + 1 );
}

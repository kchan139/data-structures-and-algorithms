#include <cmath>

Character::Character() 
{
    hp = x = y = 0;
}

Character::Character(int hp, int x, int y) : hp(hp), x(x), y(y) { }

int Character::getHp() 
{
    return hp;
}

void Character::setHp(int hp) 
{
    this->hp = hp;
}

int Character::getX() 
{
    return x;
}

void Character::setX(int x) 
{
    this->x = x;
}

int Character::getY() 
{
    return y;
}

void Character::setY(int y) 
{
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) 
{
    return sqrt(pow(other->getX() - x, 2)) + sqrt(pow(other->getY() - y, 2));
}
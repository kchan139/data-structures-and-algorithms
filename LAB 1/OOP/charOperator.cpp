// Copy all data from Character other
void Character::operator=(const Character& other) {
    // STUDENT ANSWER
    if (this == &other)
        return;
        
    hp = other.hp;
    x  = other.x;
    y  = other.y;
}

// Character a < Character b when a's hp is less than or equal b's hp
bool Character::operator<(const Character& other) {
    // STUDENT ANSWER
    return hp <= other.hp;
}

// Print data of the instance with format: hp-x-y
void Character::operator()() {
    // STUDENT ANSWER
    cout << hp << "-" << x << "-" << y;
}
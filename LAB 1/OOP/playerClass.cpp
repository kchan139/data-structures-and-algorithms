class Player : private Character {
public:
    Player() : Character() {}

    Player(int hp, int x, int y) : Character(hp, x, y) {}

    void printPlayerData() {
        cout << getHp() << "-" << getX() << "-" << getY() << endl;
    }

    void moveTo(int x, int y) {
        setX(x);
        setY(y);
    }
};
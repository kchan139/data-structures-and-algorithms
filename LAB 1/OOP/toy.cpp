enum Color { red, green, blue };
enum Size { small, medium, big };

class Toy
{
    protected:
        double price;

    public:
        Toy(double price)
        {
            this->price = price;
        }
        virtual void printType() = 0;
        friend class ToyBox;
};

class CarToy : public Toy
{
    private:
        Color color;

    public:
        CarToy(double price, Color color) : Toy (price)
        {
            this->color = color;
        }

        void printType()
        {
            cout << "This is a car toy\n";
        }

        friend class ToyBox;
};

class PuzzleToy : public Toy
{
    private:
        Size size;

    public:
        PuzzleToy(double price, Size size) : Toy(price)
        {
            this->size = size;
        }

        void printType()
        {
            cout << "This is a puzzle toy\n";
        }

        friend class ToyBox;
};

class ToyBox
{
    private:
        Toy * toyBox[5];
        int numberOfItems;

    public:
        ToyBox()
        {
            toyBox[0] = nullptr;
            numberOfItems = 0;
        }
        
        int addItem(CarToy & carToy)
        {
            if (numberOfItems == 5) return -1;
            
            toyBox[numberOfItems++] = &carToy;
            return numberOfItems;
        }
        
        int addItem(PuzzleToy & puzzleToy)
        {
            if (numberOfItems == 5) return -1;
            
            toyBox[numberOfItems++] = &puzzleToy;
            return numberOfItems;
        }
        
        void printBox()
        {
            for (int i = 0; i < numberOfItems; i++)
                toyBox[i]->printType();
        }
};
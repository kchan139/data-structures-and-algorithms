class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        title = authors = nullptr;
        publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear) 
    {
        this->title = new char[strlen(title) + 1];
        strcpy (this->title, title);
        
        this->authors = new char[strlen(authors) + 1];
        strcpy (this->authors, authors);
        
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        title = book.getTitle ();
        authors = book.getAuthors ();
        publishingYear = book.getPublishingYear();
    }
    
    void setTitle(const char* title)
    {
        this->title = new char[strlen(title) + 1];
        strcpy (this->title, title);
    }

    void setAuthors(const char* authors)
    {
        this->authors = new char[strlen(authors) + 1];
        strcpy (this->authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        return title;
    }

    char* getAuthors() const
    {
        return authors;
    }

    int getPublishingYear() const
    {
        return publishingYear;
    }

    ~Book()
    {
        //  delete [] title;
        //  delete [] authors;
        //  title = authors = nullptr;
        publishingYear = 0;
    }
    
    friend class Printer;
};

class Printer
{
public:
    static void printBook(const Book book)
    {
        /*
         * STUDENT ANSWER
         */
        cout << book.getTitle() << endl;


        if (book.getAuthors() != nullptr) 
        {
            string authors(book.getAuthors());
            istringstream ss(authors);
            string author;
            
            while (std::getline(ss, author, ','))
            {
                author.erase(0, author.find_first_not_of(" \t"));
                author.erase(author.find_last_not_of(" \t") + 1);
                
                cout << author << endl;
            }
        }

        cout << book.getPublishingYear() << endl;
    }
};
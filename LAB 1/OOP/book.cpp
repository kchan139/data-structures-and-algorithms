class Book
{
    private:
        char * title;
        char * authors;
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

        void printBook()
        {
            printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
        }
};
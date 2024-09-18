void Polynomial::insertTerm(const Term &term)
{
    // STUDENT ANSWER
    if (term.coeff == 0) return;
    if (this->terms->size() == 0)
        this->terms->add(term);
    else
    {
        int i = 0;
        for (SLinkedList<Term>::Iterator it = this->terms->begin(); it != this->terms->end(); ++it)
        {
            if (term.exp == (*it).exp)
            {
                (*it).coeff += term.coeff;
                if ((*it).coeff == 0) 
                    it.remove();
                break;
            }
            else if (term.exp > (*it).exp)
            {
                this->terms->add(i, term);
                break;
            }
            else if (i == this->terms->size() - 1) {
                this->terms->add(term);
                break;
            }
            ++i;
        }
    }
}

void Polynomial::insertTerm(double coeff, int exp)
{
    // STUDENT ANSWER
    Term tempTerm(coeff, exp);
    this->insertTerm(tempTerm);
}
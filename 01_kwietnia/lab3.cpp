template <typename Element>

class IList
{
public:
    virtual int add(int position) = 0;
    virtual void remove(int position) = 0;
    virtual Element get(int position) = 0;
    virtual int size() = 0;
};

class IStack
{
public:
    virtual int push(Element elem) = 0;
    virtual Element pop() = 0;
    virtual int size() = 0;
};

class Stack: public IList
{
public:
    int push(Element elem)
    {
        return IList::add(0);
    }
    
    void pop()
    {
        if(IList::size()==0) stderr<<"Pusty stos!";
        else return IList::remove(0);
    }
        
    int size()
    {
        return IList::size();   
    }  
};
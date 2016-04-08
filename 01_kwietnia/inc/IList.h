struct Node
{
	Node *nastepny;
	int element;	
};

class IList
{
public:
	virtual int add(int elem, int position) = 0;
	virtual Node remove(int position) = 0;
	virtual Node get(int position) = 0;
	virtual int size() = 0;
	virtual int wyszukaj(int szukana) = 0;
};

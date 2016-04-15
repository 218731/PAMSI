template <typename Element>

class Queue: public IList
{
public:
	int size()
	{
			 return IList::size();	 
	}	

	int push(Element elem)
	{
			 return IList::add(elem, 0); 
	}

	Element pop()
	{
			if(IList::size()==0) stderr<<"Pusta kolejka!";
			else return IList::remove(size());
	}				
};

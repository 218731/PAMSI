
using namespace std;

class Node
{
	Node *nastepny;
	string element;
};
	
class List: public IList
{
	int rozmiar;
	Node *poczatek;
public:
	
	List() {	poczatek=NULL; rozmiar=0;}
	
	int add(Node elem, int position)
	{
		if(position==0)
		{
			poczatek = &elem;
			rozmiar++;
			return 0;
		}
		
		if(position<=rozmiar+1)
		{
			Node *temp = &poczatek;
			for (int i=1; i<position-1; i++)
				temp = temp.nastepny;
			elem.nastepny = *temp.nastepny;
			temp.nastepny = &elem;
			rozmiar++;
			return 0;
		}
		else return -1;
	}
	
	Node remove(int position)
	{
		if(rozmiar == 0) return -1;
		if(position<=rozmiar+1)
		{
			Node *temp = &poczatek;
			for (int i=1; i<position-1; i++)
				temp = temp.nastepny;
			temp.nastepny = *(*temp.nastepny).nastepny;
			
		}
	
	
	
	
	
	
	virtual Node get(int position) = 0;
	virtual int size() = 0;
};
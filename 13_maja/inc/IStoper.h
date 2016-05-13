/*klasa do obslugi funkcji pomiaru czasu wykonania operacji uzupelniania tablicy
	start() - pobranie czasu systemowego bezposrednio przed rozpoczeciem operacji
	stop() - pobranie czasu systemowego bezposrednio po zakonczeniu operacji
	getTime() - wyliczenie czasu wykonania operacji i zwrocenie go w sekundach
*/

class IStoper	//interfejs klasy Stoper
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual double getTime() = 0;
};
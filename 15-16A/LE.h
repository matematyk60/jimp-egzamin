


class LE {
public:
	LE(int rozm);

	~LE();

	int Rozmiar() const;

	int Licznik() const;

	int

private:
	int *tablica;
	//tablica na dane
	int rozmiar;
	//rozmiar tablicy
	int licznik;
	//ile miejsc zajętych
	LE *next;
};
	

//я лох (Прокопов Андрей)

#include <iostream>

class Squad {
	int archers, horsemans, spearmans;

	Squad(int archers, int horsemans, int spearmans) {
		this->archers = archers;
		this->horsemans = horsemans;
		this->spearmans = spearmans;
	}

	friend Squad operator+(const Squad& squad, int num) {
		return Squad(squad.archers + num, squad.horsemans + num, squad.spearmans + num);
	}

	friend Squad operator-(const Squad& squad, int num) {
		return Squad(squad.archers - num, squad.horsemans - num, squad.spearmans - num);
	}

	friend bool operator< (const Squad& squad_1, const Squad& squad_2) {
		return (squad_1.archers + squad_1.horsemans + squad_1.spearmans) < (squad_2.archers + squad_2.horsemans + squad_2.spearmans);
	}

	friend bool operator> (const Squad& squad_1, const Squad& squad_2) {
		return (squad_1.archers + squad_1.horsemans + squad_1.spearmans) > (squad_2.archers + squad_2.horsemans + squad_2.spearmans);
	}

	friend std::ostream& operator<< (std::ostream& out, const Squad& squad) {
		out << "\nArchers - " << squad.archers << "\nHorsemans - " << squad.horsemans << "\nSpearmans - " << squad.spearmans;
		return out;
	}

	friend std::istream& operator>> (std::istream& in, Squad& obj) {
		std::cout << "Enter archers: "; in >> obj.archers;
		std::cout << "Enter horsemans: "; in >> obj.horsemans;
		std::cout << "Enter spearmans: "; in >> obj.spearmans;
		return in;
	}
};

int main() {

	return 0;
}

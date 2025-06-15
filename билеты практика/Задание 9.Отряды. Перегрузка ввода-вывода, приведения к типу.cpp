#include <iostream>
#include <vector>

class Squad {
	int archers, spearmans, horsemans;
public:
	Squad(int archer, int spearman, int horseman) {
		this->archers = archer;
		this->spearmans = spearman;
		this->horsemans = horseman;
	}

	friend std::ostream& operator<< (std::ostream& out, const Squad& squad) {
		out << "Archers - " << squad.archers << ", Horsemans - " << squad.horsemans << ", Spearmans - " << squad.spearmans;
		return out;
	}

	friend std::istream& operator>> (std::istream& in, Squad& obj) {
		std::cout << "Enter archers: "; in >> obj.archers;
		std::cout << "Enter horsemans: "; in >> obj.horsemans;
		std::cout << "Enter spearmans: "; in >> obj.spearmans;
		return in;
	}

	int getAllSquad() const {
		return archers + spearmans + horsemans;
	}
};

int main() {
	system("chcp 1251"); system("cls");

	Squad s1 = Squad(10,10,10);
	Squad s2 = Squad(20,20,20);

	std::cin >> s1;
	std::cin >> s2;
	std::cout << std::endl << s1 << std::endl << s2;
}
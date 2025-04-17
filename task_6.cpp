//я лох (Прокопов Андрей)

#include <iostream>
#include <vector>

class Squad {
	int archers, horsemans, spearmans;

public:
	Squad() : archers(0), horsemans(0), spearmans(0) {}

	Squad(int archers, int horsemans, int spearmans) {
		this->archers = archers;
		this->horsemans = horsemans;
		this->spearmans = spearmans;
	}

	friend Squad operator+(Squad& squad,Squad& squad2) {
		return Squad(squad.archers + squad2.archers, squad.horsemans + squad2.horsemans, squad.spearmans + squad2.spearmans);
	}

	friend void operator-(Squad& squad, Squad& squad2) {
		if (squad.archers > squad2.archers) {
			squad.archers -= squad2.archers;
		}
		else {
			squad2.archers -= squad.archers;
		}

		if (squad.horsemans > squad2.horsemans) {
			squad.horsemans -= squad2.horsemans;
		}
		else {
			squad2.horsemans -= squad.horsemans;
		}

		if (squad.spearmans > squad2.spearmans) {
			squad.spearmans -= squad2.spearmans;
		}
		else {
			squad2.spearmans -= squad.spearmans;
		}
	}

	friend bool operator< (const Squad& squad_1, const Squad& squad_2) {
		return (squad_1.archers + squad_1.horsemans + squad_1.spearmans) < (squad_2.archers + squad_2.horsemans + squad_2.spearmans);
	}

	friend bool operator> (const Squad& squad_1, const Squad& squad_2) {
		return (squad_1.archers + squad_1.horsemans + squad_1.spearmans) > (squad_2.archers + squad_2.horsemans + squad_2.spearmans);
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
};

struct TwoSquads {
	Squad squad_1;
	Squad squad_2;
};

int main() {
	system("chcp 1251"); system("cls");
	Squad first_squad(10,10,10), second_squad(15,5,7);
	std::vector<Squad>squads;
	squads.push_back(first_squad);
	squads.push_back(second_squad);
	int blades,a ,b;
	do {
		system("pause"); system("cls");
		for (int i = 0; i < squads.size(); i++) {
			std::cout << i << ". " << squads.at(i) << std::endl;
		}
		std::cout << "\n\n1.Создать пустой отряд\n2.Объединить отряды\n3.Столкнуть отряды\n4.Сравнить отряды(больше)\n5.Сравнить отряды(меньше)\n6.Редактировать отряд\n>_";
		std::cin >> blades;
		switch (blades) {
		case 1: {
			squads.push_back(Squad());
			break;
		}
		case 2: {
			std::cout << "Введите индекс первого отряда: "; std::cin >> a;
			std::cout << "Введите индекс второго отряда: "; std::cin >> b;
			squads.push_back(squads.at(a) + squads.at(b));
			squads.erase(squads.begin());
			squads.erase(squads.begin());
			break;
		}
		case 3: {
			std::cout << "Введите индекс первого отряда: "; std::cin >> a;
			std::cout << "Введите индекс второго отряда: "; std::cin >> b;
			squads.at(a) - squads.at(b);
			break;
		}
		case 4: {
			std::cout << "Введите индекс первого отряда: "; std::cin >> a;
			std::cout << "Введите индекс второго отряда: "; std::cin >> b;
			if (squads.at(a) > squads.at(b))
				std::cout << "Отряд " << a << " больше";
			else 
				std::cout << "Отряд " << b << " больше";
			break;
		}
		case 5: {
			std::cout << "Введите индекс первого отряда: "; std::cin >> a;
			std::cout << "Введите индекс второго отряда: "; std::cin >> b;
			if (squads.at(a) < squads.at(b))
				std::cout << "Отряд " << a << " меньше";
			else
				std::cout << "Отряд " << b << " меньше";
			break;
		}
		case 6: {
			std::cout << "Введите индекс отряда: "; std::cin >> a;
			std::cin >> squads.at(a);
			break;

		}
		}
	} while (true);
	return 0;
}

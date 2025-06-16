#include <iostream>
#include <vector>

class Squad {
	int archers, spearmans, horsemans;
public:
	Squad(int archers, int spearmans, int horsemans) {
		this->archers = archers;
		this->spearmans = spearmans;
		this->horsemans = horsemans;
	}

	friend Squad operator+(Squad& squad1, Squad& squad2) {
		int archers = squad1.archers + squad2.archers;
		int spearmans = squad1.spearmans + squad2.spearmans;
		int horsemans = squad1.horsemans + squad2.horsemans;
		Squad new_squad = Squad(archers, spearmans, horsemans);
		squad1.archers = 0;
		squad1.spearmans = 0;
		squad1.horsemans = 0;
		squad2.archers = 0;
		squad2.spearmans = 0;
		squad2.horsemans = 0;
		return new_squad;
	}

	friend void operator-(Squad& squad1, Squad& squad2) {
		int sq1 = squad1.archers + squad1.spearmans + squad1.horsemans;
		int sq2 = squad2.archers + squad2.spearmans + squad2.horsemans;
	
		if (sq1 > sq2) {
			squad1.archers -= squad2.archers; squad2.archers = 0;
			squad1.spearmans -= squad2.spearmans; squad2.spearmans = 0;
			squad1.horsemans -= squad2.horsemans; squad1.horsemans = 0;
		}
		else if (sq1 < sq2) {
			squad2.archers -= squad1.archers; squad2.archers = 0;
			squad2.spearmans -= squad1.spearmans; squad2.spearmans = 0;
			squad2.horsemans -= squad1.horsemans; squad2.horsemans = 0;
		}
		else if (sq1 == sq2) {
			squad1.archers = 0; squad2.archers = 0;
			squad1.spearmans = 0; squad2.spearmans = 0;
			squad1.horsemans = 0; squad2.horsemans = 0;
		}
	}

	friend bool operator== (Squad& squad1, Squad& squad2) {
		int sq1 = squad1.archers + squad1.spearmans + squad1.horsemans;
		int sq2 = squad2.archers + squad2.spearmans + squad2.horsemans;
		if (sq1 == sq2) return true;
		else return false;
	}

	void info() {
		std::cout << "archers - " << archers << " spearmans - " << spearmans << " horsemans - " << horsemans << std::endl << std::endl;
	}
};

int main() {
	Squad s1 = Squad(11, 12, 13);
	Squad s2 = Squad(10, 11, 12);

	(s1 + s2).info();
	s1 = Squad(11, 12, 13);
	s2 = Squad(10, 11, 12);
	s1 - s2;
	s1.info(); s1.info();
	bool isEqual = s1 == s2;
	std::cout << isEqual;
}
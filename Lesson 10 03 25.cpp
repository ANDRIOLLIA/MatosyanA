#include <iostream>

class Monitor {
	std::string manufacture, resolution, color;
	int diag;
	Monitor() {
		manufacture = "noname"; diag = -1; resolution = "undefined"; color = "none";
	}
	Monitor(std::string _manufacture) :Monitor() { manufacture = _manufacture; };
	Monitor(std::string _manufacture, int _diag) :Monitor(_manufacture) { diag = _diag; };
	Monitor(std::string _manufacture, int _diag, std::string _resolution) :Monitor(_manufacture, _diag) { resolution = _resolution; };
	Monitor(std::string _manufacture, int _diag, std::string _resolution, std::string _color) :
		manufacture(manufacture), diag(diag), resolution{ resolution }, color{ color } {}
};
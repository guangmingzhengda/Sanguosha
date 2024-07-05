#include"../../inc/game/Paidui.h"
#include<vector>
#include<algorithm>
#include<time.h>
#include"../../inc/Globals.h"

Paidui::Paidui() {
	std::vector<Kapai> v;
	_v = v;
}

Paidui::Paidui(std::vector<Kapai> v)
	: _v(v) {
}

Paidui* Paidui::Shuffle() {
	srand((unsigned int)time(NULL));
	std::random_shuffle(_v.begin(),_v.end());
	return this;
}
Kapai Paidui::GetFirst() {
	if ((int)_v.size() == 0) {
		New();
	}
	Kapai top = _v.back();
	_v.pop_back();
	return top;
}
Paidui* Paidui::New() {
	_v.clear();
	Paidui *qi = GetQipaidui();
	for (Kapai x : qi->_v) {
		_v.push_back(x);
	}
	qi->_v.clear();
	return this;
}
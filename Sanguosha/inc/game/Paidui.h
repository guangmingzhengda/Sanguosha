#pragma once
#ifndef _PAIDUI_H_
#define _PAIDUI_H_

#include"../Defines.h"
#include<string>
#include<map>
#include<set>
#include<vector>
class Paidui {
public:
	std::vector<Kapai> _v;

public:
	Paidui();
	Paidui(std::vector<Kapai> v);
	virtual ~Paidui() = default;
	Paidui* Shuffle();
	Paidui* New();
	Kapai GetFirst();
//	virtual void Draw() = 0;
};

#endif
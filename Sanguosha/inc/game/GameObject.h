#pragma once
#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include"../Defines.h"
#include<string>
#include<map>
#include<set>
#include<vector>
class GameObject {
public:
	int _hp;
	int _shangxian;
	int _sha;
	std::wstring _wujiang;
	std::wstring _zhongwen;
	std::vector<Kapai> _shoupai;
	Kapai _wuqi;
	Kapai _fangjv;
	Kapai _yanshi1,_yanshi2;

public:
	GameObject();
	GameObject(int hp, int shangxian, std::wstring wujiang, std::vector<Kapai> shoupai,
		Kapai wuqi, Kapai fangjv);
	virtual ~GameObject() = default;
	void ChangeHp(const int& hp,int t);
	void UseWuqi(const Kapai& _wuqi,int t);
	void UseFangjv(const Kapai& fangjv,int t);
	void Mopai(int k, int t);//摸k张牌
	void Qipai(int t);//弃置1张牌
	bool UseShoupai(int k, int t);//使用第k张手牌
	Kapai GetKapai(int k, int t);
	std::vector<Kapai>::iterator GetIt(int k, int t);//获取第k张牌的迭代器
	void Del(std::vector<Kapai>::iterator it, int t);//删除指定迭代器位置的手牌
	Kapai Panding(int t);
	bool AskSha(int k,int t);
	bool AskShan(int k,int t);
	bool AskShui(int t);
	bool AskWuxie(int t);
	bool AskTao(int t);

//	void Useshoupai(const Kapai& shoupai,int t);
	bool Jianxiong(const Kapai& Shanghai,int t);//曹操
	void Biyue(int t);//貂蝉 OK
	void Wanrong(int t);//大乔 OK
	void Tiandu(const Kapai& Pandingpai,int t);//郭嘉 OK
	void Yiji(int t);//郭嘉 OK
	void Jizhi(int t);//黄月英 OK
	void Lianying(int t);//陆逊 OK
	void Fankui(int t);//司马懿 
	void Xiaoji(int t);//孙尚香 OK
	void Luoshen(int t);
	void Yingzi(int t);//周瑜 OK
	void Fanjian(int t);
	void Fanjiandiannao(int t);
	virtual void Draw(int t);
};

#endif
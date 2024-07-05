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
	void Mopai(int k, int t);//��k����
	void Qipai(int t);//����1����
	bool UseShoupai(int k, int t);//ʹ�õ�k������
	Kapai GetKapai(int k, int t);
	std::vector<Kapai>::iterator GetIt(int k, int t);//��ȡ��k���Ƶĵ�����
	void Del(std::vector<Kapai>::iterator it, int t);//ɾ��ָ��������λ�õ�����
	Kapai Panding(int t);
	bool AskSha(int k,int t);
	bool AskShan(int k,int t);
	bool AskShui(int t);
	bool AskWuxie(int t);
	bool AskTao(int t);

//	void Useshoupai(const Kapai& shoupai,int t);
	bool Jianxiong(const Kapai& Shanghai,int t);//�ܲ�
	void Biyue(int t);//���� OK
	void Wanrong(int t);//���� OK
	void Tiandu(const Kapai& Pandingpai,int t);//���� OK
	void Yiji(int t);//���� OK
	void Jizhi(int t);//����Ӣ OK
	void Lianying(int t);//½ѷ OK
	void Fankui(int t);//˾��ܲ 
	void Xiaoji(int t);//������ OK
	void Luoshen(int t);
	void Yingzi(int t);//��� OK
	void Fanjian(int t);
	void Fanjiandiannao(int t);
	virtual void Draw(int t);
};

#endif
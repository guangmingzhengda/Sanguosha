#pragma once

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <easyx.h>
#include"../inc/ui/Application.h"
#include"../inc/Sound.h"
#include"game/Paidui.h"
#include"game/GameObject.h"
#include<map>
#include<string>
#include "Sound.h"


void QuickText(std::wstring text, int x1, int y1, int x2, int y2, int siz,int type);

void DrawKapai(Kapai pai, int x, int y);

extern std::set<std::wstring> kapai_set;
extern std::map<std::wstring, int> pri;
extern std::map<std::wstring, int> kin;
extern std::map<std::wstring, int> shun;
void init_pri();
void init_set();

bool cmp_qi(const Kapai c, const Kapai d);
bool cmp_chu(const Kapai c, const Kapai d);
std::map<std::wstring, std::wstring>* GetTrans();

class Application;

Application* GetApplication();

extern bool isRunning;

extern bool isRunning;

extern int Win;

extern IMAGE background;

class Paidui;

Paidui* GetQipaidui();

Paidui* GetMopaidui();

class GameObject;

GameObject* GetGameObject(int t);


const int SINGLE_PLAYER = 0;
const int DOUBLE_PLAYER = 1;


extern int gameMode;

// image resource
extern IMAGE batImage;
extern IMAGE ballImage;

// sound resource
extern FmodSound Biyue1;
extern FmodSound Biyue2;
extern FmodSound Botu1;
extern FmodSound Botu2;
extern FmodSound Fanjian1;
extern FmodSound Fanjian2;
extern FmodSound Fankui1;
extern FmodSound Fankui2;
extern FmodSound Ganglie1;
extern FmodSound Ganglie2;
extern FmodSound Guanxing1;
extern FmodSound Guanxing2;
extern FmodSound Guicai1;
extern FmodSound Guicai2;
extern FmodSound Guose1;
extern FmodSound Guose2;
extern FmodSound Jianxiong1;
extern FmodSound Jianxiong2;
extern FmodSound Jizhi1;
extern FmodSound Jizhi2;
extern FmodSound Kongcheng1;
extern FmodSound Kongcheng2;
extern FmodSound Kurou1;
extern FmodSound Kurou2;
extern FmodSound Lianying1;
extern FmodSound Lianying2;
extern FmodSound Longdan1;
extern FmodSound Longdan2;
extern FmodSound Luoshen1;
extern FmodSound Luoshen2;
extern FmodSound Luoyi1;
extern FmodSound Luoyi2;
extern FmodSound Paoxiao1;
extern FmodSound Paoxiao2;
extern FmodSound Qianxun1;
extern FmodSound Qianxun2;
extern FmodSound Qingguo1;
extern FmodSound Qingguo2;
extern FmodSound Qixi1;
extern FmodSound Qixi2;
extern FmodSound Renwang1;
extern FmodSound Renwang2;
extern FmodSound Shenju1;
extern FmodSound Shenju2;
extern FmodSound Tiandu1;
extern FmodSound Tiandu2;
extern FmodSound Tieji1;
extern FmodSound Tieji2;
extern FmodSound Tuxi1;
extern FmodSound Tuxi2;
extern FmodSound Wanrong1;
extern FmodSound Wanrong2;
extern FmodSound Wusheng1;
extern FmodSound Wusheng2;
extern FmodSound Wushuang1;
extern FmodSound Wushuang2;
extern FmodSound Xiaoji1;
extern FmodSound Xiaoji2;
extern FmodSound Xiechan1;
extern FmodSound Xiechan2;
extern FmodSound Yiji1;
extern FmodSound Yiji2;
extern FmodSound Yingzi1;
extern FmodSound Yingzi2;
extern FmodSound Yinli1;
extern FmodSound Yinli2;
extern FmodSound Zhiheng1;
extern FmodSound Zhiheng2;

extern FmodSound Baguazhen1;
extern FmodSound Bingliangcunduan1;
extern FmodSound Guanshifu1;
extern FmodSound Guohechaiqiao1;
extern FmodSound Hanbingjian1;
extern FmodSound Juedou1;
extern FmodSound Lebusishu1;
extern FmodSound Nanmanruqin1;
extern FmodSound Qinggangjian1;
extern FmodSound Renwangdun1;
extern FmodSound Sha1;
extern FmodSound Shan1;
extern FmodSound Shuiyanqijun1;
extern FmodSound Shunshouqianyang1;
extern FmodSound Tao1;
extern FmodSound Wanjianqifa1;
extern FmodSound Wuxiekeji1;
extern FmodSound Wuzhongshengyou1;
extern FmodSound Zhangbashemao1;
extern FmodSound Zhugeliannu1;

extern FmodSound Equipwuqi;
extern FmodSound Equipfangjv;
extern FmodSound Damage;

extern FmodSound Caocao1;
extern FmodSound Daqiao1;
extern FmodSound Diaochan1;
extern FmodSound Ganning1;
extern FmodSound Guanyu1;
extern FmodSound Guojia1;
extern FmodSound Huanggai1;
extern FmodSound Huangyueying1;
extern FmodSound Liubei1;
extern FmodSound Luxun1;
extern FmodSound Lvbu1;
extern FmodSound Lvmeng1;
extern FmodSound Machao1;
extern FmodSound Simayi1;
extern FmodSound Sunquan1;
extern FmodSound Sunshangxiang1;
extern FmodSound Xiahoudun1;
extern FmodSound Xuchu1;
extern FmodSound Zhangfei1;
extern FmodSound Zhangliao1;
extern FmodSound Zhaoyun1;
extern FmodSound Zhenji1;
extern FmodSound Zhouyu1;
extern FmodSound Zhugeliang1;
#endif
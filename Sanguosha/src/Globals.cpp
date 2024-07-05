#include"../inc/Globals.h"
#include"../inc/ui/Application.h"
#include"../inc/game/GameObject.h"
#include"../inc/utils/image.h"
#include<string>
#include<map>
#include<vector>
#include<easyx.h>


// sound resource

static Application application;

Application* GetApplication() {
	return &application;
}
static Paidui Mopaidui,Qipaidui;

IMAGE background;
IMAGE dizhi;

Paidui* GetQipaidui() {
	return &Qipaidui;
}

Paidui* GetMopaidui() {
	return &Mopaidui;
}

static GameObject Wanjia,Diannao;

GameObject* GetGameObject(int t) {
	if (t == 0) return &Diannao;
	else return &Wanjia;
}

static std::map<std::wstring, std::wstring> Trans;

std::map<std::wstring, std::wstring>* GetTrans() {
	return &Trans;
}

bool isRunning = 1;

int Win = -1;

//文本 左上右下坐标 是否换行
void QuickText(std::wstring text, int x1, int y1, int x2, int y2, int siz,int type) {
	RECT rect{ x1,y1,x2,y2 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(siz, 0, L"STXINWEI");
	if (type == 1) drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER);
	else if (type == 0) drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	else drawtext(text.c_str(), &rect,DT_VCENTER);
}

void DrawKapai(Kapai pai, int x, int y) {

	std::wstring s = pai.zhongwen;
	std::wstring Lujing = L"res/" + pai.name + L".png";
	IMAGE Shoupai;
	//				QuickText(s.c_str(), 160+ i * 80, 25 + 350, 160 + (i + 1) * 80, 25+112 + 350, 30, 1);
	loadimage(&Shoupai, Lujing.c_str(), 80, 112, 1);
	PutAlphaImage(nullptr, x, y, &Shoupai);
	Lujing = L"res/";
	Lujing += char(pai.huase + 48);
	Lujing += L".png";
	loadimage(&Shoupai, Lujing.c_str(), 8, 8, 1);
	PutAlphaImage(nullptr, x + 5, y + 13, &Shoupai);
	Lujing = L"res/";
	Lujing += char((pai.huase & 1) + 48);
	Lujing += '_';
	if (pai.dianshu < 10) Lujing += char(pai.dianshu + 48);
	else {
		Lujing += '1';
		Lujing += char(pai.dianshu % 10 + 48);
	}
	Lujing += L".png";
	//				QuickText(Lujing.c_str(), 200, 200, 500, 500, 80, 0);
	loadimage(&Shoupai, Lujing.c_str(), 8, 8, 1);
	PutAlphaImage(nullptr, x + 5, y + 5, &Shoupai);
}

std::map<std::wstring, int> pri;
std::map<std::wstring, int> kin;
std::map<std::wstring, int> shun;
std::set<std::wstring> kapai_set;
bool cmp_qi(const Kapai c, const Kapai d) {
	return pri[c.name] * kin[c.name] < pri[d.name] * kin[d.name];
}
bool cmp_chu(const Kapai c, const Kapai d) {
	return shun[c.name] < shun[d.name];
}
//Sha
//kin:1:杀 2:闪 3:桃 4:顺拆无中 5:兵乐 6:南万决斗水淹 7:仁王八卦 8:无懈 9:斧子寒冰剑青钢剑丈八AK
//shun:1:顺拆无中 2:南万决斗水淹 3:武器 4:杀 5:兵乐 6:仁王八卦 7:桃 8:无懈 9:闪
void init_set() {
	kapai_set.insert(L"Sha"); kapai_set.insert(L"Shan"); kapai_set.insert(L"Tao");
	kapai_set.insert(L"Shunshouqianyang"); kapai_set.insert(L"Guohechaiqiao");
	kapai_set.insert(L"Wuzhongshengyou"); kapai_set.insert(L"Bingliangcunduan");
	kapai_set.insert(L"Le"); kapai_set.insert(L"Shan"); kapai_set.insert(L"Tao");
	kapai_set.insert(L"Shunshouqianyang"); kapai_set.insert(L"Guohechaiqiao");
	kapai_set.insert(L"Wuzhongshengyou"); kapai_set.insert(L"Bingliangcunduan");
	kapai_set.insert(L"Nanmanruqin"); kapai_set.insert(L"Juedou");
	kapai_set.insert(L"Shuiyanqijun"); kapai_set.insert(L"Renwangdun");
	kapai_set.insert(L"Baguazhen"); kapai_set.insert(L"Wuxiekeji");
	kapai_set.insert(L"Guanshifu"); kapai_set.insert(L"Hanbingjian");
	kapai_set.insert(L"Qinggangjian"); kapai_set.insert(L"Zhangbashemao");
	kapai_set.insert(L"Zhugeliannu");
}
void init_pri() {
	pri[L"Baguazhen"] = 8; kin[L"Baguazhen"] = 7;
	pri[L"Bingliangcunduan"] = 7; kin[L"Bingliangcunduan"] = 5;
	pri[L"Guanshifu"] = 2; kin[L"Guanshifu"] = 9;
	pri[L"Hanbingjian"] = 3; kin[L"Hanbingjian"] = 9;
	pri[L"Juedou"] = 4; kin[L"Juedou"] = 6;
	pri[L"Lebusishu"] = 6; kin[L"Lebusishu"] = 5;
	pri[L"Nanmanruqin"] = 5; kin[L"Namanruqin"] = 6;
	pri[L"Qinggangjian"] = 1; kin[L"Qinggangjian"] = 9;
	pri[L"Renwangdun"] = 8; kin[L"Renwangdun"] = 7;
	pri[L"Sha"] = 2; kin[L"Sha"] = 1;
	pri[L"Shan"] = 3; kin[L"Shan"] = 2;
	pri[L"Shuiyanqijun"] = 5; kin[L"Shuiyanqijun"] = 6;
	pri[L"Shunshouqianyang"] = 8; kin[L"Shunshouqianyang"] = 4;
	pri[L"Tao"] = 10; kin[L"Tao"] = 3;
	pri[L"Wanjianqifa"] = 4; kin[L"Wanjianqifa"] = 6;
	pri[L"Wuxikeji"] = 6; kin[L"Wuxiekeji"] = 8;
	pri[L"Wuzhongshengyou"] = 7; kin[L"Wuzhongshenyou"] = 4;
	pri[L"Zhangbashemao"] = 1; kin[L"Zhangbashemao"] = 9;
	pri[L"Zhugeliannu"] = 2; kin[L"Zhugeliannu"] = 9;
}
//pri[L"Baguazhen"] = 8; kin[L"Baguazhen"] = 6;
//pri[L"Bingliangcunduan"] = 7; kin[L"Bingliangcunduan"] = 5;
//pri[L"Guanshifu"] = 2; kin[L"Guanshifu"] = 3;
//pri[L"Hanbingjian"] = 3; kin[L"Hanbingjian"] = 3;
//pri[L"Juedou"] = 4; kin[L"Juedou"] = 2;
//pri[L"Lebusishu"] = 6; kin[L"Lebusishu"] = 5;
//pri[L"Nanmanruqin"] = 5; kin[L"Namanruqin"] = 2;
//pri[L"Qinggangjian"] = 1; kin[L"Qinggangjian"] = 3;
//pri[L"Renwangdun"] = 8; kin[L"Renwangdun"] = 6;
//pri[L"Sha"] = 2; kin[L"Sha"] = 4;
//pri[L"Shan"] = 3; kin[L"Shan"] = 9;
//pri[L"Shuiyanqijun"] = 5; kin[L"Shuiyanqijun"] = 2;
//pri[L"Shunshouqianyang"] = 8; kin[L"Shunshouqianyang"] = 1;
//pri[L"Tao"] = 10; kin[L"Tao"] = 7;
//pri[L"Wanjianqifa"] = 4; kin[L"Wanjianqifa"] = 2;
//pri[L"Wuxikeji"] = 6; kin[L"Wuxiekeji"] = 8;
FmodSound Biyue1;
FmodSound Biyue2;
FmodSound Botu1;
FmodSound Botu2;
FmodSound Fanjian1;
FmodSound Fanjian2;
FmodSound Fankui1;
FmodSound Fankui2;
FmodSound Ganglie1;
FmodSound Ganglie2;
FmodSound Guanxing1;
FmodSound Guanxing2;
FmodSound Guicai1;
FmodSound Guicai2;
FmodSound Guose1;
FmodSound Guose2;
FmodSound Jianxiong1;
FmodSound Jianxiong2;
FmodSound Jizhi1;
FmodSound Jizhi2;
FmodSound Kongcheng1;
FmodSound Kongcheng2;
FmodSound Kurou1;
FmodSound Kurou2;
FmodSound Lianying1;
FmodSound Lianying2;
FmodSound Longdan1;
FmodSound Longdan2;
FmodSound Luoshen1;
FmodSound Luoshen2;
FmodSound Luoyi1;
FmodSound Luoyi2;
FmodSound Paoxiao1;
FmodSound Paoxiao2;
FmodSound Qianxun1;
FmodSound Qianxun2;
FmodSound Qingguo1;
FmodSound Qingguo2;
FmodSound Qixi1;
FmodSound Qixi2;
FmodSound Renwang1;
FmodSound Renwang2;
FmodSound Shenju1;
FmodSound Shenju2;
FmodSound Tiandu1;
FmodSound Tiandu2;
FmodSound Tieji1;
FmodSound Tieji2;
FmodSound Tuxi1;
FmodSound Tuxi2;
FmodSound Wanrong1;
FmodSound Wanrong2;
FmodSound Wusheng1;
FmodSound Wusheng2;
FmodSound Wushuang1;
FmodSound Wushuang2;
FmodSound Xiaoji1;
FmodSound Xiaoji2;
FmodSound Xiechan1;
FmodSound Xiechan2;
FmodSound Yiji1;
FmodSound Yiji2;
FmodSound Yingzi1;
FmodSound Yingzi2;
FmodSound Yinli1;
FmodSound Yinli2;
FmodSound Zhiheng1;
FmodSound Zhiheng2;

FmodSound Baguazhen1;
FmodSound Bingliangcunduan1;
FmodSound Guanshifu1;
FmodSound Guohechaiqiao1;
FmodSound Hanbingjian1;
FmodSound Juedou1;
FmodSound Lebusishu1;
FmodSound Nanmanruqin1;
FmodSound Qinggangjian1;
FmodSound Renwangdun1;
FmodSound Sha1;
FmodSound Shan1;
FmodSound Shuiyanqijun1;
FmodSound Shunshouqianyang1;
FmodSound Tao1;
FmodSound Wanjianqifa1;
FmodSound Wuxiekeji1;
FmodSound Wuzhongshengyou1;
FmodSound Zhangbashemao1;
FmodSound Zhugeliannu1;

FmodSound Equipwuqi;
FmodSound Equipfangjv;
FmodSound Damage;

FmodSound Caocao1;
FmodSound Daqiao1;
FmodSound Diaochan1;
FmodSound Ganning1;
FmodSound Guanyu1;
FmodSound Guojia1;
FmodSound Huanggai1;
FmodSound Huangyueying1;
FmodSound Liubei1;
FmodSound Luxun1;
FmodSound Lvbu1;
FmodSound Lvmeng1;
FmodSound Machao1;
FmodSound Simayi1;
FmodSound Sunquan1;
FmodSound Sunshangxiang1;
FmodSound Xiahoudun1;
FmodSound Xuchu1;
FmodSound Zhangfei1;
FmodSound Zhangliao1;
FmodSound Zhaoyun1;
FmodSound Zhenji1;
FmodSound Zhouyu1;
FmodSound Zhugeliang1;
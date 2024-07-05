#include<Windows.h>
#include<easyx.h>
#include<stdio.h>
#include"../inc/Message.h"
#include"../inc/Defines.h"
#include"../inc/Globals.h"
#include"../inc/ui/Button.h"
#include"../inc/ui/Interface.h"
#include"../inc/ui/Application.h"
#include"../inc/utils/image.h"
#include"../inc/Sound.h"
#include<cstdio>
#pragma comment(lib,"Winmm.lib")

void Init();
void Init_paidui();
void Init_Sound();
int APIENTRY WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {
	initgraph(1000, 560);
	Init();
	mciSendString(_T("close bkmusic"), NULL, 0, NULL);
	mciSendString(_T("open res/start.mp3 alias bkmusic"), NULL, 0, NULL);//²¥·ÅÒôÀÖ
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);//Ñ­»·²¥·Å

//	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	BeginBatchDraw();
//	Sleep(2000);
	Application* app = GetApplication();
	while (isRunning) {
		cleardevice();

		PeekMouseMessage();
		if (IsKeyDown(VK_Q)) {
			break;
		}
		app->Update();
		UpdateFmodSystem();

		app->Draw();

		FlushBatchDraw();
		
		Sleep(20);
	}
	EndBatchDraw();
	closegraph();
	return 0;
}

void Init() {
	//struct Kapai {
	//	std::wstring name;
	//	std::wstring zhongwen;
	//	int dianshu;
	//	int huase;//0123ºÚºìÃ··½
	//	int type;//0123»ù±¾½õÄÒÎäÆ÷·À¾ß
	//	bool operator < (const Kapai& rhs) const {
	//		return rhs.name < name;
	//	}
	//};
	InitFmodSystem();
	loadimage(&background, L"res/ol_bg.jpg", 1000, 560, 1);
	PutAlphaImage(nullptr, 0, 0, &background);
	Init_paidui();
	Init_Sound();

	std::map<std::wstring, std::wstring>* mp = GetTrans();
	mp->insert({ L"Fangjvlan", L"ÎÞ·À¾ß" });
//	Trans[L"Wufangjv"] = L"ÎÞ·À¾ß";
//	Trans[L"Wuwuqi"] = L"ÎÞÎäÆ÷";
	Application* app = GetApplication();
	app->RegisterInterface(new MainInterface())
		->RegisterInterface(new GameInterface())
		->RegisterInterface(new IllustrationInterface())
		->RegisterInterface(new RulesInterface())
		->RegisterInterface(new WujiangInterface())
		->RegisterInterface(new Caocao())
		->RegisterInterface(new Sunquan())
		->RegisterInterface(new Sunshangxiang())
		->RegisterInterface(new Diaochan())
		->RegisterInterface(new Lvbu())
		->RegisterInterface(new Zhenji())
		->RegisterInterface(new Guojia())
		->RegisterInterface(new Xuchu())
		->RegisterInterface(new Zhangliao())
		->RegisterInterface(new Xiahoudun())
		->RegisterInterface(new Simayi())
		->RegisterInterface(new Luxun())
		->RegisterInterface(new Daqiao())
		->RegisterInterface(new Zhouyu())
		->RegisterInterface(new Huanggai())
		->RegisterInterface(new Lvmeng())
		->RegisterInterface(new Ganning())
		->RegisterInterface(new Huangyueying())
		->RegisterInterface(new Machao())
		->RegisterInterface(new Zhaoyun())
		->RegisterInterface(new Zhugeliang())
		->RegisterInterface(new Zhangfei())
		->RegisterInterface(new Guanyu())
		->RegisterInterface(new Liubei())
		->RegisterInterface(new KapaiInterface())
		->RegisterInterface(new Sha())
		->RegisterInterface(new Shan())
		->RegisterInterface(new Tao())
		->RegisterInterface(new Shunshouqianyang())
		->RegisterInterface(new Guohechaiqiao())
		->RegisterInterface(new Juedou())
		->RegisterInterface(new Wuzhongshengyou())
		->RegisterInterface(new Wuxiekeji())
		->RegisterInterface(new Lebusishu())
		->RegisterInterface(new Binglaingcunduan())
		->RegisterInterface(new Nanmanruqin())
		->RegisterInterface(new Wanjianqifa())
		->RegisterInterface(new Shuiyanqijun())
		->RegisterInterface(new Guanshifu())
		->RegisterInterface(new Zhugeliannu())
		->RegisterInterface(new Hanbingjian())
		->RegisterInterface(new Zhangbashemao())
		->RegisterInterface(new Qinggangjian())
		->RegisterInterface(new Baguazhen())
		->RegisterInterface(new Renwangdun());
}
void Init_paidui() {
	Paidui* Mo = GetMopaidui();
	Kapai kapai1(L"Juedou", L"¾ö\n¶·", 1, 0, 1);
	Mo->_v.push_back(kapai1);
	Kapai kapai2(L"Baguazhen", L"°Ë\nØÔ\nÕó", 2, 0, 3);
	Mo->_v.push_back(kapai2);
	Kapai kapai3(L"Guohechaiqiao", L"¹ý\nºÓ\n²ð\nÇÅ", 3, 0, 1);
	Mo->_v.push_back(kapai3);
	Kapai kapai4(L"Shunshouqianyang", L"Ë³\nÊÖ\nÇ£\nÑò", 4, 0, 1);
	Mo->_v.push_back(kapai4);
	Kapai kapai5(L"Sha", L"É±", 5, 0, 0);
	Mo->_v.push_back(kapai5);
	Kapai kapai6(L"Qinggangjian", L"Çà\nâG\n½£", 6, 0, 2);
	Mo->_v.push_back(kapai6);
	Kapai kapai7(L"Sha", L"É±", 7, 0, 0);
	Mo->_v.push_back(kapai7);
	Kapai kapai8(L"Sha", L"É±", 8, 0, 0);
	Mo->_v.push_back(kapai8);
	Kapai kapai9(L"Hanbingjian", L"º®\n±ù\n½£", 9, 0, 2);
	Mo->_v.push_back(kapai9);
	Kapai kapai10(L"Sha", L"É±", 10, 0, 0);
	Mo->_v.push_back(kapai10);
	Kapai kapai11(L"Shunshouqianyang", L"Ë³\nÊÖ\nÇ£\nÑò", 11, 0, 1);
	Mo->_v.push_back(kapai11);
	Kapai kapai12(L"Zhangbashemao", L"ÕÉ\n°Ë\nÉß\nÃ¬", 12, 0, 2);
	Mo->_v.push_back(kapai12);
	Kapai kapai13(L"Nanmanruqin", L"ÄÏ\nÂù\nÈë\nÇÖ", 13, 0, 1);
	Mo->_v.push_back(kapai13);
	Kapai kapai14(L"Wanjianqifa", L"Íò\n¼ý\nÆë\n·¢", 1, 1, 1);
	Mo->_v.push_back(kapai14);
	Kapai kapai15(L"Shan", L"ÉÁ", 2, 1, 0);
	Mo->_v.push_back(kapai15);
	Kapai kapai16(L"Tao", L"ÌÒ", 3, 1, 0);
	Mo->_v.push_back(kapai16);
	Kapai kapai17(L"Tao", L"ÌÒ", 4, 1, 0);
	Mo->_v.push_back(kapai17);
	Kapai kapai18(L"Shan", L"ÉÁ", 5, 1, 0);
	Mo->_v.push_back(kapai18);
	Kapai kapai19(L"Lebusishu", L"ÀÖ\n²»\nË¼\nÊñ", 6, 1, 1);
	Mo->_v.push_back(kapai19);
	Kapai kapai20(L"Wuzhongshengyou", L"ÎÞ\nÖÐ\nÉú\nÓÐ", 7, 1, 1);
	Mo->_v.push_back(kapai20);
	Kapai kapai21(L"Wuzhongshengyou", L"ÎÞ\nÖÐ\nÉú\nÓÐ", 8, 1, 1);
	Mo->_v.push_back(kapai21);
	Kapai kapai22(L"Tao", L"ÌÒ", 9, 1, 0);
	Mo->_v.push_back(kapai22);
	Kapai kapai23(L"Sha", L"É±", 10, 1, 0);
	Mo->_v.push_back(kapai23);
	Kapai kapai24(L"Sha", L"É±", 11, 1, 0);
	Mo->_v.push_back(kapai24);
	Kapai kapai25(L"Guohechaiqiao", L"¹ý\nºÓ\n²ð\nÇÅ", 12, 1, 1);
	Mo->_v.push_back(kapai25);
	Kapai kapai26(L"Wuxiekeji", L"ÎÞ\nÐ¸\n¿É\n»÷", 13, 1, 1);
	Mo->_v.push_back(kapai26);
	Kapai kapai27(L"Juedou", L"¾ö¶·", 1, 2, 1);
	Mo->_v.push_back(kapai27);
	Kapai kapai28(L"Renwangdun", L"ÈÊ\nÍõ\n¶Ü", 2, 2, 3);
	Mo->_v.push_back(kapai28);
	Kapai kapai29(L"Guohechaiqiao", L"¹ý\nºÓ\n²ð\nÇÅ", 3, 2, 1);
	Mo->_v.push_back(kapai29);
	Kapai kapai30(L"Sha", L"É±", 4, 2, 0);
	Mo->_v.push_back(kapai30);
	Kapai kapai31(L"Sha", L"É±", 5, 2, 0);
	Mo->_v.push_back(kapai31);
	Kapai kapai32(L"Sha", L"É±", 6, 2, 0);
	Mo->_v.push_back(kapai32);
	Kapai kapai33(L"Shuiyanqijun", L"Ë®\nÑÍ\nÆß\n¾ü", 7, 2, 1);
	Mo->_v.push_back(kapai33);
	Kapai kapai34(L"Sha", L"É±", 8, 2, 0);
	Mo->_v.push_back(kapai34);
	Kapai kapai35(L"Sha", L"É±", 9, 2, 0);
	Mo->_v.push_back(kapai35);
	Kapai kapai36(L"Sha", L"É±", 10, 2, 0);
	Mo->_v.push_back(kapai36);
	Kapai kapai37(L"Sha", L"É±", 11, 2, 0);
	Mo->_v.push_back(kapai37);
	Kapai kapai38(L"Bingliangcunduan", L"±ø\nÁ¸\n´ç\n¶Ï", 12, 2, 1);
	Mo->_v.push_back(kapai38);
	Kapai kapai39(L"Wuxiekeji", L"ÎÞ\nÐ¸\n¿É\n»÷", 13, 2, 1);
	Mo->_v.push_back(kapai39);
	Kapai kapai40(L"Zhugeliannu", L"Öî\n¸ð\nÁ¬\nåó", 1, 3, 2);
	Mo->_v.push_back(kapai40);
	Kapai kapai41(L"Shan", L"ÉÁ", 2, 3, 0);
	Mo->_v.push_back(kapai41);
	Kapai kapai42(L"Shan", L"ÉÁ", 3, 3, 0);
	Mo->_v.push_back(kapai42);
	Kapai kapai43(L"Shunshouqianyang", L"Ë³\nÊÖ\nÇ£\nÑò", 4, 3, 1);
	Mo->_v.push_back(kapai43);
	Kapai kapai44(L"Guanshifu", L"¹á\nÊ¯\n¸«", 5, 3, 2);
	Mo->_v.push_back(kapai44);
	Kapai kapai45(L"Sha", L"É±", 6, 3, 0);
	Mo->_v.push_back(kapai45);
	Kapai kapai46(L"Shan", L"ÉÁ", 7, 3, 0);
	Mo->_v.push_back(kapai46);
	Kapai kapai47(L"Shan", L"ÉÁ", 8, 3, 0);
	Mo->_v.push_back(kapai47);
	Kapai kapai48(L"Sha", L"É±", 9, 3, 0);
	Mo->_v.push_back(kapai48);
	Kapai kapai49(L"Shan", L"ÉÁ", 10, 3, 0);
	Mo->_v.push_back(kapai49);
	Kapai kapai50(L"Shan", L"ÉÁ", 11, 3, 0);
	Mo->_v.push_back(kapai50);
	Kapai kapai51(L"Tao", L"ÌÒ",12, 3, 0);
	Mo->_v.push_back(kapai51);
	Kapai kapai52(L"Sha", L"É±", 13, 3, 0);
	Mo->_v.push_back(kapai52);
	Mo->Shuffle();
}
void Init_Sound() {

	//if(rand()&1) 
//	LoadFmodSound(&Zhiheng1, "res/music/skill/Zhiheng1.mp3");
	LoadFmodSound(&Biyue1, "res/music/skill/Biyue1.mp3");
	LoadFmodSound(&Biyue2, "res/music/skill/Biyue2.mp3");
	LoadFmodSound(&Botu1, "res/music/skill/Botu1.mp3");
	LoadFmodSound(&Botu2, "res/music/skill/Botu2.mp3");
	LoadFmodSound(&Fanjian1, "res/music/skill/Fanjian1.mp3");
	LoadFmodSound(&Fanjian2, "res/music/skill/Fanjian2.mp3");
	LoadFmodSound(&Fankui1, "res/music/skill/Fankui1.mp3");
	LoadFmodSound(&Fankui2, "res/music/skill/Fankui2.mp3");
	LoadFmodSound(&Ganglie1, "res/music/skill/Ganglie1.mp3");
	LoadFmodSound(&Ganglie2, "res/music/skill/Ganglie2.mp3");
	LoadFmodSound(&Guanxing1, "res/music/skill/Guanxing1.mp3");
	LoadFmodSound(&Guanxing2, "res/music/skill/Guanxing2.mp3");
	LoadFmodSound(&Guicai1, "res/music/skill/Guicai1.mp3");
	LoadFmodSound(&Guicai2, "res/music/skill/Guicai2.mp3");
	LoadFmodSound(&Guose1, "res/music/skill/Guose1.mp3");
	LoadFmodSound(&Guose2, "res/music/skill/Guose2.mp3");
	LoadFmodSound(&Jianxiong1, "res/music/skill/Jianxiong1.mp3");
	LoadFmodSound(&Jianxiong2, "res/music/skill/Jianxiong2.mp3");
	LoadFmodSound(&Jizhi1, "res/music/skill/Jizhi1.mp3");
	LoadFmodSound(&Jizhi2, "res/music/skill/Jizhi2.mp3");
	LoadFmodSound(&Kongcheng1, "res/music/skill/Kongcheng1.mp3");
	LoadFmodSound(&Kongcheng2, "res/music/skill/Kongcheng2.mp3");
	LoadFmodSound(&Kurou1, "res/music/skill/Kurou1.mp3");
	LoadFmodSound(&Kurou2, "res/music/skill/Kurou2.mp3");
	LoadFmodSound(&Lianying1, "res/music/skill/Lianying1.mp3");
	LoadFmodSound(&Lianying2, "res/music/skill/Lianying2.mp3");
	LoadFmodSound(&Longdan1, "res/music/skill/Longdan1.mp3");
	LoadFmodSound(&Longdan2, "res/music/skill/Longdan2.mp3");
	LoadFmodSound(&Luoshen1, "res/music/skill/Luoshen1.mp3");
	LoadFmodSound(&Luoshen2, "res/music/skill/Luoshen2.mp3");
	LoadFmodSound(&Luoyi1, "res/music/skill/Luoyi1.mp3");
	LoadFmodSound(&Luoyi2, "res/music/skill/Luoyi2.mp3");
	LoadFmodSound(&Paoxiao1, "res/music/skill/Paoxiao1.mp3");
	LoadFmodSound(&Paoxiao2, "res/music/skill/Paoxiao2.mp3");
	LoadFmodSound(&Qianxun1, "res/music/skill/Qianxun1.mp3");
	LoadFmodSound(&Qianxun2, "res/music/skill/Qianxun2.mp3");
	LoadFmodSound(&Qingguo1, "res/music/skill/Qingguo1.mp3");
	LoadFmodSound(&Qingguo2, "res/music/skill/Qingguo2.mp3");
	LoadFmodSound(&Qixi1, "res/music/skill/Qixi1.mp3");
	LoadFmodSound(&Qixi2, "res/music/skill/Qixi2.mp3");
	LoadFmodSound(&Renwang1, "res/music/skill/Renwang1.mp3");
	LoadFmodSound(&Renwang2, "res/music/skill/Renwang2.mp3");
	LoadFmodSound(&Shenju1, "res/music/skill/Shenju1.mp3");
	LoadFmodSound(&Shenju2, "res/music/skill/Shenju2.mp3");
	LoadFmodSound(&Tiandu1, "res/music/skill/Tiandu1.mp3");
	LoadFmodSound(&Tiandu2, "res/music/skill/Tiandu2.mp3");
	LoadFmodSound(&Tieji1, "res/music/skill/Tieji1.mp3");
	LoadFmodSound(&Tieji2, "res/music/skill/Tieji2.mp3");
	LoadFmodSound(&Tuxi1, "res/music/skill/Tuxi1.mp3");
	LoadFmodSound(&Tuxi2, "res/music/skill/Tuxi2.mp3");
	LoadFmodSound(&Wanrong1, "res/music/skill/Wanrong1.mp3");
	LoadFmodSound(&Wanrong2, "res/music/skill/Wanrong2.mp3");
	LoadFmodSound(&Wusheng1, "res/music/skill/Wusheng1.mp3");
	LoadFmodSound(&Wusheng2, "res/music/skill/Wusheng2.mp3");
	LoadFmodSound(&Wushuang1, "res/music/skill/Wushuang1.mp3");
	LoadFmodSound(&Wushuang2, "res/music/skill/Wushuang2.mp3");
	LoadFmodSound(&Xiaoji1, "res/music/skill/Xiaoji1.mp3");
	LoadFmodSound(&Xiaoji2, "res/music/skill/Xiaoji2.mp3");
	LoadFmodSound(&Xiechan1, "res/music/skill/Xiechan1.mp3");
	LoadFmodSound(&Xiechan2, "res/music/skill/Xiechan2.mp3");
	LoadFmodSound(&Yiji1, "res/music/skill/Yiji1.mp3");
	LoadFmodSound(&Yiji2, "res/music/skill/Yiji2.mp3");
	LoadFmodSound(&Yingzi1, "res/music/skill/Yingzi1.mp3");
	LoadFmodSound(&Yingzi2, "res/music/skill/Yingzi2.mp3");
	LoadFmodSound(&Yinli1, "res/music/skill/Yinli1.mp3");
	LoadFmodSound(&Yinli2, "res/music/skill/Yinli2.mp3");
	LoadFmodSound(&Zhiheng1, "res/music/skill/Zhiheng1.mp3");
	LoadFmodSound(&Zhiheng2, "res/music/skill/Zhiheng2.mp3");
	
	LoadFmodSound(&Baguazhen1, "res/music/card/Baguazhen.mp3");
	LoadFmodSound(&Bingliangcunduan1, "res/music/card/Bingliangcunduan.mp3");
	LoadFmodSound(&Guanshifu1, "res/music/card/Guanshifu.mp3");
	LoadFmodSound(&Guohechaiqiao1, "res/music/card/Guohechaiqiao.mp3");
	LoadFmodSound(&Hanbingjian1, "res/music/card/Hanbingjian.mp3");
	LoadFmodSound(&Juedou1, "res/music/card/Juedou.mp3");
	LoadFmodSound(&Lebusishu1, "res/music/card/Lebusishu.mp3");
	LoadFmodSound(&Nanmanruqin1, "res/music/card/Nanmanruqin.mp3");
	LoadFmodSound(&Qinggangjian1, "res/music/card/Qinggangjian.mp3");
	LoadFmodSound(&Renwangdun1, "res/music/card/Renwangdun.mp3");
	LoadFmodSound(&Sha1, "res/music/card/Sha.mp3");
	LoadFmodSound(&Shan1, "res/music/card/Shan.mp3");
	LoadFmodSound(&Shuiyanqijun1, "res/music/card/Shuiyanqijun.mp3");
	LoadFmodSound(&Shunshouqianyang1, "res/music/card/Shunshouqianyang.mp3");
	LoadFmodSound(&Tao1, "res/music/card/Tao.mp3");
	LoadFmodSound(&Wanjianqifa1, "res/music/card/Wanjianqifa.mp3");
	LoadFmodSound(&Wuxiekeji1, "res/music/card/Wuxiekeji.mp3");
	LoadFmodSound(&Wuzhongshengyou1, "res/music/card/Wuzhongshengyou.mp3");
	LoadFmodSound(&Zhangbashemao1, "res/music/card/Zhangbashemao.mp3");
	LoadFmodSound(&Zhugeliannu1, "res/music/card/Zhugeliannu.mp3");

	LoadFmodSound(&Damage, "res/music/effect/Damage.mp3");
	LoadFmodSound(&Equipwuqi, "res/music/effect/Equipwuqi.mp3");
	LoadFmodSound(&Equipfangjv, "res/music/effect/Equipfangjv.mp3");

	LoadFmodSound(&Caocao1, "res/music/die/Caocao.mp3");
	LoadFmodSound(&Daqiao1, "res/music/die/Daqiao.mp3");
	LoadFmodSound(&Diaochan1, "res/music/die/Diaochan.mp3");
	LoadFmodSound(&Ganning1, "res/music/die/Ganning.mp3");
	LoadFmodSound(&Guanyu1, "res/music/die/Guanyu.mp3");
	LoadFmodSound(&Guojia1, "res/music/die/Guojia.mp3");
	LoadFmodSound(&Huanggai1, "res/music/die/Huanggai.mp3");
	LoadFmodSound(&Huangyueying1, "res/music/die/Huangyueying.mp3");
	LoadFmodSound(&Liubei1, "res/music/die/Liubei.mp3");
	LoadFmodSound(&Luxun1, "res/music/die/Luxun.mp3");
	LoadFmodSound(&Lvbu1, "res/music/die/Lvbu.mp3");
	LoadFmodSound(&Lvmeng1, "res/music/die/Lvmeng.mp3");
	LoadFmodSound(&Machao1, "res/music/die/Machao.mp3");
	LoadFmodSound(&Simayi1, "res/music/die/Simayi.mp3");
	LoadFmodSound(&Sunquan1, "res/music/die/Sunquan.mp3");
	LoadFmodSound(&Sunshangxiang1, "res/music/die/Sunshangxiang.mp3");
	LoadFmodSound(&Xiahoudun1, "res/music/die/Xiahoudun.mp3");
	LoadFmodSound(&Xuchu1, "res/music/die/Xuchu.mp3");
	LoadFmodSound(&Zhangfei1, "res/music/die/Zhangfei.mp3");
	LoadFmodSound(&Zhangliao1, "res/music/die/Zhangliao.mp3");
	LoadFmodSound(&Zhaoyun1, "res/music/die/Zhaoyun.mp3");
	LoadFmodSound(&Zhenji1, "res/music/die/Zhenji.mp3");
	LoadFmodSound(&Zhouyu1, "res/music/die/Zhouyu.mp3");
	LoadFmodSound(&Zhugeliang1, "res/music/die/Zhugeliang.mp3");
}
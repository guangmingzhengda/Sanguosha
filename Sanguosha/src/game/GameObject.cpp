#include"../../inc/game/GameObject.h"
#include"../../inc/Defines.h"
#include"../../inc/Globals.h"
#include"../../inc/Message.h"
#include"../../inc/utils/image.h"
#include"../../inc/Sound.h"
#pragma comment(lib,"Winmm.lib")
#include<random>
#include<algorithm>
#include<easyx.h>
GameObject::GameObject() {
	_hp = 0;
	_shangxian = 0;
	_wujiang = L"名字";
	std::vector<Kapai> s;
	_shoupai = s;
	Kapai wuqi,fangjv;
	wuqi.name = L"武器";
	_wuqi = wuqi;
	fangjv.name = L"防具";
	_fangjv = fangjv;
}

GameObject::GameObject(int hp, int shangxian, std::wstring wujiang, std::vector<Kapai> shoupai,
	Kapai wuqi, Kapai fangjv)
	: _hp(hp),_shangxian(shangxian), _wujiang(wujiang), _shoupai(shoupai), _wuqi(wuqi), _fangjv(fangjv) {
	_sha = 0;
}
bool GameObject::Jianxiong(const Kapai& shanghai,int t) {
	if (GetGameObject(t)->_wujiang != L"Caocao") return 0;//曹操

	GameObject* Now = GetGameObject(t);
	Now->_shoupai.push_back(shanghai);

	UpdateFmodSystem();
	if (rand() & 1) PlayFmodSound(&Jianxiong1, true);
	else PlayFmodSound(&Jianxiong2, true);
	FlushBatchDraw();
	return 1;
}
void GameObject::Biyue(int t) {
	if (_wujiang[0] == 'D' && _wujiang[4] == 'c') {//貂蝉
		GameObject* Now = GetGameObject(t);
		Mopai(1, t);
		Draw(t);
		FlushBatchDraw();

		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Biyue1, true);
		else PlayFmodSound(&Biyue2, true);
	}
}
void GameObject::Wanrong(int t) {
	if (_wujiang[0] == 'D' && _wujiang[2] == 'q') {//大乔
		Mopai(1, t);
		Draw(t);
		FlushBatchDraw();

		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Wanrong1, true);
		else PlayFmodSound(&Wanrong2, true);
	}
}
void GameObject::Tiandu(const Kapai& Pandingpai, int t) {
	if (_wujiang[0] == 'G' && _wujiang[3] == 'j') {//郭嘉
		_shoupai.push_back(Pandingpai);
		Draw(t);
		FlushBatchDraw();
		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Tiandu1, true);
		else PlayFmodSound(&Tiandu2, true);
	}
	else {
		Paidui* Qi = GetQipaidui();
		Qi->_v.push_back(Pandingpai);
	}
}
void GameObject::Yiji(int t) {
	if (_wujiang == L"Guojia") {
		Mopai(2, t);
		Draw(t);
		FlushBatchDraw();
		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Yiji1, true);
		else PlayFmodSound(&Yiji2, true);
	}
}
void GameObject::Jizhi(int t) {
	if (_wujiang[0] == 'H' && _wujiang[5] == 'y') {//黄月英
		Mopai(1, t);
		Draw(t);
		FlushBatchDraw();
		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Jizhi1, true);
		else PlayFmodSound(&Jizhi2, true);
	}
}
void GameObject::Lianying(int t) {
	if (_wujiang[0] == 'L' && _wujiang[2] == 'x') {//陆逊
		Mopai(1, t);
		Draw(t);
		FlushBatchDraw();
		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Lianying1, true);
		else PlayFmodSound(&Lianying2, true);
	}
}
void GameObject::Fankui(int t) {
	if (_wujiang[0] == 'S' && _wujiang[2] == 'm') {//司马懿
		GameObject* Now = GetGameObject(t);
		GameObject* Nex = GetGameObject(t ^ 1);
		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Fankui1, true);
		else PlayFmodSound(&Fankui2, true);
		if (t == 0) {
			if (Nex->_fangjv.name != L"Wufangjv") {
				Now->_shoupai.push_back(Nex->_fangjv);
				DrawKapai(Nex->_fangjv, 400, 200);
				FlushBatchDraw();
				Sleep(1000);
				Nex->_fangjv.name = L"Wufangjv";
				Nex->_fangjv.zhongwen = L"无防具";
				FlushBatchDraw();
				Nex->Xiaoji(t ^ 1);
			}
			else if(Nex->_shoupai.size()) {
				int idx = rand() % Nex->_shoupai.size() + 1;
				Kapai Shun = Nex->GetKapai(idx, t ^ 1);
				Now->_shoupai.push_back(Shun);
				Nex->Del(GetIt(idx, t ^ 1), t ^ 1);
			}
			else {
				Now->_shoupai.push_back(Nex->_wuqi);
				DrawKapai(Nex->_wuqi, 400, 200);
				FlushBatchDraw();
				Sleep(1000);
				Nex->_wuqi.name = L"Wuwuqi";
				Nex->_wuqi.zhongwen = L"无武器";
				Nex->Xiaoji(t ^ 1);
			}
		}
		else {
			if (Nex->_fangjv.name == L"Wufangjv" && Nex->_wuqi.name == L"Wuwuqi") {
				if (Nex->_shoupai.size() != 0) {
					int idx = rand() % Nex->_shoupai.size() + 1;
					Kapai Shun = Nex->GetKapai(idx, t ^ 1);
					Now->_shoupai.push_back(Shun);
					Nex->Del(GetIt(idx, t ^ 1), t ^ 1);
				}
			}
			else {
				QuickText(L"请输入要获得牌的区域,1表示手牌,2表示防具,3表示武器", 200, 350, 800, 375, 25, 0);
				FlushBatchDraw();
				while (1) {
					PeekMouseMessage();
					std::wstring tmp = GetKey();
					if (isdigit(tmp[0])) {
						int opt = tmp[0] - '0';
						if (opt == 1) {
							if (Nex->_shoupai.size() == 0) {
								QuickText(L"您输入的区域不合法！请重新输入", 200, 300, 800, 325, 25, 0);
								FlushBatchDraw();
								Sleep(1000);
							}
							else {
								int idx = rand() % Nex->_shoupai.size() + 1;
								Kapai Shun = Nex->GetKapai(idx, t ^ 1);
								Now->_shoupai.push_back(Shun);
								Nex->Del(GetIt(idx, t ^ 1), t ^ 1);
								break;
							}
						}
						else if (opt == 2) {
							if (Nex->_fangjv.name == L"Wufangjv") {
								QuickText(L"您输入的区域不合法！请重新输入", 200, 300, 800, 325, 25, 0);
								FlushBatchDraw();
								Sleep(1000);
							}
							else {
								Now->_shoupai.push_back(Nex->_fangjv);
								DrawKapai(Nex->_fangjv, 400, 200);
								FlushBatchDraw();
								Sleep(1000);
								Nex->_fangjv.name = L"Wufangjv";
								Nex->_fangjv.zhongwen = L"无防具";
								Nex->Xiaoji(t ^ 1);
								break;
							}
						}
						else if (opt == 3) {
							if (Nex->_wuqi.name == L"Wuwuqi") {
								QuickText(L"您输入的区域不合法！请重新输入", 200, 300, 800, 325, 25, 0);
								FlushBatchDraw();
								Sleep(1000);
							}
							else {
								Now->_shoupai.push_back(Nex->_wuqi);
								DrawKapai(Nex->_wuqi, 400, 200);
								FlushBatchDraw();
								Sleep(1000);
								Nex->_wuqi.name = L"WUwuqi";
								Nex->_wuqi.zhongwen = L"无武器";
								Nex->Xiaoji(t ^ 1);
								break;
							}
						}
					}
					FlushBatchDraw();
				}
			}
			FlushBatchDraw();
		}
	}
}
void GameObject::Xiaoji(int t) {
	if (_wujiang[0] == 'S' && _wujiang[3] == 's') {//孙尚香
		if (_hp < 2) ChangeHp(1, t);
		else Mopai(2, t);
		FlushBatchDraw();
		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Xiaoji1, true);
		else PlayFmodSound(&Xiaoji2, true);
	}
}
//void GameObject::Ganglie(int t) {
//	if (_wujiang[0] == 'X' && _wujiang[3] == 'h') {
//		Kapai Pandingpai = Panding(t);
//		if (Pandingpai.huase == 1) return ;
//		//
//	}
//}

void GameObject::Luoshen(int t) {
	
}
FmodSound yingzi;
void GameObject::Yingzi(int t) {
	if (_wujiang[0] == 'Z' && _wujiang[4] == 'y') {//周瑜
		UpdateFmodSystem();
		if (rand() & 1) PlayFmodSound(&Yingzi1, true);
		else PlayFmodSound(&Yingzi2, true);
		Mopai(1, t);
	}
}
void GameObject::Fanjian(int t) {
	srand((unsigned int)time(NULL));
	UpdateFmodSystem();
	if (rand() & 1) PlayFmodSound(&Fanjian1, true);
	else PlayFmodSound(&Fanjian2, true);
	GameObject* Now = GetGameObject(t);
	GameObject* Nex = GetGameObject(t ^ 1);
	int huase = rand() % 4, idx = rand() % Now->_shoupai.size() + 1;
	std::wstring mmp[4] = { L"黑桃",L"红桃",L"梅花",L"方片"};
	QuickText(L"选择了花色"+mmp[huase], 200, 300, 800, 350, 30, 0);
	FlushBatchDraw();
	Kapai kapai = GetKapai(idx, t);
	Nex->_shoupai.push_back(kapai);
	Now->Del(GetIt(idx, t), t);
	if (huase != kapai.huase) {
		Nex->ChangeHp(-1, t^1);
	}
	Sleep(500);
}
void GameObject::Fanjiandiannao(int t) {
	srand((unsigned int)time(NULL));
	UpdateFmodSystem();
	if (rand() & 1) PlayFmodSound(&Fanjian1, true);
	else PlayFmodSound(&Fanjian2, true);
	GameObject* Now = GetGameObject(t);
	GameObject* Nex = GetGameObject(t ^ 1);
	int idx = rand() % Now->_shoupai.size() + 1;
	QuickText(L"请选择一种花色,1234对应黑桃红桃梅花方片", 200, 300, 800, 350, 30, 0);
	FlushBatchDraw();
	std::wstring tmp;
	while (1) {
		PeekMouseMessage();
		tmp = GetKey();
		if (tmp[0] == '1' || tmp[0] == '2' || tmp[0] == '3' || tmp[0] == '4') {
			int huase = tmp[0] - '0';
			Kapai kapai = GetKapai(idx, t);
			Nex->_shoupai.push_back(kapai);
			Now->Del(GetIt(idx, t), t);
			if (huase != kapai.huase) {
				Nex->ChangeHp(-1, t ^ 1);
			}
			FlushBatchDraw();
			break;
		}
	}
}

void GameObject::Draw(int t) {
	if (t == 0) {
		setbkmode(TRANSPARENT);
		GameObject* Now = GetGameObject(t);
		QuickText(Now->_zhongwen.c_str(), 800, 190, 1000, 240, 50, 0);
		IMAGE Fangjv_;
		std::wstring fjdizhi = L"res/Fangjv.png";
		loadimage(&Fangjv_, fjdizhi.c_str(), 157, 30, 1);
		PutAlphaImage(nullptr, 0, 95, &Fangjv_);
		IMAGE Wuqi_;
		std::wstring wqdizhi = L"res/Wuqi.png";
		loadimage(&Wuqi_, wqdizhi.c_str(), 157, 30, 1);
		PutAlphaImage(nullptr, 0, 22, &Wuqi_);

		QuickText(Now->_wuqi.zhongwen.c_str(), 30, 0, 150, 75, 30, 0);
		QuickText(Now->_fangjv.zhongwen.c_str(), 30, 75, 150, 150,30,0);
		if (Now->_yanshi1.name == L"Lebusishu") {
			IMAGE Le;
			std::wstring dizhi = L"res/Le.png";
			loadimage(&Le, dizhi.c_str(), 25, 25, 1);
			PutAlphaImage(nullptr, 30, 150, &Le);
//			QuickText(L"乐", 30, 150, 60, 180, 20, 0);
		}
		if (Now->_yanshi1.name == L"Bingliangcunduan") {
			IMAGE Bing;
			std::wstring dizhi = L"res/Bing.png";
			loadimage(&Bing, dizhi.c_str(), 25, 25, 1);
			PutAlphaImage(nullptr, 30, 150, &Bing);
//			QuickText(L"兵", 30, 150, 60, 180, 20, 0);
		}
		if (Now->_yanshi2.name == L"Lebusishu") {
			IMAGE Le;
			std::wstring dizhi = L"res/Le.png";
			loadimage(&Le, dizhi.c_str(), 25, 25, 1);
			PutAlphaImage(nullptr, 60, 150, &Le);
//			QuickText(L"乐", 60, 150, 90, 180, 20, 0);
		}
		if (Now->_yanshi2.name == L"Bingliangcunduan") {
			IMAGE Bing;
			std::wstring dizhi = L"res/Bing.png";
			loadimage(&Bing, dizhi.c_str(), 25, 25, 1);
			PutAlphaImage(nullptr, 60, 150, &Bing);
//			QuickText(L"兵", 60, 150, 90, 180, 20, 0);
		}
		std::wstring xieliang;
		xieliang = L"血量:";
		xieliang += (char)(Now->_hp + 48);
		xieliang += '/';
		xieliang += (char)(Now->_shangxian + 48);
		QuickText(xieliang.c_str(), 800, 240, 1000, 270, 20, 0);

		IMAGE Diannao;
		std::wstring dizhi = L"res/" + Now->_wujiang+L".png";
		loadimage(&Diannao, dizhi.c_str(), 140, 180, 1);
		PutAlphaImage(nullptr, 850, 0, &Diannao);
		if ((int)Now->_shoupai.size() == 0) {
			QuickText(L"无手牌", 160, 0, 600, 150, 60, 0);
		}
		else {
			//int i = 0;
			//for (Kapai x : Now->_shoupai) {
			//	DrawKapai(x, 160 + i * 80, 25);
			//	++i;
			//}
			int tot = (int)Now->_shoupai.size();
			for (int i = 0; i < tot; i++) {
				std::wstring s = L"手牌";
				s+=+(char)(49 + i);
//				QuickText(s, 160 + i * 71, 25, 160 + (i + 1) * 71, 150, 30, 0);
				std::wstring Lujing = L"res/Shoupai.png";
				IMAGE Shoupai;
//				QuickText(s.c_str(), 160 + i * 80, 25, 160 + (i + 1) * 80, 25 + 112, 30, 1);
				loadimage(&Shoupai, Lujing.c_str(), 80, 112, 1);
				PutAlphaImage(nullptr, 160 + i * 80, 25, &Shoupai);
			}
		}
	}
	else {
		setbkmode(TRANSPARENT);
		GameObject* Now = GetGameObject(t);
		std::wstring xieliang;
		xieliang = L"血量:";
		xieliang += (char)(Now->_hp + 48);
		xieliang += '/';
		xieliang += (char)(Now->_shangxian + 48);
		IMAGE Fangjv_;
		std::wstring fjdizhi = L"res/Fangjv.png";
		loadimage(&Fangjv_, fjdizhi.c_str(), 157, 30, 1);
		PutAlphaImage(nullptr, 0, 485, &Fangjv_);
		IMAGE Wuqi_;
		std::wstring wqdizhi = L"res/Wuqi.png";
		loadimage(&Wuqi_, wqdizhi.c_str(), 157, 30, 1);
		PutAlphaImage(nullptr, 0, 412, &Wuqi_);
		QuickText(Now->_zhongwen.c_str(), 800, 290, 1000, 340, 50, 0);
		QuickText(Now->_wuqi.zhongwen.c_str(), 30, 390, 150, 465, 30, 0);
		QuickText(Now->_fangjv.zhongwen.c_str(), 30, 465, 150, 540, 30, 0);
		QuickText(xieliang.c_str(), 800, 330, 1000, 370,20,0);
		if (Now->_yanshi1.name == L"Lebusishu") {
			IMAGE Le;
			std::wstring dizhi = L"res/Le.png";
			loadimage(&Le, dizhi.c_str(), 25, 25, 1);
			PutAlphaImage(nullptr, 30, 360, &Le);
//			QuickText(L"乐", 30, 360, 60, 390, 20, 0);
		}
		if (Now->_yanshi1.name == L"Bingliangcunduan") {
			IMAGE Bing;
			std::wstring dizhi = L"res/Bing.png";
			loadimage(&Bing, dizhi.c_str(), 25, 25, 1);
			PutAlphaImage(nullptr, 30, 360, &Bing);
//			QuickText(L"兵", 30, 360, 60, 390, 20, 0);
		}
		if (Now->_yanshi2.name == L"Lebusishu") {
			IMAGE Le;
			std::wstring dizhi = L"res/Le.png";
			loadimage(&Le, dizhi.c_str(), 25, 25, 1);
			PutAlphaImage(nullptr, 60, 360, &Le);
//			QuickText(L"乐", 60, 360, 90, 390, 20, 0);
		}
		if (Now->_yanshi2.name == L"Bingliangcunduan") {
			IMAGE Bing;
			std::wstring dizhi = L"res/Bing.png";
			loadimage(&Bing, dizhi.c_str(), 25, 25, 1);
			PutAlphaImage(nullptr, 60, 360, &Bing);
//			QuickText(L"兵", 60, 360, 90, 390, 20, 0);
		}
		IMAGE Wanjia;
		std::wstring dizhi = L"res/" + Now->_wujiang + L".png";
		loadimage(&Wanjia, dizhi.c_str(), 140, 180, 1);
		PutAlphaImage(nullptr, 850, 560-180, &Wanjia);
		if ((int)Now->_shoupai.size() == 0) QuickText(L"无手牌", 160, 350, 600, 500,60,0);
		else {
			int i = 0;
			for (Kapai x : Now->_shoupai) {
				DrawKapai(x,160+i*80,25+390);
				++i;
			}
		}
	}

	
}
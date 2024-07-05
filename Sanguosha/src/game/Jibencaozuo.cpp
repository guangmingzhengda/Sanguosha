#include"../../inc/game/GameObject.h"
#include"../../inc/Defines.h"
#include"../../inc/Globals.h"
#include"../../inc/Message.h"
#include"../../inc/utils/image.h"
#include<random>
#include<algorithm>
#include<easyx.h>


Kapai GameObject::Panding(int t) {
	Paidui* Mo = GetMopaidui();
	return Mo->GetFirst();
}


void GameObject::Mopai(int k, int t) {
	GameObject* Now = GetGameObject(t);
	while (k--) {
		Paidui* Mo = GetMopaidui();
		Now->_shoupai.push_back(Mo->GetFirst());
	}
}

Kapai GameObject::GetKapai(int k,int t) {
	GameObject* Now = GetGameObject(t);
	if (k > Now->_shoupai.size()) 
		return *(Now->_shoupai.begin());
	int cnt = 0;
	for (Kapai x : Now->_shoupai) {
		if (++cnt == k)
			return x;
	}
	return *(Now->_shoupai.begin());
}

std::vector<Kapai>::iterator GameObject::GetIt(int k, int t) {
	GameObject* Now = GetGameObject(t);
	if (k > Now->_shoupai.size()) return Now->_shoupai.begin();
	int cnt = 0;
	std::vector<Kapai>::iterator it=Now->_shoupai.begin();
	do {
		if (++cnt == k) return it;
		it++;
	} while (it != Now->_shoupai.end());
	return Now->_shoupai.begin();
}

std::wstring lass=L"None";
void GameObject::Qipai(int t) {
	GameObject* Now = GetGameObject(t);
	QuickText(L"请输入要弃置的牌的编号：", 200, 300, 800, 350, 25, 0);
	if (!Now->_shoupai.size()) return ;
	if (t == 0) {
		Now->Del(Now->_shoupai.begin(), t);
	}
	else if (t == 1) {
		std::wstring tmp;
		bool qing=1;
		while (qing) {
			QuickText(L"请输入要弃置的牌的编号：", 200, 300, 800, 350, 20, 0);
			PeekMouseMessage();
			tmp = GetKey();
//			QuickText(tmp.c_str(), 0, 150, 1000, 350, 60, 0);
			//if (tmp == L"None") {
			//	tmp = las;
			//}
			//else las = tmp;
			if (isdigit(tmp[0])) {
				auto it = Now->GetIt(tmp[0] - '0', t);
				Now->Del(it, t);
				//Kapai Del= Now->GetKapai(tmp[0] - '0', t);
				//if(Del.name.size()>3) Now->_shoupai.erase(Del);
				qing = 0;
			}
			FlushBatchDraw();
		}
	}
}

void GameObject::Del(std::vector<Kapai>::iterator it, int t) {
	GameObject* Now = GetGameObject(t);
	std::vector<Kapai>::iterator it2 = it;
	if (it != Now->_shoupai.end()) {
		DrawKapai(*(it), 400, 200);
		it2++;
		Now->_shoupai.erase(it, it2);
		FlushBatchDraw();
		Sleep(1000);
	}
	if (Now->_shoupai.size() == 0) {
		Now->Lianying(t);
	}
}

bool GameObject::AskSha(int k, int t) {
	GameObject* Now = GetGameObject(t);
	GameObject* Nex = GetGameObject(t ^ 1);
	Paidui* Qi = GetQipaidui();
	if (!Now->_shoupai.size()) return 0;
	//电脑
	if (t == 0) {
		if (Now->_hp == Now->_shangxian || (Now->_hp > 1 && Nex->_hp < 2)) {
			if (Now->_wujiang == L"Caocao" || Now->_wujiang == L"Guojia" || Now->_wujiang == L"Simayi") {
				return 0;
			}
		}
		auto it = Now->_shoupai.begin();
		do {
			if ((*it).name == L"Sha") break;
			it++;
		} while (it != Now->_shoupai.end());
		if (it == Now->_shoupai.end()) {
			return 0;
		}
		else {
			DrawKapai(*it, 400, 200);
			Paidui* Qi = GetQipaidui();
			Qi->_v.push_back(*it);
			Now->Del(it, t);
			Now->Draw(t);
			FlushBatchDraw();
			Sleep(1000);
			PlayFmodSound(&Sha1, true);
			return 1;
		}
	}
	else {//玩家
		QuickText(L"请打出一张杀响应，按0取消", 200, 350, 800, 400, 25, 0);
		FlushBatchDraw();
		std::wstring tmp;
		while(1) {
			PeekMouseMessage();
			tmp = GetKey();
			if (tmp[0] == 'W') {
				if ((int)Now->_shoupai.size() >= 2 && Now->_wuqi.name == L"Zhangbashemao") {
					QuickText(L"可选择两张牌当杀使用,0代表取消", 200, 350, 800, 400, 25, 0);
					FlushBatchDraw();
					std::wstring tmp;
					int k1 = 0, k2 = 0;
					while (!k2) {
						PeekMouseMessage();
						tmp = GetKey();
						if (tmp[0] == '0') break;
						if (tmp == L"None") continue;
						if (tmp[0] - '0' < 1 || tmp[0] - '0' > (int)Now->_shoupai.size()) {
							if (!k1) tmp[0] = '1';
							else tmp[0] = (int)Now->_shoupai.size() + '0';
						}
						if (!k1) k1 = tmp[0] - '0';
						else k2 = tmp[0] - '0';
					}
					if (k1 && k2) {
						if (k1 > k2) std::swap(k1, k2);
						Kapai kapai1 = Now->GetKapai(k1, t), kapai2 = Now->GetKapai(k2, t);
						DrawKapai(kapai1, 400, 200);
						DrawKapai(kapai2, 500, 200);
						FlushBatchDraw();
						Sleep(1500);
						Now->Del(Now->GetIt(k1, t), t);
						Now->Del(Now->GetIt(k2 - 1, t), t);
						Paidui* Qi = GetQipaidui();
						Qi->_v.push_back(kapai1);
						Qi->_v.push_back(kapai2);
						return 1;
					}
				}
			}
			else {
				if (tmp[0] == '0') {
					return 0;
				}
				int ch = tmp[0] - '0';
				if (ch<0 || ch>(int)Now->_shoupai.size()) {
					ch = 1;
				}
				if (Now->GetKapai(ch, t).name == L"Sha") {
					Qi->_v.push_back(Now->GetKapai(ch, t));
					DrawKapai(Now->GetKapai(ch, t), 400, 200);
					Now->Del(Now->GetIt(ch, t), t);
					Now->Draw(t);
					FlushBatchDraw();
					PlayFmodSound(&Sha1, true);
					Sleep(1000);
					return 1;
				}
			}
		}
	}
}

bool GameObject::AskShan(int k, int t) {
	GameObject* Now = GetGameObject(t);
	GameObject* Nex = GetGameObject(t ^ 1);
	Paidui* Qi = GetQipaidui();
	if (!Now->_shoupai.size()) return 0;
	//八卦阵自动发动
	if (t == 0) {
		if (Now->_hp == Now->_shangxian || (Now->_hp > 1 && Nex->_hp < 2)) {
			if (Now->_wujiang == L"Caocao" || Now->_wujiang == L"Guojia" || Now->_wujiang == L"Simayi") {
				return 0;
			}
		}
		if (Now->_fangjv.name == L"Baguazhen" && Nex->_wuqi.name != L"Qinggangjian") {
			Kapai pandingpai = Now->Panding(t);
			DrawKapai(pandingpai, 600, 200);
			Now->Tiandu(pandingpai, t);
			FlushBatchDraw();
			if (pandingpai.huase == 1 || pandingpai.huase == 3) {
				QuickText(L"八卦阵生效", 600, 300, 800, 350, 25, 0);
				FlushBatchDraw();
				UpdateFmodSystem();
				PlayFmodSound(&Shan1, true);
				Sleep(1500);
				return 1;
			}
			else {
				QuickText(L"八卦阵失效", 600, 300, 800, 350, 25, 0);
				FlushBatchDraw();
				Sleep(1500);
			}
		}
	}
	else if(Now->_fangjv.name == L"Baguazhen") {
		QuickText(L"请选择是否发动八卦阵，回车确定，0取消", 200, 320, 800, 370, 25, 0);
		FlushBatchDraw();
		std::wstring tmp;
		while (1) {
			PeekMouseMessage();
			tmp = GetKey();
			if (tmp == L"Enter") {
				if (Nex->_wuqi.name != L"Qinggangjian") {
					Kapai pandingpai = Now->Panding(t);
					DrawKapai(pandingpai, 600, 200);
					Now->Tiandu(pandingpai, t);
					FlushBatchDraw();
					if (pandingpai.huase == 1 || pandingpai.huase == 3) {
						QuickText(L"八卦阵生效", 600, 300, 800, 350, 25, 0);
						FlushBatchDraw();
						UpdateFmodSystem();
						PlayFmodSound(&Shan1, true);
						Sleep(1500);
						return 1;
					}
					else {
						QuickText(L"八卦阵失效", 600, 300, 800, 350, 25, 0);
						FlushBatchDraw();
						Sleep(1500);
					}
				}
			}
			else if (tmp[0] == '0') {
				break;
			}
		}
	}
	//电脑
	if (t == 0) {
		auto it = Now->_shoupai.begin();
		do {
			if ((*it).name == L"Shan") break;
			it++;
		} while (it!=Now->_shoupai.end());
		if (it == Now->_shoupai.end()) {
			return 0;
		}
		else {
			Qi->_v.push_back(*it);
			DrawKapai(*it, 400, 200);
			Now->Del(it, t);
			Now->Draw(t);
			FlushBatchDraw();
			UpdateFmodSystem();
			PlayFmodSound(&Shan1, true);
			Sleep(1000);
			return 1;
		}
	}
	else {//人
		QuickText(L"请使用一张闪响应，0代表取消：", 200, 350, 800, 400, 25, 0);
		FlushBatchDraw();
		std::wstring tmp;
		int ch = 0;
		while (1) {
			PeekMouseMessage();
			tmp = GetKey();
			FlushBatchDraw();
			if (tmp[0] == '0') {
				return 0;
			}
			else if (tmp[0]<'1' || tmp[0]>Now->_shoupai.size() + '0') {
				tmp[0] = 'P';
			}
			if (tmp[0] != 'P') ch = tmp[0] - '0';
			else continue;
			if (Now->GetKapai(ch,t).name==L"Shan") {
				Qi->_v.push_back(Now->GetKapai(ch, t));
				DrawKapai(Now->GetKapai(ch,t), 400, 200);
				Now->Del(Now->GetIt(ch,t), t);
				Now->Draw(t);
				FlushBatchDraw();
				UpdateFmodSystem();
				PlayFmodSound(&Shan1, true);
				Sleep(1000);
				return 1;
			}
		}

	}
}

bool GameObject::AskTao(int t) {
	GameObject* Now = GetGameObject(t);
	GameObject* Nex = GetGameObject(t ^ 1);
	if (!Now->_shoupai.size()) return 0;
	auto it = Now->_shoupai.begin();
	Paidui* Qi = GetQipaidui();
	do {
		if ((*it).name == L"Tao") break;
		it++;
	} while (it != Now->_shoupai.end());
	if (it == Now->_shoupai.end()) {
		return 0;
	}
	else {
		Qi->_v.push_back(*it);
		DrawKapai(*it, 400, 200);
		Now->Del(it, t);
		FlushBatchDraw();
		UpdateFmodSystem();
		PlayFmodSound(&Tao1, true);
		Sleep(1000);
		return 1;
	}
}

bool GameObject::AskShui(int t) {
	GameObject* Now = GetGameObject(t);
	GameObject* Nex = GetGameObject(t ^ 1);
	FlushBatchDraw();
	Sleep(2000);
	if (Now->_fangjv.name == L"Wufangjv" && Now->_wuqi.name == L"Wuwuqi") {
		return 0;
	}
	Paidui* Qi = GetQipaidui();
	Kapai tmp;
	if (t == 0) {
		if (Now->_hp == Now->_shangxian || (Now->_hp > 1 && Nex->_hp < 2)) {
			if (Now->_wujiang == L"Caocao" || Now->_wujiang == L"Guojia" || Now->_wujiang == L"Simayi") {
				return 0;
			}
		}
		if (Now->_hp <= 2) {
			if (Now->_fangjv.name != L"Wufangjv") {
				Qi->_v.push_back(Now->_fangjv);
				Now->_fangjv = tmp;
				Now->_fangjv.name = L"Wufangjv";
				Now->_fangjv.zhongwen = L"无防具";
				Now->Xiaoji(t);
			}
			if (Now->_wuqi.name != L"Wuwuqi") {
				Qi->_v.push_back(Now->_wuqi);
				Now->_wuqi = tmp;
				Now->_wuqi.name = L"Wuwuqi";
				Now->_wuqi.zhongwen = L"无武器";
				Now->Xiaoji(t);
			}
			Now->Draw(t);
			return 1;
		}
		else if (Now->_fangjv.name != L"Wufangjv" && Now->_wuqi.name != L"Wuwuqi") {
			Now->ChangeHp(-1, t);
			return 0;
		}
		else {
			if (Now->_fangjv.name != L"Wufangjv") {
				Qi->_v.push_back(Now->_fangjv);
				Now->_fangjv = tmp;
				Now->_fangjv.name = L"Wufangjv";
				Now->_fangjv.zhongwen = L"无防具";
				Now->Xiaoji(t);
			}
			if (Now->_wuqi.name != L"Wuwuqi") {
				Qi->_v.push_back(Now->_wuqi);
				Now->_wuqi = tmp;
				Now->_wuqi.name = L"Wuwuqi";
				Now->_wuqi.zhongwen = L"无武器";
				Now->Xiaoji(t);
			}
			Now->Draw(t);
			return 1;
		}
	}
	else {
		QuickText(L"请选择是否弃置装备区所有牌,1表示弃置,0表示受到伤害", 200, 350, 800, 400, 25, 0);
		FlushBatchDraw();
		std::wstring tmp;
		while (1) {
			PeekMouseMessage();
			tmp = GetKey();
			if (tmp[0] == '0') {
				return 0;
			}
			else if(tmp[0]=='1') {
				if (Now->_fangjv.name != L"Wufangjv") {
					Qi->_v.push_back(Now->_fangjv);
					Now->_fangjv.name = L"Wufangjv";
					Now->_fangjv.zhongwen = L"无防具";
					Now->Xiaoji(t);
				}
				if (Now->_wuqi.name != L"Wuwuqi") {
					Qi->_v.push_back(Now->_wuqi);
					Now->_wuqi.name = L"Wuwuqi";
					Now->_wuqi.zhongwen = L"无武器";
					Now->Xiaoji(t);
				}
				return 1;
			}
		}
	}
}

bool GameObject::AskWuxie(int t) {
	GameObject* Now = GetGameObject(t);
	Paidui* Qi = GetQipaidui();
	auto it = Now->_shoupai.begin();
	if (!Now->_shoupai.size()) return 0;
	do {
		if ((*it).name == L"Wuxiekeji") break;
		it++;
	} while (it != Now->_shoupai.end());
	if (it == Now->_shoupai.end()) {
		return 0;
	}
	if (t == 0) {
		DrawKapai(*it, 400, 200);
		Now->Del(it, t);
		Now->Jizhi(t);
		FlushBatchDraw();
		UpdateFmodSystem();
		PlayFmodSound(&Wuxiekeji1, true);
		Sleep(1000);
		return 1;
	}
	else {
		QuickText(L"请打出一张无懈响应，按0取消", 200, 350, 800, 400, 25, 0);
		FlushBatchDraw();
		std::wstring tmp;
		while (1) {
			PeekMouseMessage();
			tmp = GetKey();
			if (tmp[0] == '0') {
				return 0;
			}
			int ch = tmp[0] - '0';
			if (ch<0 || ch>(int)Now->_shoupai.size()) {
				ch = 1;
			}
			if (Now->GetKapai(ch, t).name == L"Wuxiekeji") {
				Qi->_v.push_back(Now->GetKapai(ch, t));
				DrawKapai(Now->GetKapai(ch, t), 400, 200);
				Now->Del(Now->GetIt(ch, t), t);
				Now->Jizhi(t);
				FlushBatchDraw();
				UpdateFmodSystem();
				PlayFmodSound(&Wuxiekeji1, true);
				Sleep(1000);
				return 1;
			}
		}
	}
}

bool GameObject::UseShoupai(int k, int t) {
	srand((signed)time(nullptr));
	GameObject* Now = GetGameObject(t);
	GameObject* Nex = GetGameObject(t ^ 1);
	Kapai Shoupai = GetKapai(k, t);
	if (!Now->_shoupai.size()) return 0;
	Paidui* Mo = GetMopaidui();
	Paidui* Qi = GetQipaidui();
	bool used = 1;
	if (Shoupai.type == 1) {
		Now->Jizhi(t);
	}
	if (Shoupai.type == 2) {
		DrawKapai(Shoupai, 400, 200);
		FlushBatchDraw();
		Sleep(1000);
		Now->Del(Now->GetIt(k, t), t);
		Now->UseWuqi(Shoupai, t);
	}
	else if (Shoupai.type == 3) {
		DrawKapai(Shoupai, 400, 200);
		FlushBatchDraw();
		Sleep(1000);
		Now->Del(Now->GetIt(k, t), t);
		Now->UseFangjv(Shoupai, t);
	}
	else {
		if (Shoupai.name == L"Sha") {
			if (Now->_sha < 1 || Now->_wuqi.name == L"Zhugeliannu" || Now->_wujiang == L"Zhangfei") {
				Nex->Wanrong(t ^ 1);
				FlushBatchDraw();
				UpdateFmodSystem();
				PlayFmodSound(&Sha1, true);
				Sleep(1000);
				DrawKapai(Shoupai, 400, 200);
				Now->Del(Now->GetIt(k, t), t);
				FlushBatchDraw();
				Sleep(1000);
				Now->_sha++;
				if (Nex->_fangjv.name == L"Renwangdun" && (Shoupai.huase == 0 || Shoupai.huase == 2)&&Now->_wuqi.name!=L"Qinggangjian") {
					;
				}
				else {
					bool Xiangying = Nex->AskShan(1, t ^ 1);
					if (!Xiangying) {
						if (Now->_wuqi.name != L"Hanbingjian") {
							Nex->ChangeHp(-1, t ^ 1);
							if (!(Nex->Jianxiong(Shoupai,t^1))) {
								Qi->_v.push_back(Shoupai);
							}
						}
						else if(t == 1 && (int)Nex->_shoupai.size() > 0) {
							QuickText(L"发动寒冰剑防止伤害弃置对手两张牌,0取消,1确定", 200, 350, 800, 400, 25, 0);
							FlushBatchDraw();
							std::wstring tmp;
							while (1) {
								PeekMouseMessage();
								tmp = GetKey();
								if (tmp[0] == '0') break;
								else if (tmp[0] == '1') {
									if (Nex->_shoupai.size() == 1) {
										Kapai kapai1 = *(Nex->_shoupai.begin());
										DrawKapai(kapai1, 400, 200);
										Nex->Del(Nex->_shoupai.begin(), t);
										Qi->_v.push_back(kapai1);
										FlushBatchDraw();
									}
									else {
										srand((unsigned)time(nullptr));
										int idx1 = rand() % Nex->_shoupai.size() + 1;
										Kapai kapai1 = Nex->GetKapai(idx1, t ^ 1);
										DrawKapai(kapai1, 400, 200);
										Nex->Del(Nex->GetIt(idx1, t ^ 1), t ^ 1);
										Qi->_v.push_back(kapai1);
										FlushBatchDraw();
										int idx2 = rand() % Nex->_shoupai.size() + 1;
										Kapai kapai2 = Nex->GetKapai(idx2, t ^ 1);
										DrawKapai(kapai2, 400, 200);
										Nex->Del(Nex->GetIt(idx2, t ^ 1), t ^ 1);
										Qi->_v.push_back(kapai2);
										FlushBatchDraw();
									}
									break;
								}
							}
							if (tmp[0] == '0') {
								Nex->ChangeHp(-1, t ^ 1);
								if (!(Nex->Jianxiong(Shoupai, t ^ 1))) {
									Qi->_v.push_back(Shoupai);
								}
							}
						}
						else {
							Nex->ChangeHp(-1, t ^ 1);
							if (!(Nex->Jianxiong(Shoupai, t ^ 1))) {
								Qi->_v.push_back(Shoupai);
							}
						}
					}
					else if (t==1&&Now->_wuqi.name == L"Guanshifu" && Xiangying && Now->_shoupai.size() >= 2) {
						QuickText(L"可选择两张牌弃置强制造成伤害,0代表取消", 200, 350, 800, 400, 25, 0);
						FlushBatchDraw();
						std::wstring tmp;
						int k1 = 0, k2 = 0;
						while (!k2) {
							PeekMouseMessage();
							tmp = GetKey();
							if (tmp[0] == '0') break;
							if (tmp == L"None") continue;
							if (tmp[0] - '0' < 1 || tmp[0] - '0' > (int)Now->_shoupai.size()) {
								if (!k1) tmp[0] = '1';
								else tmp[0] = (int)Now->_shoupai.size() + '0';
							}
							if (!k1) k1 = tmp[0] - '0';
							else k2 = tmp[0] - '0';
						}
						if (k1 && k2) {
							if (k1 > k2) std::swap(k1, k2);
							Kapai kapai1 = Now->GetKapai(k1, t), kapai2 = Now->GetKapai(k2, t);
							DrawKapai(kapai1, 400, 200);
							DrawKapai(kapai2, 500, 200);
							Now->Del(Now->GetIt(k1, t), t);
							Now->Del(Now->GetIt(k2 - 1, t), t);
							Paidui* Qi = GetQipaidui();
							Qi->_v.push_back(kapai1);
							Qi->_v.push_back(kapai2);
							FlushBatchDraw();
							Nex->ChangeHp(-1, t ^ 1);
							if (!(Nex->Jianxiong(Shoupai, t ^ 1))) {
								Qi->_v.push_back(Shoupai);
							}
							Sleep(1500);
						}
					}
				}
			}
			else used = 0;
		}
		else if (Shoupai.name == L"Tao") {
			if (Now->_shangxian > Now->_hp) {
				DrawKapai(Shoupai, 400, 200);
				Now->Del(Now->GetIt(k, t), t);
				UpdateFmodSystem();
				PlayFmodSound(&Tao1, true);
				FlushBatchDraw();
				Sleep(1000);
				Now->ChangeHp(1, t);
			}
			else used = 0;
		}
		else if (Shoupai.name == L"Guohechaiqiao") {
			if (!Nex->_shoupai.size() && Nex->_wuqi.name == L"Wuwuqi" && Nex->_fangjv.name == L"Wufangjv") {
				return 0;
			}
			DrawKapai(Shoupai, 400, 200);
			Now->Del(Now->GetIt(k, t), t);
			FlushBatchDraw();

			UpdateFmodSystem();
			PlayFmodSound(&Guohechaiqiao1, true);
			Sleep(1000);
			if (Nex->AskWuxie(t ^ 1)) {
				;
			}
			else {
				if (t == 0) {
					if (Nex->_fangjv.name != L"Wufangjv") {
						Qi->_v.push_back(Nex->_fangjv);
						DrawKapai(Nex->_fangjv, 400, 200);
						FlushBatchDraw();
						Sleep(1000);
						Nex->_fangjv.name = L"Wufangjv";
						Nex->_fangjv.zhongwen = L"无防具";
						Nex->Xiaoji(t ^ 1);
					}
					else if(Nex->_shoupai.size()) {
						Nex->Del(Nex->GetIt(rand() % Nex->_shoupai.size() + 1, t ^ 1), t ^ 1);
					}
					else {
						Qi->_v.push_back(Nex->_wuqi);
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
							Nex->Del(Nex->GetIt(rand() % Nex->_shoupai.size() + 1, t ^ 1), t ^ 1);
						}
						else used = 0;
					}
					else {
						QuickText(L"请输入要弃置区域,1表示手牌,2表示防具,3表示武器", 200, 325, 800, 350, 25, 0);
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
										Nex->Del(Nex->GetIt(rand() % Nex->_shoupai.size() + 1, t ^ 1), t ^ 1);
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
										Qi->_v.push_back(Nex->_fangjv);
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
				}
			}	
		}
		else if (Shoupai.name == L"Juedou") {
			DrawKapai(Shoupai, 400, 200);
			Now->Del(Now->GetIt(k, t), t);
			FlushBatchDraw();
			UpdateFmodSystem();
			PlayFmodSound(&Juedou1, true);
			Sleep(1000);
			if (Nex->AskWuxie(t ^ 1)) {
				;
			}
			else {
				//int now = t ^ 1;
				//while (Nex->AskSha(1, now)) {
				//	now ^= 1;
				//}
				//Now->ChangeHp(-1, now);
				//if (!(Now->Jianxiong(Shoupai, now))) {
				//	Qi->_v.push_back(Shoupai);
				//}
				if (Nex->AskSha(1, t ^ 1)) {
					if (Now->AskSha(1, t)) {
						if (Nex->AskSha(1, t ^ 1)) {
							if (Now->AskSha(1, t)) {
								if (Nex->AskSha(1, t ^ 1)) {
									if (Now->AskSha(1, t)) {
										;
									}
									else {
										Now->ChangeHp(-1, t);
										FlushBatchDraw();
										Now->Jianxiong(Shoupai, t);
									}
								}
								else {
									Nex->ChangeHp(-1, t ^ 1);
									FlushBatchDraw();
									Nex->Jianxiong(Shoupai, t ^ 1);
								}
							}
							else {
								Now->ChangeHp(-1, t);
								FlushBatchDraw();
								Now->Jianxiong(Shoupai, t);
							}
						}
						else {
							Nex->ChangeHp(-1, t ^ 1);
							FlushBatchDraw();
							Nex->Jianxiong(Shoupai, t ^ 1);
						}
					}
					else {
						Now->ChangeHp(-1, t);
						FlushBatchDraw();
						Now->Jianxiong(Shoupai, t);
					}
				}
				else {
					Nex->ChangeHp(-1, t ^ 1);
					FlushBatchDraw();
					Nex->Jianxiong(Shoupai, t ^ 1);
				}
			}
		}
		else if (Shoupai.name == L"Lebusishu") {
			if (Nex->_wujiang == L"Luxun") {
				used = 0;
			}
			else {
				DrawKapai(Shoupai, 400, 200);
				UpdateFmodSystem();
				PlayFmodSound(&Lebusishu1, true);
				if (Nex->_yanshi1.name == L"Wuyanshi") {
					Nex->_yanshi1 = Shoupai;
				}
				else {
					Nex->_yanshi2 = Shoupai;
				}
				Sleep(1000);
				Now->Del(Now->GetIt(k, t), t);
				FlushBatchDraw();
			}
		}
		else if (Shoupai.name == L"Nanmanruqin") {
			DrawKapai(Shoupai, 400, 200);
			FlushBatchDraw();
			Sleep(1000);
			Now->Del(Now->GetIt(k, t), t);
			FlushBatchDraw();
			UpdateFmodSystem();
			PlayFmodSound(&Nanmanruqin1, true);
			if (Nex->AskWuxie(t ^ 1)) {
				;
			}
			else {
				bool Xiangying=Nex->AskSha(1,t^1);
				if (!Xiangying) {
					Nex->ChangeHp(-1, t ^ 1);
					if (!(Nex->Jianxiong(Shoupai, t ^ 1))) {
						Qi->_v.push_back(Shoupai);
					}
				}
			}
		}
		else if (Shoupai.name == L"Shunshouqianyang") {
			if (Nex->_wujiang == L"Luxun") return 0;
			if (!Nex->_shoupai.size() && Nex->_wuqi.name == L"Wuwuqi" && Nex->_fangjv.name == L"Wufangjv") {
				return 0;
			}
			DrawKapai(Shoupai, 400, 200);
			UpdateFmodSystem();
			Sleep(1000);
			PlayFmodSound(&Shunshouqianyang1, true);
			Now->Del(Now->GetIt(k, t), t);
			FlushBatchDraw();
			if (Nex->AskWuxie(t ^ 1)) {
				;
			}
			else {
				if (t == 0) {
					if (Nex->_fangjv.name != L"Wufangjv") {
						Now->_shoupai.push_back(Nex->_fangjv);
						DrawKapai(Nex->_fangjv, 400, 200);
						FlushBatchDraw();
						Sleep(1000);
						Nex->_fangjv.name = L"Wufangjv";
						Nex->_fangjv.zhongwen = L"无防具";
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
						else used = 0;
					}
					else {
						QuickText(L"请输入要获得牌的区域,1表示手牌,2表示防具,3表示武器", 200, 325, 800, 350, 25, 0);
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
				}
			}
		}
		else if (Shoupai.name == L"Wanjianqifa") {
			DrawKapai(Shoupai, 400, 200);
			FlushBatchDraw();
			UpdateFmodSystem();
			PlayFmodSound(&Wanjianqifa1, true);
			Sleep(1000);
			Now->Del(Now->GetIt(k, t), t);
			if (Nex->AskWuxie(t ^ 1)) {
				;
			}
			else {
				bool Xiangying=Nex->AskShan(1, t ^ 1);
				if (!Xiangying) {
					Nex->ChangeHp(-1, t ^ 1);
					if (!(Nex->Jianxiong(Shoupai, t ^ 1))) {
						Qi->_v.push_back(Shoupai);
					}
				}
			}
		}
		else if (Shoupai.name == L"Wuzhongshengyou") {
			DrawKapai(Shoupai, 400, 200);
			FlushBatchDraw();
			UpdateFmodSystem();
			PlayFmodSound(&Wuzhongshengyou1, true);
			Sleep(1000);
			Now->Del(Now->GetIt(k, t), t);
			if (Nex->AskWuxie(t ^ 1)) {
				;
			}
			else {
				Now->Mopai(2, t);
			}
		}
		else if (Shoupai.name == L"Shuiyanqijun") {
			DrawKapai(Shoupai, 400, 200);
			FlushBatchDraw();
			UpdateFmodSystem();
			PlayFmodSound(&Shuiyanqijun1, true);
			Sleep(1000);
			Now->Del(Now->GetIt(k, t), t);
			if (Nex->AskWuxie(t ^ 1)) {
				;
			}
			else {
				bool Xiangying=Nex->AskShui(t ^ 1);
				if (!Xiangying) {
					Nex->ChangeHp(-1, t ^ 1);
					if (!(Nex->Jianxiong(Shoupai, t ^ 1))) {
						Qi->_v.push_back(Shoupai);
					}
				}
			}
		}
		else if (Shoupai.name == L"Bingliangcunduan") {
			DrawKapai(Shoupai, 400, 200);
			UpdateFmodSystem();
			PlayFmodSound(&Bingliangcunduan1, true);
			if (Nex->_yanshi1.name == L"Wuyanshi") {
				Nex->_yanshi1 = Shoupai;
			}
			else {
				Nex->_yanshi2 = Shoupai;
			}
			FlushBatchDraw();
			Sleep(1000);
			Now->Del(Now->GetIt(k, t), t);
		}
		else  {
			used = 0;
		}
	}
	if (!used) {
		return 0;
		//Now->Del(Now->GetIt(k,t), t);
	}
	else {
		return 1;
	}
}


void GameObject::ChangeHp(const int& hp, int t) {
	GameObject* Now = GetGameObject(t);
	Now->_hp += hp;
	if (hp < 0) {
		UpdateFmodSystem();
		PlayFmodSound(&Damage, true);
	}
	if (_hp <= 0) {
		if (!AskTao(t)) {
			Win = t ^ 1;
			return ;
		}
		else _hp++;
	}
	if (hp < 0) {
		Yiji(t);
		Fankui(t);
	}
	Draw(t); FlushBatchDraw();
}

void GameObject::UseWuqi(const Kapai& wuqi, int t) {
	GameObject* Now = GetGameObject(t);
	DrawKapai(wuqi, 400, 200);
	FlushBatchDraw();
	UpdateFmodSystem();
	PlayFmodSound(&Equipwuqi, true);
	Sleep(1000);
	if ((Now->_wuqi).name != L"Wuwuqi") {
		Paidui* Qi = GetQipaidui();
		Qi->_v.push_back((Now->_wuqi));
		Now->Xiaoji(t);
		DrawKapai(Now->_wuqi, 400, 200);
		FlushBatchDraw();
		Sleep(1000);
	}
	Now->_wuqi = wuqi;
}

void GameObject::UseFangjv(const Kapai& fangjv, int t) {
	GameObject* Now = GetGameObject(t);
	DrawKapai(fangjv, 400, 200);
	FlushBatchDraw();
	UpdateFmodSystem();
	PlayFmodSound(&Equipfangjv, true);
	Sleep(1000);
	if ((Now->_fangjv).name != L"Wufangjv") {
		Paidui* Qi = GetQipaidui();
		Qi->_v.push_back((Now->_fangjv));
		Now->Xiaoji(t);
		DrawKapai(Now->_fangjv, 400, 200);
		FlushBatchDraw();
		Sleep(1000);
	}
	Now->_fangjv = fangjv;
}


#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Xuchu::Xuchu()
	:Interface(L"Xuchu")
{

}
Xuchu::~Xuchu()
{

}
void Xuchu::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Xuchu::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Luoyi1, true);
	else PlayFmodSound(&Luoyi2, true);
}

void Xuchu::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"许褚", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"裸衣：摸牌阶段，你看可以少摸一张牌，然后本回合当你使用【杀】或【决斗】\n对对手造成伤害时，此伤害+1。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	RECT rect3{ 0,350,1000,450 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"挟缠：限定技，出牌阶段，你可以与对手拼点。若你赢，你视为对其使用一张【决斗】。\n若你没赢，其视为对你使用一张【决斗】。", &rect3, DT_CENTER | DT_VCENTER);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Xuzhu.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}
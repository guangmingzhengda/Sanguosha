#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Lvbu::Lvbu()
	:Interface(L"Lvbu")
{

}
Lvbu::~Lvbu()
{

}
void Lvbu::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Lvbu::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Wushuang1, true);
	else PlayFmodSound(&Wushuang2, true);
}

void Lvbu::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"吕布", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"无双：锁定技，你使用的【杀】需要两张【闪】才能抵消；\n对手每次响应与你的【决斗】需要打出两张【杀】。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Lvbu.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}


#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Lvmeng::Lvmeng()
	:Interface(L"Lvmeng")
{

}
Lvmeng::~Lvmeng()
{

}
void Lvmeng::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Lvmeng::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Botu1, true);
	else PlayFmodSound(&Botu2, true);
}

void Lvmeng::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"吕蒙", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"慎拒：锁定技，你的手牌上限+X（X为对手的体力值）。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style2);

	RECT rect3{ 0,350,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"博图：回合结束后，若你于出牌阶段内使用过四种花色的牌，\n则你可以获得一个额外回合。", &rect3, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Lvmeng.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

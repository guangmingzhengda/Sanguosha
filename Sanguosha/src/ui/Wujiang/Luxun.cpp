
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Luxun::Luxun()
	:Interface(L"Luxun")
{

}
Luxun::~Luxun()
{

}
void Luxun::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Luxun::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Lianying1, true);
	else PlayFmodSound(&Lianying2, true);
}

void Luxun::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"陆逊", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"谦逊：锁定技，你不能被选择为【顺手牵羊】和【乐不思蜀】的目标。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect3{ 0,350,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"连营：当你失去最后的手牌时，你可摸一张牌。", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Luxun.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

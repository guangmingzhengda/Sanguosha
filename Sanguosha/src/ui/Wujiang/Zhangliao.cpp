

#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Zhangliao::Zhangliao()
	:Interface(L"Zhangliao")
{

}
Zhangliao::~Zhangliao()
{

}
void Zhangliao::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Zhangliao::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Tuxi1, true);
	else PlayFmodSound(&Tuxi2, true);
}

void Zhangliao::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"张辽", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"突袭：摸牌阶段，若你的手牌少于对手，则你可以少摸一张牌并获得其的一张手牌。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Zhangliao.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

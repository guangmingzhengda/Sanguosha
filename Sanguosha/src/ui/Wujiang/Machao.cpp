
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Machao::Machao()
	:Interface(L"Machao")
{

}
Machao::~Machao()
{

}
void Machao::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Machao::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Tieji1, true);
	else PlayFmodSound(&Tieji2, true);
}

void Machao::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"马超", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"铁骑：当你对对手使用【杀】后，你可以进行判定，\n若结果为红色，则其不能使用【闪】响应此【杀】。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	RECT rect3{ 0,350,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"骁袭：当你登场时，你可以视为使用一张普通【杀】。", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Machao.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

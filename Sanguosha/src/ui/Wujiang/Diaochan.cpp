#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Diaochan::Diaochan()
	:Interface(L"Diaochan")
{

}
Diaochan::~Diaochan()
{

}
void Diaochan::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Diaochan::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Biyue1, true);
	else PlayFmodSound(&Biyue2, true);
}

void Diaochan::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"貂蝉", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"闭月：结束阶段，你可以摸一张牌。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Diaochan.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}


#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Xiahoudun::Xiahoudun()
	:Interface(L"Xiahoudun")
{

}
Xiahoudun::~Xiahoudun()
{

}
void Xiahoudun::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Xiahoudun::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Ganglie1, true);
	else PlayFmodSound(&Ganglie2, true);
}

void Xiahoudun::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"夏侯惇", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"刚烈：当你受到伤害后，你可以进行判定，若结果不为红桃，则伤害来源选择一项：\n1.弃置两张手牌：2.受到你造成的1点伤害。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Xiahoudun.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

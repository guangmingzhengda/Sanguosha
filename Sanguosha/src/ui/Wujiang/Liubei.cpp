
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Liubei::Liubei()
	:Interface(L"Liubei")
{

}
Liubei::~Liubei()
{

}
void Liubei::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Liubei::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Renwang1, true);
	else PlayFmodSound(&Renwang2, true);
}

void Liubei::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"刘备", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"仁望：当对手于出牌阶段对你使用【杀】或普通锦囊牌时，若你不是此阶段第一次成为上述牌的目标，\n则你可以弃置其一张牌。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);


	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Liubei.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

//	QuickText(L"仁望：当对手于其出牌\n阶段对你使用【杀】或普通锦囊牌时，若\n你不是此阶段第一次成为上述牌\n的目标，则你可以弃置其一张牌。", 0, 300, 1000, 200, 15, 1);
}


#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Huanggai::Huanggai()
	:Interface(L"Huanggai")
{

}
Huanggai::~Huanggai()
{

}
void Huanggai::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Huanggai::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Kurou1, true);
	else PlayFmodSound(&Kurou2, true);
}

void Huanggai::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"黄盖", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"苦肉：出牌阶段，你可以失去1点技能，然后摸两张牌。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);


	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Huanggai.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

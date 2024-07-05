
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Ganning::Ganning()
	:Interface(L"Ganning")
{

}
Ganning::~Ganning()
{

}
void Ganning::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Ganning::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Qixi1, true);
	else PlayFmodSound(&Qixi2, true);
}

void Ganning::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"甘宁", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"奇袭：你可以将一张黑色牌当【过河拆桥】使用。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Ganning.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

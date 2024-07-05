
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Zhangfei::Zhangfei()
	:Interface(L"Zhangfei")
{

}
Zhangfei::~Zhangfei()
{

}
void Zhangfei::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Zhangfei::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Paoxiao1, true);
	else PlayFmodSound(&Paoxiao2, true);
}

void Zhangfei::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"张飞", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"咆哮：锁定技，你使用【杀】无次数限制。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Zhangfei.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

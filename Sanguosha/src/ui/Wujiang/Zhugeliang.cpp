
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Zhugeliang::Zhugeliang()
	:Interface(L"Zhugeliang")
{

}
Zhugeliang::~Zhugeliang()
{

}
void Zhugeliang::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Zhugeliang::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Guanxing1, true);
	else PlayFmodSound(&Guanxing2, true);
}

void Zhugeliang::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"诸葛亮", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"观星：准备阶段，你可以观看牌堆顶的两张牌，将其中任意数量的牌置于牌堆顶，\n然后将其余的牌置于牌堆底。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style2);

	RECT rect3{ 0,350,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"空城：锁定技，若你没有手牌，则你不能被选择为【杀】或【决斗】的目标。", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Zhugeliang.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

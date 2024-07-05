
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Binglaingcunduan::Binglaingcunduan()
	:Interface(L"Binglaingcunduan")
{

}
Binglaingcunduan::~Binglaingcunduan()
{

}
void Binglaingcunduan::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Binglaingcunduan::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"兵粮寸断[1张]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"出牌阶段，对其他角色使用，准备阶段该角色进行一次判定，\n除非判定结果为梅花，否则跳过其摸牌阶段。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Bingliangcunduan.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);
}

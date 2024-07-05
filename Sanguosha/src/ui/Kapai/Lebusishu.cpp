
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Lebusishu::Lebusishu()
	:Interface(L"Lebusishu")
{

}
Lebusishu::~Lebusishu()
{

}
void Lebusishu::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Lebusishu::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"乐不思蜀[1张]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"出牌阶段，对其他角色使用，准备阶段该角色进行一次判定，除非判定结果为红桃，否则跳过其出牌阶段。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);


	IMAGE kapai;
	loadimage(&kapai, L"res/Lebusishu.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}

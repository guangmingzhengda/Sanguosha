
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Juedou::Juedou()
	:Interface(L"Juedou")
{

}
Juedou::~Juedou()
{

}
void Juedou::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Juedou::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"决斗[2张]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"出牌阶段对其他角色使用，其与你轮流打出【杀】，先不能打出【杀】的角色\n受到另一名角色对其造成的一点伤害", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Juedou.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}

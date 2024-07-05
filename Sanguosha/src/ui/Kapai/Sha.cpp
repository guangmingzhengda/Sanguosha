#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Sha::Sha()
	:Interface(L"Sha")
{

}
Sha::~Sha()
{

}
void Sha::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Sha::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"杀[16张]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"出牌阶段对其他角色使用，效果是对该角色造成一点伤害。每个出牌阶段你只能使用一张【杀】。", &rect2, DT_CENTER | DT_VCENTER |DT_SINGLELINE);
	settextstyle(&style2);

	IMAGE kapai;
	loadimage(&kapai, L"res/Sha.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}

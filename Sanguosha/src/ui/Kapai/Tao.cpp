
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Tao::Tao()
	:Interface(L"Tao")
{

}
Tao::~Tao()
{

}
void Tao::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Tao::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"桃[4张]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"出牌阶段，你可以对自己使用回复1点体力。当有角色处于濒死状态时，\n你可以对其使用令其回复1点体力。", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Tao.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}

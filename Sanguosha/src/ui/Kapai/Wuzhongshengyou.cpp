
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Wuzhongshengyou::Wuzhongshengyou()
	:Interface(L"Wuzhongshengyou")
{

}
Wuzhongshengyou::~Wuzhongshengyou()
{

}
void Wuzhongshengyou::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Wuzhongshengyou::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"��������[2��]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"���ƽ׶Σ������Լ�ʹ�ã��������ơ�", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Wuzhongshengyou.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}


#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Wuxiekeji::Wuxiekeji()
	:Interface(L"Wuxiekeji")
{

}
Wuxiekeji::~Wuxiekeji()
{

}
void Wuxiekeji::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Wuxiekeji::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"��и�ɻ�[2��]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"��Ŀ�������Чǰ���������һ����ɫ������Ч����", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Wuxiekeji.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}
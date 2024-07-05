
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Hanbingjian::Hanbingjian()
	:Interface(L"Hanbingjian")
{

}
Hanbingjian::~Hanbingjian()
{

}
void Hanbingjian::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Hanbingjian::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"������[1��]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"����ʹ�á�ɱ������˺�ʱ������Է�ֹ���˺�����Ϊ���ø�Ŀ���ɫ�������ơ�", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Hanbingjian.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}

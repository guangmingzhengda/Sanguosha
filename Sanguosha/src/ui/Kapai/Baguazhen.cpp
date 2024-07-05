//Fixed
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Baguazhen::Baguazhen()
	:Interface(L"Baguazhen")
{

}
Baguazhen::~Baguazhen()
{

}
void Baguazhen::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Baguazhen::Draw()
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
	drawtext(L"ÿ������Ҫʹ�ã�������һ�š�����ʱ������Խ���һ���ж���\n�����Ϊ��ɫ������Ϊ��ʹ�ã���������һ�š�������", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Baguazhen.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);
}

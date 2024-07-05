
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Shuiyanqijun::Shuiyanqijun()
	:Interface(L"Shuiyanqijun")
{

}
Shuiyanqijun::~Shuiyanqijun()
{

}
void Shuiyanqijun::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Shuiyanqijun::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"ˮ���߾�[1��]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"���ƽ׶ζ�������ɫʹ�ã���������װ�����������ƣ�����һ�ţ���\n�����ܵ��������ɵ�һ���˺���", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Shuiyanqijun.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}

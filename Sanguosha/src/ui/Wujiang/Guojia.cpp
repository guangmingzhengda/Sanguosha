
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Guojia::Guojia()
	:Interface(L"Guojia")
{

}
Guojia::~Guojia()
{

}
void Guojia::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Guojia::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Yiji1, true);
	else PlayFmodSound(&Yiji2, true);
}

void Guojia::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"����", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,300,1000,200 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"��ʣ�������ж�����Ч������Ի�ô��ơ�", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect3{ 0,400,1000,200 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"�żƣ������ܵ�1���˺�������Ի���ƶѶ��������ơ�", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Guojia.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

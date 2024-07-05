
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Simayi::Simayi()
	:Interface(L"Simayi")
{

}
Simayi::~Simayi()
{

}
void Simayi::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Simayi::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Fankui1, true);
	else PlayFmodSound(&Fankui2, true);
}

void Simayi::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"˾��ܲ", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"�����������ܵ��˺�ʱ������Ի���˺���Դ��һ���ơ�", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect3{ 0,350,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"��ţ���������ɫ���ж�����Чǰ������Խ�һ���ƴ���֮��", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Simayi.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

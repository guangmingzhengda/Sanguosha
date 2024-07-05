
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Lvmeng::Lvmeng()
	:Interface(L"Lvmeng")
{

}
Lvmeng::~Lvmeng()
{

}
void Lvmeng::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Lvmeng::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Botu1, true);
	else PlayFmodSound(&Botu2, true);
}

void Lvmeng::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"����", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"���ܣ��������������������+X��XΪ���ֵ�����ֵ����", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style2);

	RECT rect3{ 0,350,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"��ͼ���غϽ����������ڳ��ƽ׶���ʹ�ù����ֻ�ɫ���ƣ�\n������Ի��һ������غϡ�", &rect3, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Lvmeng.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

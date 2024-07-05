
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Zhenji::Zhenji()
	:Interface(L"Zhenji")
{

}
Zhenji::~Zhenji()
{

}
void Zhenji::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Zhenji::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Luoshen1, true);
	else PlayFmodSound(&Luoshen2, true);
}

void Zhenji::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"�缧", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"����׼���׶Σ�����Խ����ж��������Ϊ��ɫ�������ô��ƣ�\nȻ��������ظ������̡�", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);

	RECT rect3{ 0,350,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"���������Խ����װ�����Ƶ�������ʹ�ã���������", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Zhenji.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}


#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Zhaoyun::Zhaoyun()
	:Interface(L"Zhaoyun")
{

}
Zhaoyun::~Zhaoyun()
{

}
void Zhaoyun::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Zhaoyun::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Longdan1, true);
	else PlayFmodSound(&Longdan2, true);
}

void Zhaoyun::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"����", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"����������Խ�һ�š�ɱ����������������������ɱ��ʹ�û�����", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Zhaoyun.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

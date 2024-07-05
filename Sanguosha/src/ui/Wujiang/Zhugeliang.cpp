
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Zhugeliang::Zhugeliang()
	:Interface(L"Zhugeliang")
{

}
Zhugeliang::~Zhugeliang()
{

}
void Zhugeliang::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Zhugeliang::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Guanxing1, true);
	else PlayFmodSound(&Guanxing2, true);
}

void Zhugeliang::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"�����", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,350 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"���ǣ�׼���׶Σ�����Թۿ��ƶѶ��������ƣ������������������������ƶѶ���\nȻ��������������ƶѵס�", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style2);

	RECT rect3{ 0,350,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"�ճǣ�������������û�����ƣ����㲻�ܱ�ѡ��Ϊ��ɱ���򡾾�������Ŀ�ꡣ", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Zhugeliang.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

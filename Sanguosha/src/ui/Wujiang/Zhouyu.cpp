
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Zhouyu::Zhouyu()
	:Interface(L"Zhouyu")
{

}
Zhouyu::~Zhouyu()
{

}
void Zhouyu::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Zhouyu::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Yingzi1, true);
	else PlayFmodSound(&Yingzi2, true);
}


void Zhouyu::Draw()
{

	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"���", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"Ӣ�ˣ����ƽ׶Σ�����Զ���һ���ơ�", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect3{ 0,350,1000,450 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"���䣺���ƽ׶���һ�Σ�����������ѡ��һ�ֻ�ɫ��Ȼ�������һ�����ƣ�\n���˻�ɫ������ѡ��ɫ��ͬ������������һ���˺���", &rect3, DT_CENTER | DT_VCENTER);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Zhouyu.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}


#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Liubei::Liubei()
	:Interface(L"Liubei")
{

}
Liubei::~Liubei()
{

}
void Liubei::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Liubei::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Renwang1, true);
	else PlayFmodSound(&Renwang2, true);
}

void Liubei::Draw()
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
	drawtext(L"�������������ڳ��ƽ׶ζ���ʹ�á�ɱ������ͨ������ʱ�����㲻�Ǵ˽׶ε�һ�γ�Ϊ�����Ƶ�Ŀ�꣬\n�������������һ���ơ�", &rect2, DT_CENTER | DT_VCENTER);
	settextstyle(&style);


	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Liubei.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

//	QuickText(L"�������������������\n�׶ζ���ʹ�á�ɱ������ͨ������ʱ����\n�㲻�Ǵ˽׶ε�һ�γ�Ϊ������\n��Ŀ�꣬�������������һ���ơ�", 0, 300, 1000, 200, 15, 1);
}

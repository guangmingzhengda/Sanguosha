
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Huangyueying::Huangyueying()
	:Interface(L"Huangyueying")
{

}
Huangyueying::~Huangyueying()
{

}
void Huangyueying::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Huangyueying::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Jizhi1, true);
	else PlayFmodSound(&Jizhi2, true);
}

void Huangyueying::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"����Ӣ", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"���ǣ�����ʹ��һ�Ž�����ʱ���������һ���ơ�", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Huangyueying.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

	//RECT rect3{ 0,400,1000,200 };
	//LOGFONT style3;
	//gettextstyle(&style3);
	//settextstyle(25, 0, L"STXINWEI");
	//drawtext(L"�ػ�����������ʱ������Խ�װ��������������Ƴ���Ϸ��Ȼ�������һ����ɫ�ǳ�ʱ���㽫��Щ���������װ������", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//settextstyle(&style3);
}

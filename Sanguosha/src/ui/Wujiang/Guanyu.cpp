
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Guanyu::Guanyu()
	:Interface(L"Guanyu")
{

}
Guanyu::~Guanyu()
{

}
void Guanyu::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Wujiang");
	}
}

void Guanyu::OnEnter() {
	if (rand() & 1) PlayFmodSound(&Wusheng1, true);
	else PlayFmodSound(&Wusheng2, true);
}

void Guanyu::Draw()
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
	drawtext(L"��ʥ������Խ�һ�ź�ɫ�Ƶ���ͨ��ɱ��ʹ�û�����", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect3{ 0,3500,1000,400 };
	LOGFONT style3;
	gettextstyle(&style3);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"��������ǳ�ʱ������Ϊ�Զ���ʹ��һ�š�ˮ���߾�����", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style3);

	IMAGE Wujiang;
	loadimage(&Wujiang, L"res/Guanyu.png", 168, 216, 1);
	PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

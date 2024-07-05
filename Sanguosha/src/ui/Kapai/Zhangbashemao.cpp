//Fixed half
#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Zhangbashemao::Zhangbashemao()
	:Interface(L"Zhangbashemao")
{

}
Zhangbashemao::~Zhangbashemao()
{

}
void Zhangbashemao::Update()
{

	if (IsKeyDown(VK_ESCAPE)) {
		GetApplication()->ChangeInterface(L"Kapai");
	}
}
void Zhangbashemao::Draw()
{
	RECT rect{ 0,0,1000,200 };
	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"STXINWEI");
	drawtext(L"�ɰ���ì[1��]", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	RECT rect2{ 0,250,1000,300 };
	LOGFONT style2;
	gettextstyle(&style2);
	settextstyle(25, 0, L"STXINWEI");
	drawtext(L"������Ҫʹ�ã�������һ�š�ɱ��ʱ������Խ��������Ƶ�һ�š�ɱ��ʹ�ã���������", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	IMAGE kapai;
	loadimage(&kapai, L"res/Zhangbashemao.png", 115, 161, 1);
	PutAlphaImage(nullptr, 10, 10, &kapai);

}

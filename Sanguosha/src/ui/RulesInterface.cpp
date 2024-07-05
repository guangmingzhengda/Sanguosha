#include "../../inc/ui/Interface.h"
#include "../../inc/Message.h"
#include "../../inc/Globals.h"
#include "../../inc/ui/Application.h"

RulesInterface::RulesInterface()
    : Interface(L"Rules")
{

}

RulesInterface::~RulesInterface()
{

}
void RulesInterface::Update()
{


    if (IsKeyDown(VK_ESCAPE)) {
        GetApplication()->ChangeInterface(L"Main");
    }
}

void RulesInterface::Draw()
{
    RECT rect{ 0,0,1000,200 };
    LOGFONT style;
    gettextstyle(&style);
    settextstyle(100, 0, L"STXINWEI");
    drawtext(L"����", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);

    QuickText(L"* ÿ���غ�����Ϊ�ж��׶Ρ����ƽ׶Ρ����ƽ׶Ρ����ƽ׶Σ�\n\
* �ж��׶λ������ʱ������Ƶ��ж�����[�ֲ�˼��]��[�������]��\n\
* ���ƽ׶�ÿ���佫������2���ƣ�\n\
* ���ƽ׶��ڣ�����ʹ��һ��[ɱ]��\n\
* ���ƽ׶Σ����������ܳ�����ǰ����ֵ������������������ֵ��ȣ�\n\
* ����ֵ�ۼ���0ʱ������ʹ��[��]��������������Ϸʧ�ܣ��Է�ʤ����\n\
* �������佫���ܼ�[ͼ��]�����ڹ������ȼ����佫>����>��������\n\
        ", 100, 180, 900, 380, 25, 2);

    QuickText(L"���ͨ������ѡ�����һ�����ƣ���[Backspace]�������غ�\n\
��[W]������������������([�ɰ���ì])\n\
��[S]�������佫��������([�ƺ�]��)\n\
��[esc]������һ����(��Ϸ�лغ��ڰ�[esc]Ͷ��)\
", 100, 380, 900, 500, 25, 2);
}

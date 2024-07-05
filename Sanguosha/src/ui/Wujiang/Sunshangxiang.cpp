#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
Sunshangxiang::Sunshangxiang()
    :Interface(L"Sunshangxiang")
{

}
Sunshangxiang::~Sunshangxiang()
{

}
void Sunshangxiang::Update()
{

    if (IsKeyDown(VK_ESCAPE)) {
        GetApplication()->ChangeInterface(L"Wujiang");
    }
}

void Sunshangxiang::OnEnter() {
    if (rand() & 1) PlayFmodSound(&Xiaoji1, true);
    else PlayFmodSound(&Xiaoji2, true);
}

void Sunshangxiang::Draw()
{
    RECT rect{ 0,0,1000,200 };
    LOGFONT style;
    gettextstyle(&style);
    settextstyle(100, 0, L"STXINWEI");
    drawtext(L"孙尚香", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);

    RECT rect2{ 0,250,1000,300 };
    LOGFONT style2;
    gettextstyle(&style2);
    settextstyle(25, 0, L"STXINWEI");
    drawtext(L"枭姬：当你市区装备区里的一张牌时，你可以摸两张牌或回复一点体力。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style2);

    RECT rect3{ 0,350,1000,400 };
    LOGFONT style3;
    gettextstyle(&style3);
    settextstyle(25, 0, L"STXINWEI");
    drawtext(L"姻礼：对手的回合内，当其装备牌置入弃牌堆时，你可以获得之。", &rect3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style3);

    IMAGE Wujiang;
    loadimage(&Wujiang, L"res/Sunshangxiang.png", 168, 216, 1);
    PutAlphaImage(nullptr, 10, 10, &Wujiang);

}
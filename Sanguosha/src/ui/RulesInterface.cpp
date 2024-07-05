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
    drawtext(L"规则", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);

    QuickText(L"* 每个回合依次为判定阶段、摸牌阶段、出牌阶段、弃牌阶段；\n\
* 判定阶段会进行延时类锦囊牌的判定，如[乐不思蜀]，[兵粮寸断]；\n\
* 摸牌阶段每名武将可以摸2张牌；\n\
* 出牌阶段内，至多使用一张[杀]；\n\
* 弃牌阶段，手牌数不能超过当前体力值，超出需弃至与体力值相等；\n\
* 体力值扣减到0时，除非使用[桃]，否则阵亡，游戏失败，对方胜利；\n\
* 卡牌与武将介绍见[图鉴]，关于规则优先级：武将>卡牌>基本规则。\n\
        ", 100, 180, 900, 380, 25, 2);

    QuickText(L"玩家通过键盘选择出哪一张手牌，按[Backspace]键结束回合\n\
按[W]键发动武器主动技能([丈八蛇矛])\n\
按[S]键发动武将主动技能([制衡]等)\n\
按[esc]返回上一界面(游戏中回合内按[esc]投降)\
", 100, 380, 900, 500, 25, 2);
}

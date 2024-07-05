// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../../inc/ui/Interface.h"
#include "../../../inc/Message.h"
#include "../../../inc/Globals.h"
#include "../../../inc/ui/Application.h"
#include"../../../inc/utils/image.h"
/*
#include "../../inc/utils/Random.h"
#include "../../inc/game/Bat.h"
#include "../../inc/game/Ball.h"
#include "../../inc/game/BatController.h"
#include <cstdio>
*/

Caocao::Caocao()
    : Interface(L"Caocao")
{

}

Caocao::~Caocao()
{

}
void Caocao::Update()
{


    if (IsKeyDown(VK_ESCAPE)) {
        GetApplication()->ChangeInterface(L"Wujiang");
    }
}

void Caocao::OnEnter() {
    if (rand() & 1) PlayFmodSound(&Jianxiong1, true);
    else PlayFmodSound(&Jianxiong2, true);
}


void Caocao::Draw()
{
    RECT rect{ 0,0,1000,200 };
    LOGFONT style;
    gettextstyle(&style);
    settextstyle(100, 0, L"STXINWEI");
    drawtext(L"曹操", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);


    RECT rect2{ 0,250,1000,300 };
    LOGFONT style2;
    gettextstyle(&style2);
    settextstyle(25, 0, L"STXINWEI");
    drawtext(L"奸雄：当你受到伤害后，你可以获得对你造成伤害的牌。", &rect2, DT_CENTER | DT_VCENTER);
    settextstyle(&style);

    IMAGE Wujiang;
    loadimage(&Wujiang, L"res/Caocao.png", 168, 216, 1);
    PutAlphaImage(nullptr, 10, 10, &Wujiang);

}

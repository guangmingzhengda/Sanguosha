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

Sunquan::Sunquan()
    : Interface(L"Sunquan")
{

}

Sunquan::~Sunquan()
{

}
void Sunquan::Update()
{


    if (IsKeyDown(VK_ESCAPE)) {
        GetApplication()->ChangeInterface(L"Wujiang");
    }
}

void Sunquan::OnEnter() {
    if (rand() & 1) PlayFmodSound(&Zhiheng1, true);
    else PlayFmodSound(&Zhiheng2, true);
}

void Sunquan::Draw()
{
    RECT rect{ 0,0,1000,200 };
    LOGFONT style;
    gettextstyle(&style);
    settextstyle(100, 0, L"STXINWEI");
    drawtext(L"孙权", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);

    RECT rect2{ 0,250,1000,300 };
    LOGFONT style2;
    gettextstyle(&style2);
    settextstyle(25, 0, L"STXINWEI");
    drawtext(L"制衡：出牌阶段限一次，你可以弃置至多两张牌张牌，然后摸等量的牌。", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);


    IMAGE Wujiang;
    loadimage(&Wujiang, L"res/Sunquan.png", 168, 216, 1);
    PutAlphaImage(nullptr, 10, 10, &Wujiang);
}

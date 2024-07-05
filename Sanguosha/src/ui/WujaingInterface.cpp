// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/ui/Interface.h"
#include "../../inc/Message.h"
#include "../../inc/Globals.h"
#include "../../inc/ui/Application.h"
/*
#include "../../inc/utils/Random.h"
#include "../../inc/game/Bat.h"
#include "../../inc/game/Ball.h"
#include "../../inc/game/BatController.h"
#include <cstdio>
*/

WujiangInterface::WujiangInterface()
    : Interface(L"Wujiang")
{
    _pCaocaoButton = new Button(Rect(40,150,120,80), L"²Ü²Ù");
    _pCaocaoButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickCaocaoButton);
    _pSunquanButton = new Button(Rect(200, 150, 120, 80), L"ËïÈ¨");
    _pSunquanButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickSunquanButton);
    _pSunshangxiangButton = new Button(Rect(360, 150, 120, 80), L"ËïÉÐÏã");
    _pSunshangxiangButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickSunshangxiangButton);
    _pDiaochanButton = new Button(Rect(520, 150, 120, 80), L"õõ²õ");
    _pDiaochanButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickDiaochanButton);
    _pLvbuButton = new Button(Rect(680, 150, 120, 80), L"ÂÀ²¼");
    _pLvbuButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickLvbuButton);
    _pZhenjiButton = new Button(Rect(840, 150, 120, 80), L"Õç¼§");
    _pZhenjiButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickZhenjiButton);
    _pGuojiaButton = new Button(Rect(40, 250, 120, 80), L"¹ù¼Î");
    _pGuojiaButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickGuojiaButton);
    _pXuchuButton = new Button(Rect(200, 250, 120, 80), L"ÐíñÒ");
    _pXuchuButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickXuchuButton);
    _pZhangliaoButton = new Button(Rect(360, 250, 120, 80), L"ÕÅÁÉ");
    _pZhangliaoButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickZhangliaoButton);
    _pXiahoudunButton = new Button(Rect(520, 250, 120, 80), L"ÏÄºîª");
    _pXiahoudunButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickXiahoudunButton);
    _pSimayiButton = new Button(Rect(680, 250, 120, 80), L"Ë¾ÂíÜ²");
    _pSimayiButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickSimayiButton);
    _pLuxunButton = new Button(Rect(840, 250, 120, 80), L"Â½Ñ·");
    _pLuxunButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickLuxunButton);
    _pDaqiaoButton = new Button(Rect(40, 350, 120, 80), L"´óÇÇ");
    _pDaqiaoButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickDaqiaoButton);
    _pZhouyuButton = new Button(Rect(200, 350, 120, 80), L"ÖÜè¤");
    _pZhouyuButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickZhouyuButton);
    _pHuanggaiButton = new Button(Rect(360, 350, 120, 80), L"»Æ¸Ç");
    _pHuanggaiButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickHuanggaiButton);
    _pLvmengButton = new Button(Rect(520, 350, 120, 80), L"ÂÀÃÉ");
    _pLvmengButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickLvmengButton);
    _pGanningButton = new Button(Rect(680, 350, 120, 80), L"¸ÊÄþ");
    _pGanningButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickGanningButton);
    _pHuangyueyingButton = new Button(Rect(840, 350, 120, 80), L"»ÆÔÂÓ¢");
    _pHuangyueyingButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickHuangyueyingButton);
    _pMachaoButton = new Button(Rect(40, 450, 120, 80), L"Âí³¬");
    _pMachaoButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickMachaoButton);
    _pZhaoyunButton = new Button(Rect(200, 450, 120, 80), L"ÕÔÔÆ");
    _pZhaoyunButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickZhaoyunButton);
    _pZhugeliangButton = new Button(Rect(360, 450, 120, 80), L"Öî¸ðÁÁ");
    _pZhugeliangButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickZhugeliangButton);
    _pZhangfeiButton = new Button(Rect(520, 450, 120, 80), L"ÕÅ·É");
    _pZhangfeiButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickZhangfeiButton);
    _pGuanyvButton = new Button(Rect(680, 450, 120, 80), L"¹ØÓð");
    _pGuanyvButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickGuanyvButton);
    _pLiubeiButton = new Button(Rect(840, 450, 120, 80), L"Áõ±¸");
    _pLiubeiButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickLiubeiButton);
}

WujiangInterface::~WujiangInterface()
{
    delete _pCaocaoButton;
    delete _pSunquanButton;
    delete _pSunshangxiangButton;
    delete _pDiaochanButton;
    delete _pLvbuButton;
    delete _pZhenjiButton;
    delete _pGuojiaButton;
    delete _pXuchuButton;
    delete _pZhangliaoButton;
    delete _pXiahoudunButton;
    delete _pSimayiButton;
    delete _pLuxunButton;
    delete _pDaqiaoButton;
    delete _pZhouyuButton;
    delete _pHuanggaiButton;
    delete _pLvmengButton;
    delete _pGanningButton;
    delete _pHuangyueyingButton;
    delete _pMachaoButton;
    delete _pZhaoyunButton;
    delete _pZhugeliangButton;
    delete _pZhangfeiButton;
    delete _pGuanyvButton;
    delete _pLiubeiButton;
}
void WujiangInterface::Update()
{
    _pCaocaoButton->Update();
    _pSunquanButton->Update();
    _pSunshangxiangButton->Update();
    _pDiaochanButton->Update();
    _pLvbuButton->Update();
    _pZhenjiButton->Update();
    _pGuojiaButton->Update();
    _pXuchuButton->Update();
    _pZhangliaoButton->Update();
    _pXiahoudunButton->Update();
    _pSimayiButton->Update();
    _pLuxunButton->Update();
    _pDaqiaoButton->Update();
    _pZhouyuButton->Update();
    _pHuanggaiButton->Update();
    _pLvmengButton->Update();
    _pGanningButton->Update();
    _pHuangyueyingButton->Update();
    _pMachaoButton->Update();
    _pZhaoyunButton->Update();
    _pZhugeliangButton->Update();
    _pZhangfeiButton->Update();
    _pGuanyvButton->Update();
    _pLiubeiButton->Update();

    if (IsKeyDown(VK_ESCAPE)) {
        GetApplication()->ChangeInterface(L"Illustration");
    }
}

void WujiangInterface::Draw()
{
    RECT rect{ 0,0,1000,150 };
    LOGFONT style;
    gettextstyle(&style);
    settextstyle(100, 0, L"STXINWEI");
    drawtext(L"Îä½«", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);

    _pCaocaoButton->Draw();
    _pSunquanButton->Draw();
    _pSunshangxiangButton->Draw();
    _pDiaochanButton->Draw();
    _pLvbuButton->Draw();
    _pZhenjiButton->Draw();
    _pGuojiaButton->Draw();
    _pXuchuButton->Draw();
    _pZhangliaoButton->Draw();
    _pXiahoudunButton->Draw();
    _pSimayiButton->Draw();
    _pLuxunButton->Draw();
    _pDaqiaoButton->Draw();
    _pZhouyuButton->Draw();
    _pHuanggaiButton->Draw();
    _pLvmengButton->Draw();
    _pGanningButton->Draw();
    _pHuangyueyingButton->Draw();
    _pMachaoButton->Draw();
    _pZhaoyunButton->Draw();
    _pZhugeliangButton->Draw();
    _pZhangfeiButton->Draw();
    _pGuanyvButton->Draw();
    _pLiubeiButton->Draw();
}

void WujiangInterface::_OnClickCaocaoButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Caocao");
}

void WujiangInterface::_OnClickSunquanButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Sunquan");
}

void WujiangInterface::_OnClickSunshangxiangButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Sunshangxiang");
}

void WujiangInterface::_OnClickDiaochanButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Diaochan");
}

void WujiangInterface::_OnClickLvbuButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Lvbu");
}

void WujiangInterface::_OnClickZhenjiButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Zhenji");
}

void WujiangInterface::_OnClickGuojiaButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Guojia");
}

void WujiangInterface::_OnClickXuchuButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Xuchu");
}

void WujiangInterface::_OnClickZhangliaoButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Zhangliao");
}

void WujiangInterface::_OnClickXiahoudunButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Xiahoudun");
}

void WujiangInterface::_OnClickSimayiButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Simayi");
}

void WujiangInterface::_OnClickLuxunButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Luxun");
}

void WujiangInterface::_OnClickDaqiaoButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Daqiao");
}

void WujiangInterface::_OnClickZhouyuButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Zhouyu");
}

void WujiangInterface::_OnClickHuanggaiButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Huanggai");
}

void WujiangInterface::_OnClickLvmengButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Lvmeng");
}

void WujiangInterface::_OnClickGanningButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Ganning");
}

void WujiangInterface::_OnClickHuangyueyingButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Huangyueying");
}

void WujiangInterface::_OnClickMachaoButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Machao");
}

void WujiangInterface::_OnClickZhaoyunButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Zhaoyun");
}

void WujiangInterface::_OnClickZhugeliangButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Zhugeliang");
}

void WujiangInterface::_OnClickZhangfeiButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Zhangfei");
}

void WujiangInterface::_OnClickGuanyvButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Guanyu");
}

void WujiangInterface::_OnClickLiubeiButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Liubei");
}
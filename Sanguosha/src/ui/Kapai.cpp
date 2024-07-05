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

KapaiInterface::KapaiInterface()
    : Interface(L"Kapai")
{
    _pShaButton = new Button(Rect(40, 150, 120, 80), L"É±");
    _pShaButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickShaButton);
    _pShanButton = new Button(Rect(200, 150, 120, 80), L"ÉÁ");
    _pShanButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickShanButton);
    _pTaoButton = new Button(Rect(360, 150, 120, 80), L"ÌÒ");
    _pTaoButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickTaoButton);
    _pShunshouqianyangButton = new Button(Rect(520, 150, 120, 80), L"Ë³ÊÖÇ£Ñò");
    _pShunshouqianyangButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickShunshouqianyangButton);
    _pGuohechaiqiaoButton = new Button(Rect(680, 150, 120, 80), L"¹ýºÓ²ðÇÅ");
    _pGuohechaiqiaoButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickGuohechaiqiaoButton);
    _pJuedouButton = new Button(Rect(840, 150, 120, 80), L"¾ö¶·");
    _pJuedouButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickJuedouButton);
    _pWuzhongshengyouButton = new Button(Rect(40, 250, 120, 80), L"ÎÞÖÐÉúÓÐ");
    _pWuzhongshengyouButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickWuzhongshengyouButton);
    _pWuxiekejiButton = new Button(Rect(200, 250, 120, 80), L"ÎÞÐ¸¿É»÷");
    _pWuxiekejiButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickWuxiekejiButton);
    _pLebusishuButton = new Button(Rect(360, 250, 120, 80), L"ÀÖ²»Ë¼Êñ");
    _pLebusishuButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickLebusishuButton);
    _pBinglaingcunduanButton = new Button(Rect(520, 250, 120, 80), L"±øÁ¸´ç¶Ï");
    _pBinglaingcunduanButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickBinglaingcunduanButton);
    _pNanmanruqinButton = new Button(Rect(680, 250, 120, 80), L"ÄÏÂùÈëÇÖ");
    _pNanmanruqinButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickNanmanruqinButton);
    _pWanjianqifaButton = new Button(Rect(840, 250, 120, 80), L"Íò¼ýÆë·¢");
    _pWanjianqifaButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickWanjianqifaButton);
    _pShuiyanqijunButton = new Button(Rect(40, 350, 120, 80), L"Ë®ÑÍÆß¾ü");
    _pShuiyanqijunButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickShuiyanqijunButton);
    _pGuanshifuButton = new Button(Rect(200, 350, 120, 80), L"¹áÊ¯¸«");
    _pGuanshifuButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickGuanshifuButton);
    _pZhugeliannuButton = new Button(Rect(360, 350, 120, 80), L"Öî¸ðÁ¬åó");
    _pZhugeliannuButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickZhugeliannuButton);
    _pHanbingjianButton = new Button(Rect(520, 350, 120, 80), L"º®±ù¼ý");
    _pHanbingjianButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickHanbingjianButton);
    _pZhangbashemaoButton = new Button(Rect(680, 350, 120, 80), L"ÕÉ°ËÉßÃ¬");
    _pZhangbashemaoButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickZhangbashemaoButton);
    _pQinggangjianButton = new Button(Rect(840, 350, 120, 80), L"Çà¸Ö½£");
    _pQinggangjianButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickQinggangjianButton);
    _pBaguazhenButton = new Button(Rect(40, 450, 120, 80), L"°ËØÔÕó");
    _pBaguazhenButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickBaguazhenButton);
    _pRenwangdunButton = new Button(Rect(200, 450, 120, 80), L"ÈÊÍõ¶Ü");
    _pRenwangdunButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickRenwangdunButton);
}

KapaiInterface::~KapaiInterface()
{
    delete _pShaButton;
    delete _pShanButton;
    delete _pTaoButton;
    delete _pShunshouqianyangButton;
    delete _pGuohechaiqiaoButton;
    delete _pJuedouButton;
    delete _pWuzhongshengyouButton;
    delete _pWuxiekejiButton;
    delete _pLebusishuButton;
    delete _pBinglaingcunduanButton;
    delete _pNanmanruqinButton;
    delete _pWanjianqifaButton;
    delete _pShuiyanqijunButton;
    delete _pGuanshifuButton;
    delete _pZhugeliannuButton;
    delete _pHanbingjianButton;
    delete _pZhangbashemaoButton;
    delete _pQinggangjianButton;
    delete _pBaguazhenButton;
    delete _pRenwangdunButton;
}
void KapaiInterface::Update()
{
    _pShaButton->Update();
    _pShanButton->Update();
    _pTaoButton->Update();
    _pShunshouqianyangButton->Update();
    _pGuohechaiqiaoButton->Update();
    _pJuedouButton->Update();
    _pWuzhongshengyouButton->Update();
    _pWuxiekejiButton->Update();
    _pLebusishuButton->Update();
    _pBinglaingcunduanButton->Update();
    _pNanmanruqinButton->Update();
    _pWanjianqifaButton->Update();
    _pShuiyanqijunButton->Update();
    _pGuanshifuButton->Update();
    _pZhugeliannuButton->Update();
    _pHanbingjianButton->Update();
    _pZhangbashemaoButton->Update();
    _pQinggangjianButton->Update();
    _pBaguazhenButton->Update();
    _pRenwangdunButton->Update();

    if (IsKeyDown(VK_ESCAPE)) {
        GetApplication()->ChangeInterface(L"Illustration");
    }
}

void KapaiInterface::Draw()
{
    RECT rect{ 0,0,1000,150 };
    LOGFONT style;
    gettextstyle(&style);
    settextstyle(100, 0, L"STXINWEI");
    drawtext(L"¿¨ÅÆ", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);

    _pShaButton->Draw();
    _pShanButton->Draw();
    _pTaoButton->Draw();
    _pShunshouqianyangButton->Draw();
    _pGuohechaiqiaoButton->Draw();
    _pJuedouButton->Draw();
    _pWuzhongshengyouButton->Draw();
    _pWuxiekejiButton->Draw();
    _pLebusishuButton->Draw();
    _pBinglaingcunduanButton->Draw();
    _pNanmanruqinButton->Draw();
    _pWanjianqifaButton->Draw();
    _pShuiyanqijunButton->Draw();
    _pGuanshifuButton->Draw();
    _pZhugeliannuButton->Draw();
    _pHanbingjianButton->Draw();
    _pZhangbashemaoButton->Draw();
    _pQinggangjianButton->Draw();
    _pBaguazhenButton->Draw();
    _pRenwangdunButton->Draw();
}

void KapaiInterface::_OnClickShaButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Sha");
}

void KapaiInterface::_OnClickShanButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Shan");
}

void KapaiInterface::_OnClickTaoButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Tao");
}

void KapaiInterface::_OnClickShunshouqianyangButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Shunshouqianyang");
}

void KapaiInterface::_OnClickGuohechaiqiaoButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Guohechaiqiao");
}

void KapaiInterface::_OnClickJuedouButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Juedou");
}

void KapaiInterface::_OnClickWuzhongshengyouButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Wuzhongshengyou");
}

void KapaiInterface::_OnClickWuxiekejiButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Wuxiekeji");
}

void KapaiInterface::_OnClickLebusishuButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Lebusishu");
}

void KapaiInterface::_OnClickBinglaingcunduanButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Binglaingcunduan");
}

void KapaiInterface::_OnClickNanmanruqinButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Nanmanruqin");
}

void KapaiInterface::_OnClickWanjianqifaButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Wanjianqifa");
}

void KapaiInterface::_OnClickShuiyanqijunButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Shuiyanqijun");
}

void KapaiInterface::_OnClickGuanshifuButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Guanshifu");
}

void KapaiInterface::_OnClickZhugeliannuButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Zhugeliannu");
}

void KapaiInterface::_OnClickHanbingjianButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Hanbingjian");
}

void KapaiInterface::_OnClickZhangbashemaoButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Zhangbashemao");
}

void KapaiInterface::_OnClickQinggangjianButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Qinggangjian");
}

void KapaiInterface::_OnClickBaguazhenButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Baguazhen");
}

void KapaiInterface::_OnClickRenwangdunButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Renwangdun");
}
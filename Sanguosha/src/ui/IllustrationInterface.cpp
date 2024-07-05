#include "../../inc/ui/Interface.h"
#include "../../inc/Message.h"
#include "../../inc/Globals.h"
#include "../../inc/ui/Application.h"

IllustrationInterface::IllustrationInterface()
    : Interface(L"Illustration")
{
    _pWujiangButton = new Button(Rect(350, 280, 120, 80), L"Îä½«");
    _pWujiangButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickWujiangButton);
    _pKapaiButton = new Button(Rect(530, 280, 120, 80), L"¿¨ÅÆ");
    _pKapaiButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickKapaiButton);
}

IllustrationInterface::~IllustrationInterface()
{
    delete _pWujiangButton;
    delete _pKapaiButton;
}
void IllustrationInterface::Update()
{

    _pWujiangButton->Update();
    _pKapaiButton->Update();
    if (IsKeyDown(VK_ESCAPE)) {
        GetApplication()->ChangeInterface(L"Main");
    }
}

void IllustrationInterface::Draw()
{
    RECT rect{ 0,0,1000,280 };
    LOGFONT style;
    gettextstyle(&style);
    settextstyle(100, 0, L"STXINWEI");
    drawtext(L"Í¼¼ø", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);

    _pWujiangButton->Draw();
    _pKapaiButton->Draw();
}

void IllustrationInterface::_OnClickWujiangButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Wujiang");

}

void IllustrationInterface::_OnClickKapaiButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Kapai");
}
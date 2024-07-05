#include "../../inc/ui/Interface.h"
#include "../../inc/Globals.h"
#include "../../inc/ui/Application.h"

MainInterface::MainInterface()
    : Interface(L"Main")
{
    _pStartButton = new Button(Rect(350, 280, 120, 80), L"开始");
    _pStartButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickStartButton);

    _pRulesButton = new Button(Rect(550, 280, 120, 80), L"规则");
    _pRulesButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickRulesButton);

    _pExitButton = new Button(Rect(900, 460, 80, 80), L"退出");
    _pExitButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickExitButton);

    _pIllustrateButton = new Button(Rect(20, 460, 80, 80), L"图鉴");
    _pIllustrateButton->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
        ->SetOnClick(_OnClickIllustrateButton);
}

MainInterface::~MainInterface()
{
    delete _pStartButton;
    delete _pRulesButton;
    delete _pIllustrateButton;
    delete _pExitButton;
}

void MainInterface::Update()
{
    _pStartButton->Update();
    _pRulesButton->Update();
    _pIllustrateButton->Update();
    _pExitButton->Update();
}

void MainInterface::OnEnter()
{
    mciSendString(_T("close bkmusic"), NULL, 0, NULL);
    mciSendString(_T("open res/start.mp3 alias bkmusic"), NULL, 0, NULL);//播放音乐
    mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);//循环播放
}


void MainInterface::Draw()
{
    RECT rect{ 0, 0, 1000, 280 };

    LOGFONT style;
    gettextstyle(&style);
    settextstyle(100, 0, L"STXINWEI");
    drawtext(L"三国杀", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&style);

    _pStartButton->Draw();
    _pRulesButton->Draw();
    _pIllustrateButton->Draw();
    _pExitButton->Draw();
}

void MainInterface::_OnClickStartButton()
{
    Application* app = GetApplication();
    app->ChangeInterface(L"Game");
    /*
        gameMode = SINGLE_PLAYER;
        Application* app = GetApplication();
        app->ChangeInterface(L"Game");
    */
}

void MainInterface::_OnClickRulesButton()
{
    Application* app = GetApplication();
    app->ChangeInterface(L"Rules");
}

void MainInterface::_OnClickExitButton()
{
    
    isRunning = false;
}

void MainInterface::_OnClickIllustrateButton() {
    Application* app = GetApplication();
    app->ChangeInterface(L"Illustration");
}
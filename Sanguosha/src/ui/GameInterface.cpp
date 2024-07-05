#include "../../inc/ui/Interface.h"
#include "../../inc/Message.h"
#include "../../inc/Globals.h"
#include "../../inc/ui/Application.h"
#include"../../inc/utils/image.h"
#include"../../inc/game/GameObject.h"
#include"../../inc/Sound.h"
#include<random>

GameInterface::GameInterface() : Interface(L"Game")
{

}

GameInterface::~GameInterface()
{
}
int M = 11, N = 11;
void init(std::wstring s, std::wstring zh, int t, int xie) {
    GameObject* Now = GetGameObject(t);
    Now->_wujiang = s;
    Paidui* Mo = GetMopaidui();
    Now->_shoupai.clear();
    Now->Mopai(4, t);
    Kapai fangjv, wuqi;
    fangjv.name = L"Wufangjv";
    fangjv.zhongwen = L"无防具";
    wuqi.name = L"Wuwuqi";
    wuqi.zhongwen = L"无武器";
    Now->_fangjv = fangjv;
    Now->_wuqi = wuqi;
    Now->_hp = Now->_shangxian = xie;
    Now->_yanshi1.name = L"Wuyanshi";
    Now->_yanshi2.name = L"Wuyanshi";
    Now->_zhongwen = zh;
}
int flag = 1,turn=1,skill_time;
int Pandingjieduan, Mopaijieduan, Chupaijieduan, Qipaijieduan;
int times_sha;
void GameInterface::OnEnter()
{
    Pandingjieduan = Mopaijieduan = Chupaijieduan = Qipaijieduan = 0;
    turn = rand() % 2;
    //turn = 1;
    Sleep(1000);
    skill_time = 0;
    mciSendString(_T("close bkmusic"), NULL, 0, NULL);
    mciSendString(_T("open res/bgm.mp3 alias bkmusic"), NULL, 0, NULL);//播放音乐
    mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);//循环播放
    Paidui* Qi = GetQipaidui();
    Paidui* Mo = GetMopaidui();
    for (Kapai x : Qi->_v) {
        Mo->_v.push_back(x);
    }
    Qi->_v.clear();
    Mo->Shuffle();
    std::wstring na[20] = {}, zh[20] = {};
    int xie[20] = { 0 };
    std::map<char, std::wstring> mp;
    na[1] = L"Simayi"; zh[1] = L"司马懿"; xie[1] = 3;
    na[2] = L"Huangyueying"; zh[2] = L"黄月英"; xie[2] = 3;
    na[3] = L"Diaochan"; zh[3] = L"貂蝉"; xie[3] = 3;
    na[4] = L"Zhangfei"; zh[4] = L"张飞"; xie[4] = 4;
    na[5] = L"Luxun"; zh[5] = L"陆逊"; xie[5] = 3;
    na[6] = L"Sunshangxiang"; zh[6] = L"孙尚香"; xie[6] = 3;
    na[7] = L"Guojia"; zh[7] = L"郭嘉"; xie[7] = 3;
    na[8] = L"Daqiao"; zh[8] = L"大乔"; xie[8] = 3;
    na[9] = L"Zhouyu"; zh[9] = L"周瑜"; xie[9] = 3;
    na[10] = L"Sunquan"; zh[10] = L"孙权"; xie[10] = 4;
    na[11] = L"Caocao"; zh[11] = L"曹操"; xie[11] = 4;
    srand((unsigned int)time(NULL));
    int x = rand() % M + 1, y = rand() % N + 1;
    if (x == y) x = (y + 1) % M + 1;
    //y = 10;
//    x = 11;
//    y = 10;
 //   y = 2;
    init(na[x], zh[x], 0, xie[x]);
    init(na[y], zh[y], 1, xie[y]);
    //init(na[1], zh[1], 0, xie[1]);
    //init(na[10], zh[10], 1, xie[10]);
    Win = -1;
}

void _clear(int t) {
    GameObject* Now = GetGameObject(t);
    Paidui* Qi = GetQipaidui();
    for (Kapai x : Now->_shoupai) {
        Qi->_v.push_back(x);
    }
    if (Now->_fangjv.zhongwen != L"无防具") {
        Qi->_v.push_back(Now->_fangjv);
    }
    if (Now->_wuqi.zhongwen != L"无武器") {
        Qi->_v.push_back(Now->_wuqi);
    }
    if (Now->_yanshi1.name != L"Wuyanshi") {
        Qi->_v.push_back(Now->_yanshi1);
    }
    if (Now->_yanshi2.name != L"Wuyanshi") {
        Qi->_v.push_back(Now->_yanshi2);
    }
    Now->_shoupai.clear();
}

void GameInterface::OnExit()
{
    _clear(0);
    _clear(1);
}

std::wstring las = L"None",NEW=L"";
void GameInterface::Update()
{
    init_pri();
    GameObject* Diannao = GetGameObject(0);
    sort(Diannao->_shoupai.begin(), Diannao->_shoupai.end(), cmp_chu);
    GameObject* Now = GetGameObject(turn);
    Now->Draw(turn);
    GameObject* Nex = GetGameObject(turn^1);
    Nex->Draw(turn^1);
    FlushBatchDraw();
    if (turn == 1) {
        QuickText(L"当前为玩家回合", 0, 200, 300, 300, 30, 0);
    }
    else {
        QuickText(L"当前为电脑回合", 0, 200, 300, 300, 30, 0);
    }
    FlushBatchDraw();
    if (Win >= 0) {
        std::map<std::wstring, FmodSound> mpsound;
        mpsound[L"Caocao"] = Caocao1;
        mpsound[L"Huangyueying"] = Huangyueying1;
        mpsound[L"Diaochan"] = Diaochan1;
        mpsound[L"Luxun"] = Luxun1;
        mpsound[L"Sunshangxiang"] = Sunshangxiang1;
        mpsound[L"Guojia"] = Guojia1;
        mpsound[L"Simayi"] = Simayi1;
        mpsound[L"Daqiao"] = Daqiao1;
        mpsound[L"Sunquan"] = Sunquan1;
        mpsound[L"Zhouyu"] = Zhouyu1;
        mpsound[L"Zhangfei"] = Zhangfei1;
        if (Win == 1) {
            QuickText(L"恭喜你获得胜利", 0, 0, 1000, 560, 50, 0);
            PlayFmodSound(&mpsound[GetGameObject(0)->_wujiang], true);
        }
        else {
            QuickText(L"很遗憾你失败了", 0, 0, 1000, 560, 50, 0);
            PlayFmodSound(&mpsound[GetGameObject(1)->_wujiang], true);
        }
        QuickText(L"3秒后将返回主界面", 200, 300, 800, 350, 30, 0);
        FlushBatchDraw();
        Sleep(3000);
        Application* app = GetApplication();
        app->ChangeInterface(L"Main");
        return ;
    }
    if (!Pandingjieduan) {
        QuickText(L"现在是判定阶段", 0, 300, 300, 400, 30, 0);
        if (Now->_yanshi2.name != L"Wuyanshi") {
            Kapai pandingpai = Now->Panding(turn);
            if (Now->_yanshi2.name == L"Lebusishu") {
                if (pandingpai.huase == 1) {
                    QuickText(L"乐不思蜀失效", 600, 300, 800, 350, 25, 0);
                    Chupaijieduan = 0;
                }
                else {
                    QuickText(L"乐不思蜀生效", 600, 300, 800, 350, 25, 0);
                    Chupaijieduan = 1;
                }
            }
            else {
                if (pandingpai.huase == 2) {
                    QuickText(L"兵粮寸断失效", 600, 300, 800, 350, 25, 0);
                    Mopaijieduan = 0;
                }
                else {
                    QuickText(L"兵粮寸断生效", 600, 300, 800, 350, 25, 0);
                    Mopaijieduan = 1;
                }
            }
            DrawKapai(Now->_yanshi2, 400, 200);
            DrawKapai(pandingpai, 600, 200);
            FlushBatchDraw();
            Sleep(2000);
            Now->_yanshi2.name = L"Wuyanshi";

            Now->Tiandu(pandingpai, turn);
//            Paidui* Qi=GetQipaidui();
//            Qi->_v.push_back(pandingpai);
        }
        else if (Now->_yanshi1.name != L"Wuyanshi") {
            Kapai pandingpai = Now->Panding(turn);
            if (Now->_yanshi1.name == L"Lebusishu") {
                if (pandingpai.huase == 1) {
                    QuickText(L"乐不思蜀失效", 600, 300, 800, 350, 25, 0);
                    Chupaijieduan = 0;
                }
                else {
                    QuickText(L"乐不思蜀生效", 600, 300, 800, 350, 25, 0);
                    Chupaijieduan = 1;
                }
            }
            else {
                if (pandingpai.huase == 2) {
                    QuickText(L"兵粮寸断失效", 600, 300, 800, 350, 25, 0);
                    Mopaijieduan = 0;
                }
                else {
                    QuickText(L"兵粮寸断生效", 600, 300, 800, 350, 25, 0);
                    Mopaijieduan = 1;
                }
            }
            DrawKapai(Now->_yanshi1, 400, 200);
            DrawKapai(pandingpai, 600, 200);
            Now->_yanshi1.name = L"Wuyanshi";
            FlushBatchDraw();
            Sleep(2000);
            Now->Tiandu(pandingpai, turn);
            //Paidui* Qi = GetQipaidui();
            //Qi->_v.push_back(pandingpai);
        }
        else Pandingjieduan = 1;
    }
    else if (!Mopaijieduan) {
        Now->Yingzi(turn);
        Now->Mopai(2, turn);
        Mopaijieduan= 1;
    }
    else if(!Chupaijieduan) {
        QuickText(L"现在是出牌阶段", 0, 300, 300, 400, 30, 0);
        if (turn == 0) {
            bool used = 0;
            for (int i = 1; i <= (int)Now->_shoupai.size(); i++) {
                if (Now->GetKapai(i, turn).type == 2 && Now->_wuqi.name != L"Wuwuqi") continue;
                if (Now->GetKapai(i, turn).type == 3 && Now->_fangjv.name != L"Wufangjv") continue;
                bool Used=Now->UseShoupai(i, turn);
                if (!Used) continue;
                Now->Draw(turn);
                Nex->Draw(turn ^ 1);
                FlushBatchDraw();
                used = 1;
                break;
            }
            if (!used) {
                if (Now->_wujiang == L"Zhouyu" && skill_time < 1) {
                    skill_time++;
                    Now->Fanjiandiannao(turn);
                }
                else if (Now->_wujiang == L"Daqiao" && skill_time < 1 && Nex->_wujiang != L"Luxun") {
                    skill_time++;
                    if (Nex->_yanshi1.name != L"Lebusishu" && Nex->_yanshi2.name != L"Lebusishu") {
                        for (int i = 1; i <= (int)Now->_shoupai.size(); i++) {
                            Kapai shoupaii = Now->GetKapai(i, turn);
                            if (shoupaii.huase>4) continue;
                            else {

                                QuickText(L"发动了国色", 0, 0, 1000, 560, 100, 0);
                                FlushBatchDraw();
                                Sleep(2000);
                                UpdateFmodSystem();
                                if (rand() & 1) PlayFmodSound(&Guose1, true);
                                else PlayFmodSound(&Guose2, true);

                                UpdateFmodSystem();
                                PlayFmodSound(&Lebusishu1, true);
                                if (Nex->_yanshi1.name == L"Wuyanshi") {
                                    Nex->_yanshi1 = shoupaii;
                                    Nex->_yanshi1.name = L"Lebusishu";
                                    Nex->_yanshi1.zhongwen = L"乐不思蜀";
                                }
                                else if(Nex->_yanshi2.name == L"Wuyanshi") {
                                    Nex->_yanshi2 = shoupaii;
                                    Nex->_yanshi2.name = L"Lebusishu";
                                    Nex->_yanshi2.zhongwen=L"乐不思蜀";
                                }
                                Now->Del(Now->GetIt(i, turn), turn);
                                Nex->Draw(turn ^ 1);
                                FlushBatchDraw();
                                Sleep(2000);
                                break;
                            }
                        }
                    }

                }
                else Chupaijieduan = 1;
            }
        }
        else {
            PeekMouseMessage();
            FlushBatchDraw();
            std::wstring tmp = GetKey();
            if (tmp == L"Backspace") {
                Chupaijieduan = 1;
            }
            else if (Now->_shoupai.size() && isdigit(tmp[0])) {
                bool Used=Now->UseShoupai(tmp[0] - '0', turn);
                if (!Used) {
                    QuickText(L"当前状态无法使用此牌", 200,300,800,350,30,0);
                    FlushBatchDraw();
                    Sleep(1000);
                }
                Now->Draw(turn);
                Nex->Draw(turn^1);
                FlushBatchDraw();
            }
            else if (tmp[0] == 'W' && Now->_wuqi.name==L"Zhangbashemao" && (Now->_sha < 1 || Now->_wujiang == L"Zhangfei") && (int)Now->_shoupai.size() >= 2) {
                QuickText(L"可选择两张牌当杀使用,0代表取消", 200, 350, 800, 400, 25, 0);
                FlushBatchDraw();
                std::wstring tmp;
                int k1 = 0, k2 = 0;
                while (!k2) {
                    PeekMouseMessage();
                    tmp = GetKey();
                    if (tmp[0] == '0') break;
                    if (tmp == L"None") continue;
                    if (tmp[0] - '0' < 1 || tmp[0] - '0' > (int)Now->_shoupai.size()) {
                        if (!k1) tmp[0] = '1';
                        else tmp[0] = (int)Now->_shoupai.size() + '0';
                    }
                    if (!k1) k1 = tmp[0] - '0';
                    else k2 = tmp[0] - '0';
                }
                if (k1 && k2) {
                    if (k1 > k2) std::swap(k1, k2);
                    Kapai kapai1 = Now->GetKapai(k1, turn), kapai2 = Now->GetKapai(k2, turn);
                    DrawKapai(kapai1, 400, 200);
                    DrawKapai(kapai2, 500, 200);
                    FlushBatchDraw();
                    Sleep(1500);
                    Now->Del(Now->GetIt(k1, turn), turn);
                    Now->Del(Now->GetIt(k2 - 1, turn), turn);
                    Paidui* Qi = GetQipaidui();
                    Qi->_v.push_back(kapai1);
                    Qi->_v.push_back(kapai2);
                    bool Xiangying=Nex->AskShan(1, turn ^ 1);
                    if (!Xiangying) Nex->ChangeHp(-1, turn ^ 1);
                    Now->_sha++;
                }
            }
            else if (tmp[0] == 'S') {
                Paidui* Qi = GetQipaidui();
                if (Now->_wujiang == L"Daqiao") {//国色
                    QuickText(L"请选择一张方片牌当乐不思蜀使用,按0取消", 200, 350, 800, 400, 30, 0);
                    std::wstring ss;
                    FlushBatchDraw();
                    while (1) {
                        PeekMouseMessage();
                        ss = GetKey();
                        if (ss[0] == '0') {
                            break;
                        }
                        else if(isdigit(ss[0])) {
                            int ch = ss[0] - '0';
                            if (ss[0] - '0' > (int)Now->_shoupai.size()) ch = 1;
                            Kapai Le = Now->GetKapai(ch, turn);
                            if (Nex->_yanshi1.name == L"Lebusishu" || Nex->_yanshi2.name == L"Bingliangcunduan" || Le.huase != 3) {
                                QuickText(L"当前状态无法使用此牌", 200, 300, 800, 350, 30, 0);
                                FlushBatchDraw();
                            }
                            else {

                                UpdateFmodSystem();
                                if (rand() & 1) PlayFmodSound(&Guose1, true);
                                else PlayFmodSound(&Guose2, true);
                                
                                UpdateFmodSystem();
                                PlayFmodSound(&Lebusishu1, true);
                                if (Nex->_yanshi1.name == L"Wuyanshi") {
                                    Nex->_yanshi1 = Le;
                                    Nex->_yanshi1.name = L"Lebusishu";
                                    Now->Del(Now->GetIt(ch, turn), turn);
                                }
                                else {
                                    Nex->_yanshi2 = Le;
                                    Nex->_yanshi2.name = L"Lebusishu";
                                    Now->Del(Now->GetIt(ch, turn), turn);
                                }
                                FlushBatchDraw();
                                break;
                            }
                        }
                    }
                }
                else if (Now->_wujiang == L"Sunquan" && skill_time < 1) {
                    QuickText(L"请选择至多两张手牌制衡,按0取消,按回车确定", 200, 350, 800, 400, 30, 0);
                    FlushBatchDraw();
                    std::wstring ss;
                    int k1 = 0, k2 = 0;
                    while (1) {
                        PeekMouseMessage();
                        ss = GetKey();
                        if (ss[0] == '0') {
                            k1 = k2 = 0;
                            break;
                        }
                        else if (ss == L"Enter") {
                            break;
                        }
                        else if('1'<=ss[0]&&ss[0]<=(int)Now->_shoupai.size()+'0') {
                            if (!k1) k1 = ss[0] - '0';
                            else if (!k2) k2 = ss[0] - '0';
                            else k1 = k2, k2 = ss[0] - '0';
                        }
                    }
                    if (k1 || k2) {
                        UpdateFmodSystem();
                        if (rand() & 1) PlayFmodSound(&Zhiheng1, true);
                        else PlayFmodSound(&Zhiheng2, true);
                        skill_time++;
                        if (k1 == k2) k2 = 0;
                        if (k1 && k2) {
                            Qi->_v.push_back(Now->GetKapai(k1, turn));
                            Qi->_v.push_back(Now->GetKapai(k2, turn));
                            Now->Del(Now->GetIt(k1, turn), turn);
                            Now->Del(Now->GetIt(k2, turn), turn);
                            Now->Mopai(2, turn);
                            FlushBatchDraw();
                        }
                        else {
                            Qi->_v.push_back(Now->GetKapai(k1, turn));
                            Now->Del(Now->GetIt(k1, turn), turn);
                            Now->Mopai(1, turn);
                            FlushBatchDraw();
                        }
                    }
                }
                else if (Now->_wujiang == L"Zhouyu" && skill_time < 1 && Now->_shoupai.size() > 0) {
                    QuickText(L"发动技能反间,按0取消,按回车确定", 200, 350, 800, 400, 30, 0);
                    FlushBatchDraw();
                    std::wstring ss;
                    while (1) {
                        PeekMouseMessage();
                        ss = GetKey();
                        if (ss[0] == '0') {
                            break;
                        }
                        else if (ss == L"Enter") {
                            Now->Fanjian(turn);
                            skill_time++;
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (!Qipaijieduan) {
        if (Now->_shoupai.size() <= Now->_hp) {
            Qipaijieduan = 1;
        }
        else {
            QuickText(L"现在是弃牌阶段", 0, 300, 300, 400, 30, 0);
            if (turn == 0) {
                sort(Diannao->_shoupai.begin(), Diannao->_shoupai.end(), cmp_qi);
                if (Nex->_fangjv.name == L"Renwangdun") 
                    pri[L"Qinggangjian"] *= 5;
                if (Now->_hp < Now->_shangxian)
                    pri[L"Tao"]*=5;
                if (Nex->_hp <= 2) {
                    pri[L"Nanmanruqin"] *= 3;
                    pri[L"Wanjianqifa"] *= 3;
                    pri[L"Juedou"] *= 3;
                    pri[L"Shuiyanqijun"] *= 3;
                }
                Now->Del(Now->GetIt(1, turn), turn);
            }
            else {
                PeekMouseMessage();
                std::wstring tmp = GetKey();
                if (isdigit(tmp[0])) {
                    Now->Del(Now->GetIt(tmp[0] - '0', turn), turn);
                }
            }
        }
    }
    else {
        Now->Biyue(turn);
        Now->_sha = 0;
        Pandingjieduan = 0;
        Mopaijieduan = 0;
        Chupaijieduan = 0;
        Qipaijieduan = 0;
        times_sha = 0;
        skill_time = 0;
        turn ^= 1;
    }

    FlushBatchDraw();
    //if (IsKeyDown(VK_DELETE)) {
    //    cleardevice();
    //    Sleep(1000);
    //}
    if (IsKeyDown(VK_ESCAPE)) {
        QuickText(L"您已投降\n游戏失败", 200, 200, 800, 400, 80,1);
        FlushBatchDraw();
        Sleep(5000);
        GetApplication()->ChangeInterface(L"Main");
    }
}

void GameInterface::Draw()
{

}
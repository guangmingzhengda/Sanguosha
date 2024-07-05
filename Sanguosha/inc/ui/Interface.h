#pragma once

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <string>
#include <memory>
#include "Button.h"

class Interface
{
private:
    std::wstring _name;

public:
    Interface(const std::wstring& name) : _name(name)
    {
    }

    virtual ~Interface()
    {
    }

    const std::wstring& Name() const { return _name; }

    virtual void OnEnter()
    {
    }

    virtual void OnExit()
    {
    }

    virtual void Update()
    {
    }

    virtual void Draw()
    {
    }
};


class MainInterface : public Interface
{
private:
    Button* _pStartButton;
    Button* _pRulesButton;
    Button* _pExitButton;
    Button* _pIllustrateButton;

public:
    MainInterface();
    ~MainInterface() override;

    void OnEnter() override;
//    void OnExit() override;
    void Update() override;
    void Draw() override;

private:
    static void _OnClickStartButton();
    static void _OnClickRulesButton();
    static void _OnClickExitButton();
    static void _OnClickIllustrateButton();
};

class IllustrationInterface : public Interface
{
private:
    Button* _pWujiangButton;
    Button* _pKapaiButton;

public:
    IllustrationInterface();
    ~IllustrationInterface() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:
    static void _OnClickWujiangButton();
    static void _OnClickKapaiButton();
};

class RulesInterface : public Interface
{
public:
    RulesInterface();
    ~RulesInterface() override;

    void Update() override;
    void Draw() override;
};


class WujiangInterface : public Interface
{
private:
    Button* _pCaocaoButton;
    Button* _pSunquanButton;
    Button* _pSunshangxiangButton;
    Button* _pDiaochanButton;
    Button* _pLvbuButton;
    Button* _pZhenjiButton;
    Button* _pGuojiaButton;
    Button* _pXuchuButton;
    Button* _pZhangliaoButton;
    Button* _pXiahoudunButton;
    Button* _pSimayiButton;
    Button* _pLuxunButton;
    Button* _pDaqiaoButton;
    Button* _pZhouyuButton;
    Button* _pHuanggaiButton;
    Button* _pLvmengButton;
    Button* _pGanningButton;
    Button* _pHuangyueyingButton;
    Button* _pMachaoButton;
    Button* _pZhaoyunButton;
    Button* _pZhugeliangButton;
    Button* _pZhangfeiButton;
    Button* _pGuanyvButton;
    Button* _pLiubeiButton;

public:
    WujiangInterface();
    ~WujiangInterface() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:
    static void _OnClickCaocaoButton();
    static void _OnClickSunquanButton();
    static void _OnClickSunshangxiangButton();
    static void _OnClickDiaochanButton();
    static void _OnClickLvbuButton();
    static void _OnClickZhenjiButton();
    static void _OnClickGuojiaButton();
    static void _OnClickXuchuButton();
    static void _OnClickZhangliaoButton();
    static void _OnClickXiahoudunButton();
    static void _OnClickSimayiButton();
    static void _OnClickLuxunButton();
    static void _OnClickDaqiaoButton();
    static void _OnClickZhouyuButton();
    static void _OnClickHuanggaiButton();
    static void _OnClickLvmengButton();
    static void _OnClickGanningButton();
    static void _OnClickHuangyueyingButton();
    static void _OnClickMachaoButton();
    static void _OnClickZhaoyunButton();
    static void _OnClickZhugeliangButton();
    static void _OnClickZhangfeiButton();
    static void _OnClickGuanyvButton();
    static void _OnClickLiubeiButton();
};



class Caocao : public Interface
{
public:
    Caocao();
    ~Caocao() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};


class Sunquan : public Interface
{
public:
    Sunquan();
    ~Sunquan() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Sunshangxiang : public Interface
{
public:
    Sunshangxiang();
    ~Sunshangxiang() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Diaochan : public Interface
{
public:
    Diaochan();
    ~Diaochan() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Lvbu : public Interface
{
public:
    Lvbu();
    ~Lvbu() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Zhenji : public Interface
{
public:
    Zhenji();
    ~Zhenji() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Guojia : public Interface
{
public:
    Guojia();
    ~Guojia() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Xuchu : public Interface
{
public:
    Xuchu();
    ~Xuchu() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Zhangliao : public Interface
{
public:
    Zhangliao();
    ~Zhangliao() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Xiahoudun : public Interface
{
public:
    Xiahoudun();
    ~Xiahoudun() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Simayi : public Interface
{
public:
    Simayi();
    ~Simayi() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Luxun : public Interface
{
public:
    Luxun();
    ~Luxun() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Daqiao : public Interface
{
public:
    Daqiao();
    ~Daqiao() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Zhouyu : public Interface
{
public:
    Zhouyu();
    ~Zhouyu() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Huanggai : public Interface
{
public:
    Huanggai();
    ~Huanggai() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Lvmeng : public Interface
{
public:
    Lvmeng();
    ~Lvmeng() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Ganning : public Interface
{
public:
    Ganning();
    ~Ganning() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Huangyueying : public Interface
{
public:
    Huangyueying();
    ~Huangyueying() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Machao : public Interface
{
public:
    Machao();
    ~Machao() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Zhaoyun : public Interface
{
public:
    Zhaoyun();
    ~Zhaoyun() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Zhugeliang : public Interface
{
public:
    Zhugeliang();
    ~Zhugeliang() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Zhangfei : public Interface
{
public:
    Zhangfei();
    ~Zhangfei() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Guanyu : public Interface
{
public:
    Guanyu();
    ~Guanyu() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Liubei : public Interface
{
public:
    Liubei();
    ~Liubei() override;

    void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};


class KapaiInterface : public Interface
{
private:
    Button* _pShaButton;
    Button* _pShanButton;
    Button* _pTaoButton;
    Button* _pShunshouqianyangButton;
    Button* _pGuohechaiqiaoButton;
    Button* _pJuedouButton;
    Button* _pWuzhongshengyouButton;
    Button* _pWuxiekejiButton;
    Button* _pLebusishuButton;
    Button* _pBinglaingcunduanButton;
    Button* _pNanmanruqinButton;
    Button* _pWanjianqifaButton;
    Button* _pShuiyanqijunButton;
    Button* _pGuanshifuButton;
    Button* _pZhugeliannuButton;
    Button* _pHanbingjianButton;
    Button* _pZhangbashemaoButton;
    Button* _pQinggangjianButton;
    Button* _pBaguazhenButton;
    Button* _pRenwangdunButton;

public:
    KapaiInterface();
    ~KapaiInterface() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:
    static void _OnClickShaButton();
    static void _OnClickShanButton();
    static void _OnClickTaoButton();
    static void _OnClickShunshouqianyangButton();
    static void _OnClickGuohechaiqiaoButton();
    static void _OnClickJuedouButton();
    static void _OnClickWuzhongshengyouButton();
    static void _OnClickWuxiekejiButton();
    static void _OnClickLebusishuButton();
    static void _OnClickBinglaingcunduanButton();
    static void _OnClickNanmanruqinButton();
    static void _OnClickWanjianqifaButton();
    static void _OnClickShuiyanqijunButton();
    static void _OnClickGuanshifuButton();
    static void _OnClickZhugeliannuButton();
    static void _OnClickHanbingjianButton();
    static void _OnClickZhangbashemaoButton();
    static void _OnClickQinggangjianButton();
    static void _OnClickBaguazhenButton();
    static void _OnClickRenwangdunButton();
};

class Sha : public Interface
{
public:
    Sha();
    ~Sha() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Shan : public Interface
{
public:
    Shan();
    ~Shan() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Tao : public Interface
{
public:
    Tao();
    ~Tao() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Shunshouqianyang : public Interface
{
public:
    Shunshouqianyang();
    ~Shunshouqianyang() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Guohechaiqiao : public Interface
{
public:
    Guohechaiqiao();
    ~Guohechaiqiao() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Juedou : public Interface
{
public:
    Juedou();
    ~Juedou() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Wuzhongshengyou : public Interface
{
public:
    Wuzhongshengyou();
    ~Wuzhongshengyou() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Wuxiekeji : public Interface
{
public:
    Wuxiekeji();
    ~Wuxiekeji() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Lebusishu : public Interface
{
public:
    Lebusishu();
    ~Lebusishu() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Binglaingcunduan : public Interface
{
public:
    Binglaingcunduan();
    ~Binglaingcunduan() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Nanmanruqin : public Interface
{
public:
    Nanmanruqin();
    ~Nanmanruqin() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Wanjianqifa : public Interface
{
public:
    Wanjianqifa();
    ~Wanjianqifa() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Shuiyanqijun : public Interface
{
public:
    Shuiyanqijun();
    ~Shuiyanqijun() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Guanshifu : public Interface
{
public:
    Guanshifu();
    ~Guanshifu() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Zhugeliannu : public Interface
{
public:
    Zhugeliannu();
    ~Zhugeliannu() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Hanbingjian : public Interface
{
public:
    Hanbingjian();
    ~Hanbingjian() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Zhangbashemao : public Interface
{
public:
    Zhangbashemao();
    ~Zhangbashemao() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Qinggangjian : public Interface
{
public:
    Qinggangjian();
    ~Qinggangjian() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Baguazhen : public Interface
{
public:
    Baguazhen();
    ~Baguazhen() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Renwangdun : public Interface
{
public:
    Renwangdun();
    ~Renwangdun() override;

    //void OnEnter() override;
    //void OnExit() override;
    void Update() override;
    void Draw() override;

private:

};

class Bat;
class BatController;
class Ball;

class GameInterface : public Interface
{
private:
    //std::shared_ptr<Bat> _bats[2];
    //std::shared_ptr<BatController> _controllers[2];
    //std::shared_ptr<Ball> _ball;

    //int _scores[2];

    //int _turn;
    //bool _started;

public:
    GameInterface();
    ~GameInterface() override;


    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Draw() override;
};

#endif
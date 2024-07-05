#include<bits/stdc++.h>
using namespace std;
string s[24]={"Caocao","Sunquan","Sunshangxiang","Diaochan","Lvbu","Zhenji","Guojia","Xuchu",
	"Zhangliao","Xiahoudun","Simayi","Luxun","Daqiao","Zhouyu","Huanggai","Lvmeng",
	"Ganning","Huangyueying","Machao","Zhaoyun","Zhugeliang","Zhangfei","Guanyu","Liubei"};
string t[]={"Sha","Shan","Tao","Shunshouqianyang","Guohechaiqiao","Juedou","Wuzhongshengyou",
	"Wuxiekeji","Lebusishu","Binglaingcunduan","Nanmanruqin","Wanjianqifa","Shuiyanqijun",
	"Guanshifu","Zhugeliannu","Hanbingjian","Zhangbashemao","Qinggangjian","Baguazhen","Renwangdun"};
inline void NewButton(int y,int x,string s) {
	cout<<"_p"<<s<<"Button = new Button(Rect("<<x<<","<<y<<",120,80), L\""<<s<<"\");\n";
	cout<<"_p"<<s<<"Button"<<"->SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)\n";
        cout<<"	->SetOnClick(_OnClick"<<s<<"Button);\n";
}
int main() {
	sort(s,s+24);
	for(string x : s) {
		cout<<"extern FmodSound "<<x<<"1;\n";
	}
//	for(string x : s) {
//		cout<<"LoadFmodSound(&"<<x<<"1, \"res/music/die/"<<x<<".mp3\");\n";
//	}
	sort(t,t+20);
//	freopen("a.cpp","w",stdout);
//	for(auto x : t) 
//		cout<<"Button* _p"<<x<<"Button;"<<endl;
//	for(auto x : t) 
//		cout<<"static void _OnClick"<<x<<"Button();"<<endl;
//	for(auto x : t) {
//		cout<<"class "<<x<<" : public Interface"<<endl;
//		cout<<"{\n";
//		cout<<"public:\n";
//		cout<<"	"<<x<<"();\n";
//		cout<<"	~"<<x<<"() override;\n";
//		cout<<"\n	//void OnEnter() override;\n	//void OnExit() override;\n	void Update() override;\n	void Draw() override;\n";
//		cout<<"\nprivate:\n\n};\n\n";
//	}
//	for(auto x : s) {
//		printf("IMAGE Wujiang;\n");
//		cout<<"loadimage(&Wujiang, L\"res/"<<x<<".png\", 168, 216, 1);\n";
//		cout<<"PutAlphaImage(nullptr, 10, 10, &Wujiang);\n\n";
//	}
//	for(auto x : t) {
//		printf("IMAGE kapai;\n");
//		cout<<"loadimage(&kapai, L\"res/"<<x<<".png\", 115, 161, 1);\n";
//		cout<<"PutAlphaImage(nullptr, 10, 10, &kapai);\n\n";
//	} 
//	int cnt=1;
//	for(auto x : t) {
//		NewButton(150+(cnt-1)/6*100,(cnt-1)%6*160+40,x);
//		cnt++;
//	}
//	for(auto x : t) {
//		cout<<"_p"<<x<<"Button->Draw();\n";
//	} 
//	for(auto x : t) {
//		printf("#include \"../../../inc/ui/Interface.h\"\n");
//		printf("#include \"../../../inc/Message.h\"\n");
//		printf("#include \"../../../inc/Globals.h\"\n");
//		printf("#include \"../../../inc/ui/Application.h\"\n");
//		cout<<x<<"::"<<x<<"()\n	:Interface(L\""<<x<<"\")\n{\n\n}\n";
//		cout<<x<<"::~"<<x<<"()\n{\n\n}\n";
//		cout<<"void "<<x<<"::Update()\n{\n\n    if (IsKeyDown(VK_ESCAPE)) {\n		GetApplication()->ChangeInterface(L\"Wujiang\");\n}\n}\n";
//		cout<<"void "<<x;
//		puts("::Draw()\n{\n    RECT rect{ 0,0,1000,200 };\n"
//	    "LOGFONT style;\n"
//	    "gettextstyle(&style);\n"
//	    "settextstyle(100, 0, L\"Consolas\");\n"
//	    "drawtext(L\"杀\", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);\n"
//	    "settextstyle(&style);\n\n"
//	
//	    "RECT rect2{ 0,300,1000,200 };\n"
//	    "LOGFONT style2;\n"
//	    "gettextstyle(&style2);\n"
//	    "settextstyle(25, 0, L\"Consolas\");\n"
//	    "drawtext(L\"出牌阶段对其他角色使用，其需使用一张闪抵消你的杀，否则受到你对其造成的一点伤害。\", &rect2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);\n"
//	    "settextstyle(&style);\n"
//		"}\n");
//	}
//	for(auto x: t) {
//		cout<<"		->RegisterInterface(new "<<x<<"())\n";
//	}
//	for(auto x : t) {
//		cout<<"void KapaiInterface::_OnClick"<<x<<"Button() {\n";
//		cout<<"	Application* app=GetApplication();\n";
//		cout<<"	app->ChangeInterface(L\""<<x<<"\");\n";
//		cout<<"}\n\n";
//	}
	return 0;
} 

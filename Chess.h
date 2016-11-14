#pragma once


// CChess
#include "info.h"
class CChess 
{
public:
		void BackGo();               //悔棋
		void SetDc(CDC*,CDC*);       //设置绘图dc
		void NewGame(int);           //新游戏
		void ReDraw();               //重画函数
		bool DownZi(int nx,int ny,int type,HWND hwnd);//调用此函数下子
		CChess();
		virtual ~CChess();
			
private:
	void AiGo(int &,int&);             // 五子棋AI
	void DrawQz(int nx,int ny,int type=0);//画棋子
	void DrawQp();                        //画棋盘
	int PanYing(int nx,int ny);           //判断输赢
	int m_turn;                          //下棋次序
	int m_flag;                         //输赢标志，1白，2黑
	CDC *dc,*qp;
	char m_board[15][15];      //棋盘数组
	pos posinfo[255];          //下子信息数组，用于悔棋函数
	int posflag;              //下子信息数组下标
};



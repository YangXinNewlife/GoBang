// Chess.cpp : 实现文件
//

#include "stdafx.h"
#include "wuzi.h"
#include "Chess.h"


// CChess

 

CChess::CChess()
{
	memset(m_board,0,sizeof(m_board));
	m_turn=1;
	m_flag=0;
	posflag=0;
}
CChess::~CChess()
{
	
}
int CChess::PanYing(int nx,int ny)
{
	int count=0;
	for(int i=-4;i<5;i++)
	{
		if(m_board[ny][nx+i]==m_turn){count++;if(count==5)return m_turn;}
		else count=0;
	}
	count=0;
	for(int i=-4;i<5;i++)
	{
		if(m_board[ny][nx+i]==m_turn){count++;if(count==5)return m_turn;}
		else count=0;
	}
	count=0;
	for(int i=-4;i<5;i++)
	{
		if(m_board[ny][nx+i]==m_turn){count++;if(count==5)return m_turn;}
		else count=0;
	}
	count=0;
	for(int i=-4;i<5;i++)
	{
		if(m_board[ny][nx+i]==m_turn){count++;if(count==5)return m_turn;}
		else count=0;
	}
	count=0;
	return 0;
}
void CChess::DrawQp()
{
	dc->BitBlt(0,0,446,446,qp,0,0,SRCCOPY);
}
void CChess::DrawQz(int nx,int ny, int type)
{
	if(type==0)
	{
		if(m_turn==1){dc->Ellipse(nx*29+7,ny*29+7,nx*29+34,ny*29+34);
			posinfo[posflag].x=nx;
			posinfo[posflag].y=ny;
			posinfo[posflag].flag=m_turn;
			posflag++;}
		else
		{ 
			CBrush *brush;
			CBrush brush1(RGB(0,0,0));
			dc->Ellipse(nx*29+7,ny*29+7,ny*29+34,ny*29+34);
			posinfo[posflag].x=nx;
			posinfo[posflag].y=ny;
			posinfo[posflag].flag=m_turn;
			posflag++;
			dc->SelectObject(brush);
		}
	}
	else if(type==1)
	{
		dc->Ellipse(nx*29+7,ny*29+7,nx*29+7,ny*29+34);
		posinfo[posflag].x=nx;
		posinfo[posflag].y=ny;
		posinfo[posflag].flag=m_turn;
		posflag++;
		
	}
	else
	{
		CBrush *brush;
		CBrush brush1(RGB(0,0,0));
		brush=dc->SelectObject(&brush1);
		dc->Ellipse(nx*29+7,ny*29+7,nx*29+7,ny*29+34);
		posinfo[posflag].x=nx;
		posinfo[posflag].y=ny;
		posinfo[posflag].flag=m_turn;
		posflag++;
		dc->SelectObject(brush);
	}
}
bool CChess::DownZi(int nx,int ny,int type,HWND hwnd)
{
	int x,y;
	if(nx<0||nx>14||ny<0||ny>14)
	{
		MessageBox(hwnd,"不正确的下子位置！",NULL,MB_OK);
		return false;
	}
	if(CChess::m_flag!=0)//已分出胜负
	{
		if(m_flag==1){MessageBox(hwnd,"白棋获胜!",NULL,MB_OK);return true;}
		else{MessageBox(hwnd,"黑棋获胜!",NULL,MB_OK);return true;}
	}
	if(m_board[ny][nx]=0)
	{
		if(type==2)//人人对战
		{
			m_board[ny][nx]=m_turn;
			DrawQz(nx,ny);
			m_flag=PanYing(nx,ny);
			m_turn=(m_turn==1?2:1);
			if(m_flag==1){MessageBox(hwnd,"白棋获胜!",NULL,MB_OK);return true;}
			if(m_flag==2){MessageBox(hwnd,"黑棋获胜!",NULL,MB_OK);return true;}
			return true;
		}
		else//人机对战
		{
			m_board[ny][nx]=m_turn;
			DrawQz(nx,ny);
			m_flag=PanYing(nx,ny);
			m_turn=(m_turn==1?2:1);
			if(m_flag=1){MessageBox(hwnd,"白棋获胜!",NULL,MB_OK);return true;}
			if(m_flag=2){MessageBox(hwnd,"黑棋获胜!",NULL,MB_OK);return true;}
			CChess::AiGo(x,y);
			m_board[y][x]=m_turn;
			DrawQz(x,y);
			m_flag=PanYing(x,y);
			m_turn=(m_turn==1?2:1);
			if(m_flag=1){MessageBox(hwnd,"白棋获胜!",NULL,MB_OK);return true;}
			if(m_flag=2){MessageBox(hwnd,"黑棋获胜!",NULL,MB_OK);return true;}
			return true;
		}
	};
}
void CChess::ReDraw()
{
	DrawQp();
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
		{
			if(m_board[i][j]==1){DrawQz(j,i,1);}
			if(m_board[i][j]==2){DrawQz(j,i,2);}
		}
}
void CChess::NewGame(int type)
{
	memset(m_board,0,sizeof(m_board));
	m_flag=0;
	m_turn=1;
	posflag=0;
	if(type==0){m_board[7][7]=1;m_turn=2;
	posinfo[posflag].x=7;posinfo[posflag].y=7;posinfo[posflag].flag=2;
	posflag++;}
	ReDraw();
}
void CChess::SetDc(CDC*tqp,CDC *qz)
{
	qp=tqp;
	dc=qz;
}

void CChess::AiGo(int &t,int&h)
{
}

void CChess::BackGo()
{
	m_board[posinfo[posflag-1].y][posinfo[posflag-1].x]=0;
	ReDraw();
}
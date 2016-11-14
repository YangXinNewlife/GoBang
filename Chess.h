#pragma once


// CChess
#include "info.h"
class CChess 
{
public:
		void BackGo();               //����
		void SetDc(CDC*,CDC*);       //���û�ͼdc
		void NewGame(int);           //����Ϸ
		void ReDraw();               //�ػ�����
		bool DownZi(int nx,int ny,int type,HWND hwnd);//���ô˺�������
		CChess();
		virtual ~CChess();
			
private:
	void AiGo(int &,int&);             // ������AI
	void DrawQz(int nx,int ny,int type=0);//������
	void DrawQp();                        //������
	int PanYing(int nx,int ny);           //�ж���Ӯ
	int m_turn;                          //�������
	int m_flag;                         //��Ӯ��־��1�ף�2��
	CDC *dc,*qp;
	char m_board[15][15];      //��������
	pos posinfo[255];          //������Ϣ���飬���ڻ��庯��
	int posflag;              //������Ϣ�����±�
};



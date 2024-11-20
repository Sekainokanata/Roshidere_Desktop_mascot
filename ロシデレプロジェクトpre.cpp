#include <stdio.h>
#include "DxLib.h"
#include <iostream>
#include <stdlib.h>

void preInitialize(int *width,int *height)
{
	//ディスプレイ解像度の取得
	RECT rc;
	GetWindowRect(GetDesktopWindow(), &rc);
	*width = rc.right - rc.left;
	*height = rc.bottom - rc.top;
	//解像度，ウィンドウモード指定→pプロジェクトのDPI設定の変更が必要
	SetGraphMode(*width, *height, 32); // 解像度の設定
	ChangeWindowMode(TRUE); // ウィンドウモードに変更
	SetWindowStyleMode(2); // ウィンドウのスタイルを枠無しに指定
	SetUseBackBufferTransColorFlag(TRUE); // ウィンドウを透明にします
}

void afterInitialize() {
	HWND hWnd = GetMainWindowHandle();//操作先ウィンドウ
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetAlwaysRunFlag(TRUE);//ウィンドウがアクティブ状態でなくても実行する
	SetDrawScreen(DX_SCREEN_BACK);//描画対象を裏画面にする
}

void mainsystem(int width, int height)
{
	/*Live 2D viwerを用いれば行ける可能性大*/
	
	
	
	
	
	/*
	int Arisa_Meido = LoadGraph("アーリャメイド服.png");//データハンドル
	int Maria_Tenshi = LoadGraph("マーシャ天使.png");
	int Arisa_Seifuku = LoadGraph("アーリャ制服.png");
	int SELECT_GRAPH = Arisa_Meido;
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		DrawGraph(width - 250, height - 450, SELECT_GRAPH,TRUE);//width - 250, height - 450
		ScreenFlip();
		if (CheckHitKey(KEY_INPUT_1)) 
			SELECT_GRAPH = Arisa_Meido;
		if (CheckHitKey(KEY_INPUT_2)) 
			SELECT_GRAPH = Maria_Tenshi;
		if (CheckHitKey(KEY_INPUT_3))
			SELECT_GRAPH = Arisa_Seifuku;

		if (CheckHitKey(KEY_INPUT_Q)) {
			DeleteGraph(Arisa_Meido);// マスコットの画像データをメモリから解放します
			break;
		}
	}
	*/
}


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int width = NULL;
	int height = NULL;
	preInitialize(&width,&height);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
		return -1;			// エラーが起きたら直ちに終了
	afterInitialize();
	mainsystem(width, height);
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
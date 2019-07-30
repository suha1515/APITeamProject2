#pragma once

#ifndef __EXTERN_H__

// extern 키워드: 외부에 이러한 전역변수가 존재함을 알려주는 키워드.
extern HWND g_hWnd;
extern HDC  g_hDC;
// 더블 버퍼링
extern HDC		BackDC;
extern HBITMAP	g_hBitmap;
extern HBITMAP  g_hOldBit;

extern HINSTANCE hInst;

extern float g_fDeltaTime;
extern float g_fElapsedTime;
extern float g_fTimeScale;

extern const DWORD KEY_UP;
extern const DWORD KEY_DOWN;
extern const DWORD KEY_LEFT;
extern const DWORD KEY_RIGHT;


#define __EXTERN_H__
#endif

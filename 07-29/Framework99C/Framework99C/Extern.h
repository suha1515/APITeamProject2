#pragma once

#ifndef __EXTERN_H__

// extern Ű����: �ܺο� �̷��� ���������� �������� �˷��ִ� Ű����.
extern HWND g_hWnd;
extern HDC  g_hDC;
// ���� ���۸�
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

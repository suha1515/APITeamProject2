#pragma once

#ifndef __STRUCT_H__

typedef struct tagLineInfo
{
	float fStartX, fStartY;
	float fEndX, fEndY;
}LINE_INFO;

typedef struct tagInfo
{
	float fX = 0.f;
	float fY = 0.f;
	float fCX = 0.f;
	float fCY = 0.f;
}INFO;

typedef struct tagFloatPos
{
	float x;
	float y;
}POSf;

typedef struct tagIntPos
{
	int x;
	int y;
}POSi;

#define __STRUCT_H__
#endif

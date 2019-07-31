#pragma once

#ifndef __DEFINE_H__

#define PI 3.141592f
#define GRAVITY 10.f

#define WINCX 1000
#define WINCY 500
#define GROUND 410

#define NO_EVENT 0
#define DEAD_OBJ 1

#define OBSTACLE OBJECT_TYPE::OBJECT_OBSTACLE
#define NULL_CHECK(ptr)	\
if(nullptr == (ptr)) return;

#define NULL_CHECK_RETURN(ptr, val)	\
if(nullptr == (ptr)) return val;

#define BMP BitManager::GetInstance()
#define __DEFINE_H__
#endif

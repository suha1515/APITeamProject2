#pragma once

#ifndef __DEFINE_H__

#define PI 3.141592f
#define GRAVITY 9.8f


#define WINCX 1000
#define WINCY 500

#define NO_EVENT 0
#define DEAD_OBJ 1

//프레임과 프레임사이의 지난 시간
#define DELTA_TIME (g_fDeltaTime)
#define TOTAL_TIME (g_fTotalTime)

#define NULL_CHECK(ptr)	\
if(nullptr == (ptr)) return;

#define NULL_CHECK_RETURN(ptr, val)	\
if(nullptr == (ptr)) return val;



// 싱글톤 매크로
#define DECLARE_SINGLE_TONE(T) \
private:\
	T();\
	~T();\
	static T* m_pInstance;\
public:\
	static T* GetInstance();\
	static void DeleteInstance();


#define DEFINE_SINGLE_TONE(T) \
T* T::m_pInstance = nullptr;\
T::T()\
{}\
T::~T()\
{}\
T* T::GetInstance()\
{\
	if (!m_pInstance)\
	{\
		m_pInstance = new T;\
		m_pInstance->Initialize();\
	}\
	return m_pInstance;\
}\
void T::DeleteInstance()\
{\
	if (m_pInstance)\
	{\
		delete m_pInstance;\
		m_pInstance = nullptr;\
	}\
}



#define BMP BitManager::GetInstance()
#define __DEFINE_H__
#endif

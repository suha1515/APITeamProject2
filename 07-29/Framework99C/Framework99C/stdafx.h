// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

// Standard Headers
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>

using namespace std;

// User Headers
#include "Define.h"
#include "Typedef.h"
#include "Enum.h"
#include "Extern.h"
#include "Function.h"
#include "Struct.h"

// Manager Headers
#include "AbstractFactory.h"
#include "CollsionMgr.h"
#include "KeyMgr.h"
#include "ObjectMgr.h"
#include "ScrollMgr.h"
#include "BitManager.h"
#include "StageManager.h"


#pragma comment(linker,"/entry:wWinMainCRTStartup /subsystem:console")
//��ó: https://alleysark.tistory.com/36 [�ٸ���]
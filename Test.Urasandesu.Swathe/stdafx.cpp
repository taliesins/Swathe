// stdafx.cpp : �W���C���N���[�h Test.Urasandesu.Swathe.pch �݂̂�
// �܂ރ\�[�X �t�@�C���́A�v���R���p�C���ς݃w�b�_�[�ɂȂ�܂��B
// stdafx.obj �ɂ̓v���R���p�C���ς݌^��񂪊܂܂�܂��B

#include "stdafx.h"
#include <corhlpr.cpp>

// TODO: ���̃t�@�C���ł͂Ȃ��ASTDAFX.H �ŕK�v��
// �ǉ��w�b�_�[���Q�Ƃ��Ă��������B

struct OleCom 
{
    OleCom() 
    { 
#ifdef _DEBUG
        ::_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 
        //::_CrtSetBreakAlloc(4540);
#endif
        ::CoInitialize(NULL); 
    }
    ~OleCom() 
    { ::CoUninitialize(); }
} olecom;

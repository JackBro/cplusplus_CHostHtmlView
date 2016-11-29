//�����װAPI����SendInput�Ĳ��ֹ��ܣ�����ģ����������ַ���
//2013��2��2��23:49���

//����MFC����Ԥ�����ļ��Ĺ�����ʱ
//��SimulateInputString.cpp������#include "stdafx.h"
//����stdafx.h�����#include "SimulateInputString.h"
#pragma once
//ֻ������Windows 2000�����ϲ���ϵͳ
#ifndef _WIN32_WINNT		
#define _WIN32_WINNT 0x0501
#endif
//��Ҫ�õ�winAPI����
#include <Windows.h>
//�ַ���������stringģ��洢
#include <string>

class SendString 
{
public:
	//���캯��
	SendString();
	SendString(const WCHAR *wszText);
	SendString(const CHAR *szText);

	//�����ַ�������
	void SetString(const WCHAR *wszText);
	void SetString(const CHAR *szText);

	//׷���ַ�������
	void AddString(const WCHAR *wszText);
	void AddString(const CHAR *szText);

	//���������
	const SendString& operator = (const WCHAR *wszText);
	const SendString& operator = (const CHAR *szText);
	const SendString& operator += (const WCHAR *wszText);
	const SendString& operator += (const CHAR *szText);

	//ģ�������ַ�����nTimesΪ�ظ�ģ������Ĵ���
	INT Send(INT nTimes = 1);

protected:
	//�����ַ�������
	std::wstring m_strText;

	//CHAR���ַ���ת��Ϊwstring
	std::wstring szTOwstr(const CHAR *szText);

	//����������ͬ���ַ�����ȡ�ָ�����
	INPUT* Divide(UINT *nIput)const;

	//����û��������ͬ���ַ�����ȡ���ָ�����
	INPUT* NoDivede(UINT *nIput)const;
	//nIput���ڽ��շ���ֵ��Ϊ���ص�INPUT�ṹ����Ԫ�ظ���

	//����Ƿ���������ͬ���ַ�
	bool CheckString()const;

};
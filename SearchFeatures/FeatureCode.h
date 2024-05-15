#pragma once
#include <string>

//�ƻ����뼸�ֲ�ͬ������ģʽ��Ϊ�˷���������Զ�����һ����������������
class CFeatureCode
{
public:
	CFeatureCode(void);
	~CFeatureCode(void);
	

    //Sunday�㷨���� ���ϳ����� ��л����  ֮���Զ���һ��������Ϊ�������������ɨ���㷨������
    //2020.8.9������£��޸�ͨ�����СBUG����BUG���м��ͼ����������������޸�
    //2022.4.4������£����һ����룬�޸���ʼ��ַ��СBUG����BUG����С�����Ѳ�����Ҫ���ڴ�

    /*
    FindMatchingCode() ����˵����
    1) hProcess		Ҫ�򿪵Ľ��̾��
    2) markCode		������,֧��ͨ�����**������: 55 8b ec ** 56 83 ec 20 ** ** 08 d9 ee
    3) memBeginAddr		��ʼ������ַ
    4) memEndAddr		����������ַ
    5) retAddr[]		��¼�ҵ��ĵ�ַ,�����������ǰһ��Ҫ��0���� DWORD retAddr[32] = {0};  ���� DWORD *retAddr = new DWORD[32]();
    6) deviation		�������ַ��Ŀ���ַ��ƫ�ƾ��룬�ϸ�����
    7) isCall		�Ƿ�Ϊ��CALL����ת��ַ��true �� retAddr[] ���ص���CALL��ת�ĵ�ַ
    8) isAll		�Ƿ�������з��ϵĵ�ַ��false�ҵ���һ�����ϵĵ�ַ��ͽ���������true����������ֱ��������ַ���ڽ�����ַ��memEndAddr��
    return����ֵ		�ҵ��ĵ�ַ����
    �Ѳ����ڴ�����Ǳ�������û��ѡ��
    */
    DWORD FindMatchingCode(HANDLE hProcess, std::string markCode, DWORD memBeginAddr, DWORD memEndAddr, DWORD retAddr[], int deviation, bool isCall, bool isAll = false);
};


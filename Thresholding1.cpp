
// Thresholding1.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Thresholding1.h"
#include "Thresholding1Dlg.h"
#include <initguid.h>
#include "Thresholding1_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThresholding1App


class CThresholding1Module :
	public ATL::CAtlMfcModule
{
public:
	DECLARE_LIBID(LIBID_Thresholding1Lib);
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_THRESHOLDING1, "{993B1E6F-2EB9-486A-AB2D-1D2CF8AA4969}");};

CThresholding1Module _AtlModule;

BEGIN_MESSAGE_MAP(CThresholding1App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CThresholding1App ����

CThresholding1App::CThresholding1App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CThresholding1App ����

CThresholding1App theApp;


// CThresholding1App ��ʼ��

BOOL CThresholding1App::InitInstance()
{
	AfxOleInit();
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();
	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	#if !defined(_WIN32_WCE) || defined(_CE_DCOM)
	// ͨ�� CoRegisterClassObject() ע���๤����
	if (FAILED(_AtlModule.RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE)))
		return FALSE;
	#endif // !defined(_WIN32_WCE) || defined(_CE_DCOM)
	// Ӧ�ó������� /Embedding �� /Automation ���������ġ�
	// ��Ӧ�ó�����Ϊ�Զ������������С�
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// ����ʾ������
		return TRUE;
	}
	// Ӧ�ó������� /Unregserver �� /Unregister ���������ġ�
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		_AtlModule.UpdateRegistryAppId(FALSE);
		_AtlModule.UnregisterServer(TRUE);
		return FALSE;
	}
	// Ӧ�ó������� /Register �� /Regserver ���������ġ�
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
	{
		_AtlModule.UpdateRegistryAppId(TRUE);
		_AtlModule.RegisterServer(TRUE);
		return FALSE;
	}

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CThresholding1Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}



BOOL CThresholding1App::ExitInstance(void)
{
#if !defined(_WIN32_WCE) || defined(_CE_DCOM)
	_AtlModule.RevokeClassObjects();
#endif
	return CWinApp::ExitInstance();
}

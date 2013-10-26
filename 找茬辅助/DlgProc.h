//==========================================================================
#include <Windows.h>
#include <WindowsX.h>
#include <tchar.h>

#include "resource.h"
//==========================================================================
INT_PTR CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);	//�Ի���ص�����

void SetDlgIcon(HWND hDlg, UINT uID);	//���öԻ���ͼ��
BOOL OnInitDlg(HWND hDlg, HWND hwndFocus, LPARAM lParam);//��ʼ���Ի���, WM_INITDIALOG
void OnPaint(HWND hDlg);	//WM_PAINT
void OnCommand(HWND hDlg, int id, HWND hwndCtl, UINT codeNotify);	//WM_COMMAND
void OnHotKey(HWND hDlg, int idHotKey, UINT fuModifiers, UINT vk);	//WM_HOTKEY
void OnKeyDown(HWND hDlg, UINT vk, BOOL fDown, int cRepeat, UINT flags);		//WM_KEYDOWN
void OnTimer(HWND hDlg, UINT id);	//WM_TIMER
void OnLButtonDown(HWND hDlg, BOOL fDoubleClick, int x, int y, UINT keyFlags);	//WM_LBUTTONDOWN

inline HWND GetTargetWnd(){		return FindWindow(NULL, _T("������Ҳ�"));	}	//�Ҳ細�ھ��

BYTE * GetBmpBuffer(HWND hDlg, DWORD &dwSize, bool fLeft = true);	//ȡ���������ͼ�����ݲ�����
void Find(HWND hDlg);			//��ʼ�ȶ�
void AdjustPos(HWND hDlg);		//��������λ���ڵ�һ��ͼ����
//bool IsGamStarted();
int	GetRemainCount();			//��ȡ�Ҳ�ʣ�����������Զ�ˢ��

bool EnableDebugPrivilege();	//����SeDebugȨ��
bool IsVistaOrLater();			//�ж�ϵͳ��Vista����ǰ
////////////////////////////////////////////////////////////////////////////
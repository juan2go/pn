/**
 * @file optionspageextensions.cpp
 * @brief Options Dialog Clips Page for Programmer's Notepad 2
 * @author Simon Steele
 * @note Copyright (c) 2007 Simon Steele - http://untidy.net/
 *
 * Programmer's Notepad 2 : The license file (license.[txt|html]) describes 
 * the conditions under which this source may be modified / distributed.
 */
#include "stdafx.h"
#include "resource.h"
#include "optionspageextensions.h"
#include "extapp.h"
#include "extension.h"

#if defined (_DEBUG)
	#define new DEBUG_NEW
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

COptionsPageExtensions::COptionsPageExtensions()
{
}

void COptionsPageExtensions::OnOK()
{
}

void COptionsPageExtensions::OnInitialise()
{
	int count = 0;

	for(App::ExtensionList::iterator i = g_Context.ExtApp->GetExtensions().begin();
		i != g_Context.ExtApp->GetExtensions().end();
		++i)
	{
		PN::AString name;
		PN::AString version;
		
		if(!(*i)->GetDetails(name, version))
		{
			name = "Unknown";
			version = "Unknown";
		}
		
		int index = m_list.InsertItem(count++, name.Get());
		m_list.SetItemText(index, 1, version.Get());
		m_list.SetItemText(index, 2, "Yes");
	}
}

LPCTSTR COptionsPageExtensions::GetTreePosition()
{
	return _T("Extensions");
}

void COptionsPageExtensions::OnCancel()
{

}

LRESULT COptionsPageExtensions::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	m_list.Attach(GetDlgItem(IDC_EXTENSIONSLIST));
	m_list.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 140, 0);
	m_list.InsertColumn(1, _T("Version"), LVCFMT_LEFT, 80, 0);
	m_list.InsertColumn(2, _T("Enabled"), LVCFMT_LEFT, 80, 0);
	m_list.SetExtendedListViewStyle(LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	return 0;
}
#ifndef __BANKNOTERECOGNITIONFRMAPP_h__
#define __BANKNOTERECOGNITIONFRMAPP_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class BanknoteRecognitionFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif

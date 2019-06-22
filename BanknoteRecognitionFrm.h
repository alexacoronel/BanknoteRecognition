///-----------------------------------------------------------------
///
/// @file      BanknoteRecognitionFrm.h
/// @author    Alexa
/// Created:   12/02/2019 8:53:52 PM
/// @section   DESCRIPTION
///            BanknoteRecognitionFrm class declaration
///
///------------------------------------------------------------------

#ifndef __BANKNOTERECOGNITIONFRM_H__
#define __BANKNOTERECOGNITIONFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/statbmp.h>
////Header Include End
#include <iostream>
#include <string>
using namespace std;
////Dialog Style Start
#undef BanknoteRecognitionFrm_STYLE
#define BanknoteRecognitionFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class BanknoteRecognitionFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		BanknoteRecognitionFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Banknote Recognition"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = BanknoteRecognitionFrm_STYLE);
		virtual ~BanknoteRecognitionFrm();
		void WxBtnUploadClick(wxCommandEvent& event);
		void WxBtnIdentifyClick(wxCommandEvent& event);
		void WxBtnGrayscaleClick(wxCommandEvent& event);
		void WxBtnBinarizationClick(wxCommandEvent& event);
		void WxBtnThinClick(wxCommandEvent& event);
		void WxBtnCloseClick(wxCommandEvent& event);
		string ColorRecognition(int startX, int startY, int endX, int endY);
		string getEndPoints(wxImage img);		
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxResultTextColor;
		wxButton *WxBtnClose;
		wxButton *WxBtnThin;
		wxButton *WxBtnBinarization;
		wxButton *WxBtnGrayscale;
		wxStaticText *WxResultText;
		wxFileDialog *WxOpenImageDialog;
		wxStaticBox *WxStaticBox1;
		wxButton *WxBtnIdentify;
		wxStaticText *WxStaticText1;
		wxButton *WxBtnUpload;
		wxStaticBitmap *WxImageDisplay;
		////GUI Control Declaration End
		
		wxImage imageFile;
		wxImage scaledImage;
		wxImage grayImage;
		wxImage binaryImage;
		wxImage closedImage;
		wxImage thinnedImage;
		wxImage tempImage;
		wxImage endPointImage;
		
		static const int width = 500;
        static const int height = 200;
		int h;
		int w;
		
		int tolerance;
        int redTotal;
        int greenTotal;
        int blueTotal;
        int pixels;
        int billColorCount;
        int temp;

		int ** redVal;
        int ** greenVal;
        int ** blueVal;

		
		
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT3 = 1017,
			ID_WXSTATICTEXTLABEL = 1016,
			ID_WXRESULTTEXTCOLOR = 1013,
			ID_WXBTNCLOSE = 1011,
			ID_WXBTNTHIN = 1010,
			ID_WXBTNBINARIZATION = 1009,
			ID_WXBTNGRAYSCALE = 1008,
			ID_WXRESULTTEXT = 1007,
			ID_WXSTATICBOX1 = 1006,
			ID_WXBTNIDENTIFY = 1005,
			ID_WXSTATICTEXT1 = 1004,
			ID_WXBTNUPLOAD = 1003,
			ID_WXIMAGEDISPLAY = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif

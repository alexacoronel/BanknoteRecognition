///-----------------------------------------------------------------
///
/// @file      BanknoteRecognitionFrm.cpp
/// @author    Alexa
/// Created:   12/02/2019 8:53:52 PM
/// @section   DESCRIPTION
///            BanknoteRecognitionFrm class implementation
///
///------------------------------------------------------------------

#include "BanknoteRecognitionFrm.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// BanknoteRecognitionFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(BanknoteRecognitionFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(BanknoteRecognitionFrm::OnClose)
	EVT_BUTTON(ID_WXBTNCLOSE,BanknoteRecognitionFrm::WxBtnCloseClick)
	EVT_BUTTON(ID_WXBTNTHIN,BanknoteRecognitionFrm::WxBtnThinClick)
	EVT_BUTTON(ID_WXBTNBINARIZATION,BanknoteRecognitionFrm::WxBtnBinarizationClick)
	EVT_BUTTON(ID_WXBTNGRAYSCALE,BanknoteRecognitionFrm::WxBtnGrayscaleClick)
	EVT_BUTTON(ID_WXBTNIDENTIFY,BanknoteRecognitionFrm::WxBtnIdentifyClick)
	EVT_BUTTON(ID_WXBTNUPLOAD,BanknoteRecognitionFrm::WxBtnUploadClick)
END_EVENT_TABLE()
////Event Table End

BanknoteRecognitionFrm::BanknoteRecognitionFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize &size, long style)
    : wxFrame(parent, id, title, position, size, style)
{
    CreateGUIControls();
}

BanknoteRecognitionFrm::~BanknoteRecognitionFrm()
{
}

//Create GUI controls
void BanknoteRecognitionFrm::CreateGUIControls()
{
    //Do not add custom code between
    //GUI Items Creation Start and GUI Items Creation End
    //wxDev-C++ designer will remove them.
    //Add the custom code before or after the blocks
    ////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Color Agorithm:"), wxPoint(322, 447), wxDefaultSize, 0, _("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(18, wxSWISS, wxNORMAL, wxNORMAL, false, _("Arial Narrow")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXTLABEL, _("Pattern Recognition:"), wxPoint(58, 446), wxDefaultSize, 0, _("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(18, wxSWISS, wxNORMAL, wxNORMAL, false, _("Arial Narrow")));

	WxResultTextColor = new wxStaticText(this, ID_WXRESULTTEXTCOLOR, _("No Bill Detected"), wxPoint(322, 485), wxDefaultSize, 0, _("WxResultTextColor"));
	WxResultTextColor->SetFont(wxFont(18, wxSWISS, wxNORMAL, wxNORMAL, false, _("Arial Narrow")));

	WxBtnClose = new wxButton(this, ID_WXBTNCLOSE, _("Close"), wxPoint(321, 355), wxSize(86, 43), 0, wxDefaultValidator, _("WxBtnClose"));

	WxBtnThin = new wxButton(this, ID_WXBTNTHIN, _("Thinning"), wxPoint(406, 355), wxSize(107, 43), 0, wxDefaultValidator, _("WxBtnThin"));

	WxBtnBinarization = new wxButton(this, ID_WXBTNBINARIZATION, _("Binarization"), wxPoint(222, 352), wxSize(101, 43), 0, wxDefaultValidator, _("WxBtnBinarization"));

	WxBtnGrayscale = new wxButton(this, ID_WXBTNGRAYSCALE, _("Grayscale"), wxPoint(119, 350), wxSize(104, 44), 0, wxDefaultValidator, _("WxBtnGrayscale"));
	WxBtnGrayscale->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, _("Arial Narrow")));

	WxResultText = new wxStaticText(this, ID_WXRESULTTEXT, _("No Bill Detected"), wxPoint(61, 485), wxDefaultSize, 0, _("WxResultText"));
	WxResultText->SetFont(wxFont(18, wxSWISS, wxNORMAL, wxNORMAL, false, _("Arial Narrow")));

	WxOpenImageDialog =  new wxFileDialog(this, _("Choose an image file"), _(""), _(""), _("*.jpg;*.jpeg;*.png"), wxFD_OPEN);

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, _("Results"), wxPoint(30, 402), wxSize(577, 161));
	WxStaticBox1->SetForegroundColour(wxColour(_("WHITE")));
	WxStaticBox1->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false));

	WxBtnIdentify = new wxButton(this, ID_WXBTNIDENTIFY, _("Identify"), wxPoint(512, 355), wxSize(104, 44), 0, wxDefaultValidator, _("WxBtnIdentify"));
	WxBtnIdentify->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, _("Arial Narrow")));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("BANKNOTE RECOGNITION"), wxPoint(107, 34), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(27, wxSWISS, wxNORMAL, wxBOLD, false, _("Arial Narrow")));

	WxBtnUpload = new wxButton(this, ID_WXBTNUPLOAD, _("Upload"), wxPoint(13, 348), wxSize(104, 44), 0, wxDefaultValidator, _("WxBtnUpload"));
	WxBtnUpload->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, _("Arial Narrow")));

	WxImageDisplay = new wxStaticBitmap(this, ID_WXIMAGEDISPLAY, wxNullBitmap, wxPoint(27, 104), wxSize(590, 225) );
	WxImageDisplay->SetForegroundColour(wxColour(_("WHITE")));

	SetTitle(_("Banknote Recognition"));
	SetIcon(wxNullIcon);
	SetSize(8,8,659,675);
	Center();
	
    ////GUI Items Creation End
}

//Close Application
void BanknoteRecognitionFrm::OnClose(wxCloseEvent &event)
{
    Destroy();
}

string BanknoteRecognitionFrm::ColorRecognition(int startX, int startY, int endX, int endY)
{

    //Initialize RGB array
    redVal = new int *[w];
    greenVal = new int *[w];
    blueVal = new int *[w];

    for (int i = 0; i < w; i++)
    {
        redVal[i] = new int[h];
        greenVal[i] = new int[h];
        blueVal[i] = new int[h];
    }

    double colorCount[12] = {};

    //RGB Color of Bills
    int billRGBColors[6][3] = {
        //Orange
        {228, 153, 117},
        //red
        {224, 138, 130},
        //purple
        {151, 121, 155},
        //green
        {159, 196, 157},
        //yellow
        {185, 162, 115},
        //blue
        {149, 168, 192}};

    //Result labels
    string billResult[6] = {
        "20 Peso Bill",
        "50 Peso Bill",
        "100 Peso Bill",
        "200 Peso Bill",
        "500 Peso Bill",
        "1000 Peso Bill"};

    double counting[5] = {1, 0.5, 0.125, 0.0625, 0.0015625};

    //Loop through pixels
    for (int y = startY; y < endY; y++)
    {
        for (int x = startX; x < endX; x++)
        {

            //Get RGB values of each pixel and store in array
            redVal[x][y] = scaledImage.GetRed(x, y);
            greenVal[x][y] = scaledImage.GetGreen(x, y);
            blueVal[x][y] = scaledImage.GetBlue(x, y);

            //loop through billRGBColors/billResult arrays
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (j == 0)
                    {
                        tolerance = 0.5 * 16;
                    }
                    else
                    {
                        tolerance = 16 * j;
                    }
                    if ((redVal[x][y] <= billRGBColors[i][0] + tolerance) && (redVal[i][y] >= billRGBColors[i][0] - tolerance) &&
                        (greenVal[x][y] <= billRGBColors[i][1] + tolerance) && (greenVal[i][y] >= billRGBColors[i][1] - tolerance) &&
                        (blueVal[x][y] <= billRGBColors[i][2] + tolerance) && (blueVal[i][y] >= billRGBColors[i][2] - tolerance))
                    {
                        colorCount[i] += counting[j];
                    }
                }
            }
        }
    }

    //Check Clusters for dominant color
    for (int i = 0; i < 6; i++)
    {
        if (colorCount[i] > temp)
        {
            temp = colorCount[i];
            billColorCount = i;
        }
    }

    return (billResult[billColorCount]);
}

wxImage grayScale(wxImage img){
    for (int i = 410; i < img.GetWidth(); i++)
    {
        for (int j = 155; j < img.GetHeight(); j++)
        {
            unsigned char r = img.GetRed(i, j);
            unsigned char g = img.GetGreen(i, j);
            unsigned char b = img.GetBlue(i, j);
            unsigned char grayValue = r * 0.299 + g * 0.587 + b * 0.114;
            img.SetRGB(i, j, grayValue, grayValue, grayValue);
        }
    }
    return img;
}

// Binarization Technique taken from Fingerprint Verification System using Minutiae Extraction by Pua, Retona, Villegas. 
wxImage otsuBinarization(wxImage img)
{
    //Sets up the histogram of the input image
    double histogram[256] = {};
    unsigned char value;
    for (int i = 410; i < img.GetWidth(); i++)
    {
        for (int j = 155; j < img.GetHeight(); j++)
        {
            unsigned char value = img.GetRed(i, j);
            histogram[value] += 1;
        }
    }

    //gets the sum of the products of frequencies
    double sum = 0;
    for (int t = 0; t < 256; t++)
    {
        sum += t * histogram[t];
    }

    //holds the total sum of frequencies
    double totalFrequency = 0;
    for (int i = 0; i < 256; i++)
    {
        totalFrequency += histogram[i];
    }

    double sumB = 0;     //Sum of frequencies times possible threshold until the background
    double bgWeight = 0; //Background weight
    double fgWeight = 0; //Foreground weight

    double totalBg = 0; //Background total
    double totalFg = 0; //Foreground total

    double maxVar = 0;
    double threshold = 0;
    
    //Setting the threshold value based on the grayscale values present in the image
    for (int t = 0; t < 256; t++)
    {

        totalBg += histogram[t];
        if (totalBg == 0)
            continue;

        totalFg = totalFrequency - totalBg;
        if (totalFg == 0)
            break;

        sumB += t * histogram[t];

        double bgMean = sumB / totalBg;
        double fgMean = (sum - sumB) / totalFg;

        bgWeight = totalBg / totalFrequency;
        fgWeight = totalFg / totalFrequency;

        double bcVar = bgWeight * fgWeight * (bgMean - fgMean) * (bgMean - fgMean);

        if (bcVar > maxVar)
        {
            maxVar = bcVar;
            threshold = t;
        }
    }
    // Thresholding, setting pixels to either 1 or 0 based on the value of the threshold
    for (int i = 410; i < img.GetWidth(); i++)
    {
        for (int j = 155; j < img.GetHeight(); j++)
        {

            unsigned char value = img.GetRed(i, j);
            if (value > threshold)
            {
                img.SetRGB(i, j, 255, 255, 255);
            }
            else
            {
                img.SetRGB(i, j, 0, 0, 0);
            }
        }
    }
    
    return img;
}
/*
 * Start of Guo-Hall Thinning Algorithm
 * Taken from Fingerprint Verification System using Minutiae Extraction by Pua, Retona, Villegas. 
 */
int getBlackPixelCount(wxImage img)
{
    int count = 0;
    for (int i = 410; i < img.GetWidth(); i++)
    {
        for (int j = 155; j < img.GetHeight(); j++)
        {
            if (img.GetRed(i, j) == 0)
            {
                count += 1;
            }
        }
    }
    return count;
}

// Guo-Hall iteration through the neighboring pixels at the South-west region
wxImage thinSouthSide(wxImage img)
{
    wxImage temp = img;
    //   temp = img;
    //end copy

    for (int i = 410; i < img.GetWidth() - 1; i++)
    {
        for (int j = 155; j < img.GetHeight() - 1; j++)
        {
            if (img.GetRed(i, j) == 0)
            {
                // get 8 neighbors

                int point[8] = {};

                point[0] = (int)img.GetRed(i - 1, j - 1);
                point[1] = (int)img.GetRed(i - 1, j);
                point[2] = (int)img.GetRed(i - 1, j + 1);
                point[3] = (int)img.GetRed(i, j + 1);
                point[4] = (int)img.GetRed(i + 1, j + 1);
                point[5] = (int)img.GetRed(i + 1, j);
                point[6] = (int)img.GetRed(i + 1, j - 1);
                point[7] = (int)img.GetRed(i, j - 1);

                for (int k = 0; k < 8; k++)
                {
                    if (point[k] == 0)
                    {
                        point[k] = 1;
                    }
                    else
                    {
                        point[k] = 0;
                    }
                }
                // calculate C(p)
                int C = int(~point[1] & (point[2] | point[3])) +
                        int(~point[3] & (point[4] | point[5])) +
                        int(~point[5] & (point[6] | point[7])) +
                        int(~point[7] & (point[0] | point[1]));
                if (C == 1)
                {
                    // calculate N
                    int N1 = int(point[0] | point[1]) +
                             int(point[2] | point[3]) +
                             int(point[4] | point[5]) +
                             int(point[6] | point[7]);
                    int N2 = int(point[1] | point[2]) +
                             int(point[3] | point[4]) +
                             int(point[5] | point[6]) +
                             int(point[7] | point[0]);
                    int N = std::min(N1, N2);
                    if ((N == 2) || (N == 3))
                    {
                        int E = (point[5] | point[6] | ~point[0]) & point[7];
                        if (E == 0)
                        {
                            temp.SetRGB(i, j, 255, 255, 255);
                        }
                    }
                }
            }
        }
    }
    return temp;
}

// Guo-Hall iteration through the neighboring pixels at the north-east region
wxImage thinNorthSide(wxImage img)
{
    wxImage temp;
    temp = img;

    for (int i = 410; i < img.GetWidth() - 1; i++)
    {
        for (int j = 155; j < img.GetHeight() - 1; j++)
        {
            if (img.GetRed(i, j) == 0)
            {
                // get 8 neighbors
                int point[8] = {};

                point[0] = (int)img.GetRed(i - 1, j - 1);
                point[1] = (int)img.GetRed(i - 1, j);
                point[2] = (int)img.GetRed(i - 1, j + 1);
                point[3] = (int)img.GetRed(i, j + 1);
                point[4] = (int)img.GetRed(i + 1, j + 1);
                point[5] = (int)img.GetRed(i + 1, j);
                point[6] = (int)img.GetRed(i + 1, j - 1);
                point[7] = (int)img.GetRed(i, j - 1);

                for (int k = 0; k < 8; k++)
                {
                    if (point[k] == 0)
                    {
                        point[k] = 1;
                    }
                    else
                    {
                        point[k] = 0;
                    }
                }
                // calculate C(p)
                int C = int(~point[1] & (point[2] | point[3])) +
                        int(~point[3] & (point[4] | point[5])) +
                        int(~point[5] & (point[6] | point[7])) +
                        int(~point[7] & (point[0] | point[1]));
                if (C == 1)
                {
                    // calculate N
                    int N1 = int(point[0] | point[1]) +
                             int(point[2] | point[3]) +
                             int(point[4] | point[5]) +
                             int(point[6] | point[7]);
                    int N2 = int(point[1] | point[2]) +
                             int(point[3] | point[4]) +
                             int(point[5] | point[6]) +
                             int(point[7] | point[0]);
                    int N = std::min(N1, N2);
                    if ((N == 2) || (N == 3))
                    {
                        int E = (point[1] | point[2] | ~point[4]) & point[3];
                        if (E == 0)
                        {
                            temp.SetRGB(i, j, 255, 255, 255);
                        }
                    }
                }
            }
        }
    }
    return temp;
}

wxImage thinImg(wxImage img)
{
    int count1 = getBlackPixelCount(img);
    int count2 = 0;
    img = thinSouthSide(img);
    while (count1 != count2)
    {
        img = thinSouthSide(img);
        count2 = getBlackPixelCount(img);
        img = thinNorthSide(img);
        count1 = getBlackPixelCount(img);
    }
    return img;
}

// Code inspired by Morphological Close Function from project Facial Detection by Sison & Lim
wxImage morphClose(wxImage image, wxImage output) // Image Closing Function
{
    int inWidth = image.GetWidth();
    int inHeight = image.GetHeight();
    int count;
    output.wxImage::Create(inWidth, inHeight);
    
    for (int i = 0; i < inWidth; i++)
    {
        for (int j = 0; j < inHeight; j++)
        {
            int r = image.GetRed(i, j);
            int g = image.GetGreen(i, j);
            int b = image.GetBlue(i, j);
            output.SetRGB(i, j, r, g, b);
            
        }
    }
    for (int i = 410; i < inWidth; i++)
    {
        for (int j = 155; j < inHeight; j++){
            output.SetRGB(i, j, 0, 0, 0);
        }
    }


    for (int i = 410; i < inWidth; i++)
    {
        for (int j = 155; j < inHeight; j++)
        {
            int r = image.GetRed(i, j);
            if (r == 0) //checks if the pixel is black
            {
                int count = 0;
                for (int hor = -1; hor <= 1; hor++) //loop for horizontal
                {
                    for (int ver = -1; ver <= 1; ver++) //loop for vertical
                    {
                        if (image.GetRed(i + hor, j + ver) != 0)
                        {
                            count++;
                        }
                    }
                }

                if (count < 2)
                {
                    output.SetRGB(i, j, 255, 255, 255);
                }
                else
                    output.SetRGB(i, j, 0, 0, 0);
            }

            if (output.GetRed(i, j) == 0)
            {
                output.SetRGB(i, j, 255, 255, 255);
            }
            else
                output.SetRGB(i, j, 0, 0, 0);
        }
    }
    return output;
}

string BanknoteRecognitionFrm::getEndPoints(wxImage img)
{
    ofstream myfile;
    wxImage temp;
    temp = img;
    vector<int> xCoordinates, yCoordinates;
    int count, endPointCount, startX = 410, startY = 155;

    for (int i = startX; i < img.GetWidth() - 1; i++)
    {
        for (int j = startY; j < img.GetHeight() - 1; j++)
        {
            count = 0;
            if (img.GetRed(i, j) == 0)
            {
                // get neighboring pixels
                for (int hor = -3; hor <= 3; hor++) //loop for horizontal
                {
                    for (int ver = -3; ver <= 3; ver++) //loop for vertical
                    {
                     //   v_temp = img.GetRed(i + hor, j + ver);
                        if (img.GetRed(i + hor, j + ver) == 0)
                        {
                            count++;
                        }
                    }
                }
                
                if (count == 4)
                { // if the pixel is an endpoint
                    endPointCount++;
                    //save its coordinates
                    xCoordinates.push_back(i);
                    yCoordinates.push_back(j);
                    img.SetRGB(i, j, 0, 90, 255);
                }
                else if (count < 3){img.SetRGB(i, j, 255, 255, 255);}
                    
            } //end of if i,j is ==0
        }     // loop through height
    }         // loop through whole image is done
    endPointImage = img;
    float slope;

    bool pix = false;
    bool check = false;
    int digitCount = 0;

    for (int i = startX; i < img.GetWidth()-1; i++)
    {
        for (int j = startY; j < img.GetHeight()-1; j++)
        {
            if (img.GetRed(i, j) == 0)
            {
                pix = true;
                break;
            }
            else
            {
                pix = false;
            }
        }

        if (check && (pix != check))
            digitCount++;

        check = pix;
    }
    
    //get slope of line connecting the endpoints
    if(xCoordinates.size() == 2){
    slope = (yCoordinates.at(0) - yCoordinates.at(1)) / (xCoordinates.at(0) - xCoordinates.at(1));
    }
    else{
        slope = (yCoordinates.at(0) - yCoordinates.at(2)) / (xCoordinates.at(0) - xCoordinates.at(2));
    }
    
    myfile.open("log.txt", ios::out | ios::app);
    for (int i = 0; i < xCoordinates.size(); i++)
    {
        myfile << "x-coordinate: " << xCoordinates.at(i) << endl
               << "y-coordinate: " << yCoordinates.at(i) << endl;
    }
    myfile << "Slope: " << slope << endl
           << "Number of Digits: " << digitCount << endl;
    myfile.close();
    //    }

    if (slope > 3)
    { // if slope is negative
        //number is 1 and not 2
        if (digitCount == 3)
        {
            return "100 Peso bill";
        }
        else
        {
            return "1000 Peso bill";
        }
    }

    else if (slope < 4&& slope > 0 && endPointCount >= 2)
    { // 3 end points detected
        //number is 2
        if (digitCount == 3)
        {
            return "200 Peso bill";
        }
        else
        {
            return "20 Peso bill";
        }
    }

    else if (slope < 0) // slope is negative so the number is 5
    {
        if (digitCount == 3)
        {
            return "500 Peso bill";
        }
        else
        {
            return "50 Peso bill";
        }
    }
    else
    {
        return "Bill unidentifiable";
    }

} //end function

/*
 * Start of Button Click Event Handlers
 */

//Upload Image Button Click
void BanknoteRecognitionFrm::WxBtnUploadClick(wxCommandEvent &event)
{
    WxOpenImageDialog->ShowModal();
    if (WxOpenImageDialog->GetPath().IsEmpty())
    {
        return;
    }

    imageFile.LoadFile(WxOpenImageDialog->GetPath(), wxBITMAP_TYPE_ANY);

    //get height and width of image
    h = imageFile.GetHeight();
    w = imageFile.GetWidth();

    //Scale image if dimensions are not equal to widthxheight
    if (w != width && h != height)
    {
        scaledImage = imageFile.Scale(width, height);
        WxImageDisplay->SetBitmap(scaledImage);
    }
    else
    {
        WxImageDisplay->SetBitmap(imageFile);
    }
}

//Identify Image Button Click
void BanknoteRecognitionFrm::WxBtnIdentifyClick(wxCommandEvent &event)
{
    //Perform all
    
    grayImage = grayScale(scaledImage);
    binaryImage = otsuBinarization(grayImage);
    closedImage = morphClose(binaryImage, tempImage);
    thinnedImage = thinImg(closedImage);
    //Print results to GUI
    WxResultText->SetLabel(getEndPoints(thinnedImage));
    WxResultTextColor->SetLabel(ColorRecognition(0, 0, 125, scaledImage.GetHeight()));
    WxImageDisplay->SetBitmap(endPointImage);
}

/*
 * WxBtnGrayscaleClick
 */
void BanknoteRecognitionFrm::WxBtnGrayscaleClick(wxCommandEvent &event)
{
    grayImage = grayScale(scaledImage);
    WxImageDisplay->SetBitmap(grayImage);
}

/*
 * Binarization button blick
 */
void BanknoteRecognitionFrm::WxBtnBinarizationClick(wxCommandEvent &event)
{
    binaryImage = otsuBinarization(grayImage);
    WxImageDisplay->SetBitmap(binaryImage);
}

void BanknoteRecognitionFrm::WxBtnCloseClick(wxCommandEvent &event)
{
    closedImage = morphClose(binaryImage, tempImage);
    WxImageDisplay->SetBitmap(closedImage);
}

void BanknoteRecognitionFrm::WxBtnThinClick(wxCommandEvent &event)
{
    thinnedImage = thinImg(closedImage);
    WxImageDisplay->SetBitmap(thinnedImage);
}


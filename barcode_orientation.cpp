///////////////////////////////////////////////////////////////////////////////
// File generated by HDevelop for HALCON/C++ Version 18.05.0.1
///////////////////////////////////////////////////////////////////////////////



#ifndef __APPLE__
#  include "HalconCpp.h"
#  include "HDevThread.h"
#  if defined(__linux__) && !defined(__arm__) && !defined(NO_EXPORT_APP_MAIN)
#    include <X11/Xlib.h>
#  endif
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#    include <HALCONCpp/HDevThread.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#    include <HALCONCppxl/HDevThread.h>
#  endif
#  include <stdio.h>
#  include <HALCON/HpThread.h>
#  include <CoreFoundation/CFRunLoop.h>
#endif



using namespace HalconCpp;

// Procedure declarations 
// External procedures 
// Chapter: Graphics / Text
// Short Description: This procedure displays 'Click 'Run' to continue' in the lower right corner of the screen. 
void disp_continue_message (HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box);
// Chapter: Graphics / Text
// Short Description: This procedure writes a text message. 
void disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem, 
    HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box);
// Chapter: XLD / Creation
// Short Description: Creates an arrow shaped XLD contour. 
void gen_arrow_contour_xld (HObject *ho_Arrow, HTuple hv_Row1, HTuple hv_Column1, 
    HTuple hv_Row2, HTuple hv_Column2, HTuple hv_HeadLength, HTuple hv_HeadWidth);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
void set_display_font (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold, 
    HTuple hv_Slant);

// Procedures 
// External procedures 
// Chapter: Graphics / Text
// Short Description: This procedure displays 'Click 'Run' to continue' in the lower right corner of the screen. 
void disp_continue_message (HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_GenParamName, hv_GenParamValue, hv_ContinueMessage;

  //This procedure displays 'Press Run (F5) to continue' in the
  //lower right corner of the screen.
  //It uses the procedure disp_message.
  //
  //Input parameters:
  //WindowHandle: The window, where the text shall be displayed
  //Color: defines the text color.
  //   If set to '' or 'auto', the currently set color is used.
  //Box: If set to 'true', the text is displayed in a box.
  //
  //Convert the parameter Box to generic parameters.
  hv_GenParamName = HTuple();
  hv_GenParamValue = HTuple();
  if (0 != ((hv_Box.TupleLength())>0))
  {
    if (0 != (HTuple(hv_Box[0])==HTuple("false")))
    {
      //Display no box
      hv_GenParamName = hv_GenParamName.TupleConcat("box");
      hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
    }
    else if (0 != (HTuple(hv_Box[0])!=HTuple("true")))
    {
      //Set a color other than the default.
      hv_GenParamName = hv_GenParamName.TupleConcat("box_color");
      hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[0]));
    }
  }
  if (0 != ((hv_Box.TupleLength())>1))
  {
    if (0 != (HTuple(hv_Box[1])==HTuple("false")))
    {
      //Display no shadow.
      hv_GenParamName = hv_GenParamName.TupleConcat("shadow");
      hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
    }
    else if (0 != (HTuple(hv_Box[1])!=HTuple("true")))
    {
      //Set a shadow color other than the default.
      hv_GenParamName = hv_GenParamName.TupleConcat("shadow_color");
      hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[1]));
    }
  }
  //
  if (0 != (hv_Color==HTuple("")))
  {
    //disp_text does not accept an empty string for Color.
    hv_Color = HTuple();
  }
  //
  //Display the message.
  hv_ContinueMessage = "Press Run (F5) to continue";
  DispText(hv_WindowHandle, hv_ContinueMessage, "window", "bottom", "right", hv_Color, 
      hv_GenParamName, hv_GenParamValue);
  return;
}

// Chapter: Graphics / Text
// Short Description: This procedure writes a text message. 
void disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem, 
    HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_GenParamName, hv_GenParamValue;

  //This procedure displays text in a graphics window.
  //
  //Input parameters:
  //WindowHandle: The WindowHandle of the graphics window, where
  //   the message should be displayed
  //String: A tuple of strings containing the text message to be displayed
  //CoordSystem: If set to 'window', the text position is given
  //   with respect to the window coordinate system.
  //   If set to 'image', image coordinates are used.
  //   (This may be useful in zoomed images.)
  //Row: The row coordinate of the desired text position
  //   A tuple of values is allowed to display text at different
  //   positions.
  //Column: The column coordinate of the desired text position
  //   A tuple of values is allowed to display text at different
  //   positions.
  //Color: defines the color of the text as string.
  //   If set to [], '' or 'auto' the currently set color is used.
  //   If a tuple of strings is passed, the colors are used cyclically...
  //   - if |Row| == |Column| == 1: for each new textline
  //   = else for each text position.
  //Box: If Box[0] is set to 'true', the text is written within an orange box.
  //     If set to' false', no box is displayed.
  //     If set to a color string (e.g. 'white', '#FF00CC', etc.),
  //       the text is written in a box of that color.
  //     An optional second value for Box (Box[1]) controls if a shadow is displayed:
  //       'true' -> display a shadow in a default color
  //       'false' -> display no shadow
  //       otherwise -> use given string as color string for the shadow color
  //
  //It is possible to display multiple text strings in a single call.
  //In this case, some restrictions apply:
  //- Multiple text positions can be defined by specifying a tuple
  //  with multiple Row and/or Column coordinates, i.e.:
  //  - |Row| == n, |Column| == n
  //  - |Row| == n, |Column| == 1
  //  - |Row| == 1, |Column| == n
  //- If |Row| == |Column| == 1,
  //  each element of String is display in a new textline.
  //- If multiple positions or specified, the number of Strings
  //  must match the number of positions, i.e.:
  //  - Either |String| == n (each string is displayed at the
  //                          corresponding position),
  //  - or     |String| == 1 (The string is displayed n times).
  //
  //
  //Convert the parameters for disp_text.
  if (0 != (HTuple(hv_Row==HTuple()).TupleOr(hv_Column==HTuple())))
  {
    return;
  }
  if (0 != (hv_Row==-1))
  {
    hv_Row = 12;
  }
  if (0 != (hv_Column==-1))
  {
    hv_Column = 12;
  }
  //
  //Convert the parameter Box to generic parameters.
  hv_GenParamName = HTuple();
  hv_GenParamValue = HTuple();
  if (0 != ((hv_Box.TupleLength())>0))
  {
    if (0 != (HTuple(hv_Box[0])==HTuple("false")))
    {
      //Display no box
      hv_GenParamName = hv_GenParamName.TupleConcat("box");
      hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
    }
    else if (0 != (HTuple(hv_Box[0])!=HTuple("true")))
    {
      //Set a color other than the default.
      hv_GenParamName = hv_GenParamName.TupleConcat("box_color");
      hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[0]));
    }
  }
  if (0 != ((hv_Box.TupleLength())>1))
  {
    if (0 != (HTuple(hv_Box[1])==HTuple("false")))
    {
      //Display no shadow.
      hv_GenParamName = hv_GenParamName.TupleConcat("shadow");
      hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
    }
    else if (0 != (HTuple(hv_Box[1])!=HTuple("true")))
    {
      //Set a shadow color other than the default.
      hv_GenParamName = hv_GenParamName.TupleConcat("shadow_color");
      hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[1]));
    }
  }
  //Restore default CoordSystem behavior.
  if (0 != (hv_CoordSystem!=HTuple("window")))
  {
    hv_CoordSystem = "image";
  }
  //
  if (0 != (hv_Color==HTuple("")))
  {
    //disp_text does not accept an empty string for Color.
    hv_Color = HTuple();
  }
  //
  DispText(hv_WindowHandle, hv_String, hv_CoordSystem, hv_Row, hv_Column, hv_Color, 
      hv_GenParamName, hv_GenParamValue);
  return;
}

// Chapter: XLD / Creation
// Short Description: Creates an arrow shaped XLD contour. 
void gen_arrow_contour_xld (HObject *ho_Arrow, HTuple hv_Row1, HTuple hv_Column1, 
    HTuple hv_Row2, HTuple hv_Column2, HTuple hv_HeadLength, HTuple hv_HeadWidth)
{

  // Local iconic variables
  HObject  ho_TempArrow;

  // Local control variables
  HTuple  hv_Length, hv_ZeroLengthIndices, hv_DR;
  HTuple  hv_DC, hv_HalfHeadWidth, hv_RowP1, hv_ColP1, hv_RowP2;
  HTuple  hv_ColP2, hv_Index;

  //This procedure generates arrow shaped XLD contours,
  //pointing from (Row1, Column1) to (Row2, Column2).
  //If starting and end point are identical, a contour consisting
  //of a single point is returned.
  //
  //input parameteres:
  //Row1, Column1: Coordinates of the arrows' starting points
  //Row2, Column2: Coordinates of the arrows' end points
  //HeadLength, HeadWidth: Size of the arrow heads in pixels
  //
  //output parameter:
  //Arrow: The resulting XLD contour
  //
  //The input tuples Row1, Column1, Row2, and Column2 have to be of
  //the same length.
  //HeadLength and HeadWidth either have to be of the same length as
  //Row1, Column1, Row2, and Column2 or have to be a single element.
  //If one of the above restrictions is violated, an error will occur.
  //
  //
  //Init
  GenEmptyObj(&(*ho_Arrow));
  //
  //Calculate the arrow length
  DistancePp(hv_Row1, hv_Column1, hv_Row2, hv_Column2, &hv_Length);
  //
  //Mark arrows with identical start and end point
  //(set Length to -1 to avoid division-by-zero exception)
  hv_ZeroLengthIndices = hv_Length.TupleFind(0);
  if (0 != (hv_ZeroLengthIndices!=-1))
  {
    hv_Length[hv_ZeroLengthIndices] = -1;
  }
  //
  //Calculate auxiliary variables.
  hv_DR = (1.0*(hv_Row2-hv_Row1))/hv_Length;
  hv_DC = (1.0*(hv_Column2-hv_Column1))/hv_Length;
  hv_HalfHeadWidth = hv_HeadWidth/2.0;
  //
  //Calculate end points of the arrow head.
  hv_RowP1 = (hv_Row1+((hv_Length-hv_HeadLength)*hv_DR))+(hv_HalfHeadWidth*hv_DC);
  hv_ColP1 = (hv_Column1+((hv_Length-hv_HeadLength)*hv_DC))-(hv_HalfHeadWidth*hv_DR);
  hv_RowP2 = (hv_Row1+((hv_Length-hv_HeadLength)*hv_DR))-(hv_HalfHeadWidth*hv_DC);
  hv_ColP2 = (hv_Column1+((hv_Length-hv_HeadLength)*hv_DC))+(hv_HalfHeadWidth*hv_DR);
  //
  //Finally create output XLD contour for each input point pair
  {
  HTuple end_val45 = (hv_Length.TupleLength())-1;
  HTuple step_val45 = 1;
  for (hv_Index=0; hv_Index.Continue(end_val45, step_val45); hv_Index += step_val45)
  {
    if (0 != (HTuple(hv_Length[hv_Index])==-1))
    {
      //Create_ single points for arrows with identical start and end point
      GenContourPolygonXld(&ho_TempArrow, HTuple(hv_Row1[hv_Index]), HTuple(hv_Column1[hv_Index]));
    }
    else
    {
      //Create arrow contour
      GenContourPolygonXld(&ho_TempArrow, ((((HTuple(hv_Row1[hv_Index]).TupleConcat(HTuple(hv_Row2[hv_Index]))).TupleConcat(HTuple(hv_RowP1[hv_Index]))).TupleConcat(HTuple(hv_Row2[hv_Index]))).TupleConcat(HTuple(hv_RowP2[hv_Index]))).TupleConcat(HTuple(hv_Row2[hv_Index])), 
          ((((HTuple(hv_Column1[hv_Index]).TupleConcat(HTuple(hv_Column2[hv_Index]))).TupleConcat(HTuple(hv_ColP1[hv_Index]))).TupleConcat(HTuple(hv_Column2[hv_Index]))).TupleConcat(HTuple(hv_ColP2[hv_Index]))).TupleConcat(HTuple(hv_Column2[hv_Index])));
    }
    ConcatObj((*ho_Arrow), ho_TempArrow, &(*ho_Arrow));
  }
  }
  return;
}

// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
void set_display_font (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold, 
    HTuple hv_Slant)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_OS, hv_Fonts, hv_Style, hv_Exception;
  HTuple  hv_AvailableFonts, hv_Fdx, hv_Indices;

  //This procedure sets the text font of the current window with
  //the specified attributes.
  //
  //Input parameters:
  //WindowHandle: The graphics window for which the font will be set
  //Size: The font size. If Size=-1, the default of 16 is used.
  //Bold: If set to 'true', a bold font is used
  //Slant: If set to 'true', a slanted font is used
  //
  GetSystem("operating_system", &hv_OS);
  if (0 != (HTuple(hv_Size==HTuple()).TupleOr(hv_Size==-1)))
  {
    hv_Size = 16;
  }
  if (0 != ((hv_OS.TupleSubstr(0,2))==HTuple("Win")))
  {
    //Restore previous behaviour
    hv_Size = (1.13677*hv_Size).TupleInt();
  }
  else
  {
    hv_Size = hv_Size.TupleInt();
  }
  if (0 != (hv_Font==HTuple("Courier")))
  {
    hv_Fonts.Clear();
    hv_Fonts[0] = "Courier";
    hv_Fonts[1] = "Courier 10 Pitch";
    hv_Fonts[2] = "Courier New";
    hv_Fonts[3] = "CourierNew";
    hv_Fonts[4] = "Liberation Mono";
  }
  else if (0 != (hv_Font==HTuple("mono")))
  {
    hv_Fonts.Clear();
    hv_Fonts[0] = "Consolas";
    hv_Fonts[1] = "Menlo";
    hv_Fonts[2] = "Courier";
    hv_Fonts[3] = "Courier 10 Pitch";
    hv_Fonts[4] = "FreeMono";
    hv_Fonts[5] = "Liberation Mono";
  }
  else if (0 != (hv_Font==HTuple("sans")))
  {
    hv_Fonts.Clear();
    hv_Fonts[0] = "Luxi Sans";
    hv_Fonts[1] = "DejaVu Sans";
    hv_Fonts[2] = "FreeSans";
    hv_Fonts[3] = "Arial";
    hv_Fonts[4] = "Liberation Sans";
  }
  else if (0 != (hv_Font==HTuple("serif")))
  {
    hv_Fonts.Clear();
    hv_Fonts[0] = "Times New Roman";
    hv_Fonts[1] = "Luxi Serif";
    hv_Fonts[2] = "DejaVu Serif";
    hv_Fonts[3] = "FreeSerif";
    hv_Fonts[4] = "Utopia";
    hv_Fonts[5] = "Liberation Serif";
  }
  else
  {
    hv_Fonts = hv_Font;
  }
  hv_Style = "";
  if (0 != (hv_Bold==HTuple("true")))
  {
    hv_Style += HTuple("Bold");
  }
  else if (0 != (hv_Bold!=HTuple("false")))
  {
    hv_Exception = "Wrong value of control parameter Bold";
    throw HException(hv_Exception);
  }
  if (0 != (hv_Slant==HTuple("true")))
  {
    hv_Style += HTuple("Italic");
  }
  else if (0 != (hv_Slant!=HTuple("false")))
  {
    hv_Exception = "Wrong value of control parameter Slant";
    throw HException(hv_Exception);
  }
  if (0 != (hv_Style==HTuple("")))
  {
    hv_Style = "Normal";
  }
  QueryFont(hv_WindowHandle, &hv_AvailableFonts);
  hv_Font = "";
  {
  HTuple end_val48 = (hv_Fonts.TupleLength())-1;
  HTuple step_val48 = 1;
  for (hv_Fdx=0; hv_Fdx.Continue(end_val48, step_val48); hv_Fdx += step_val48)
  {
    hv_Indices = hv_AvailableFonts.TupleFind(HTuple(hv_Fonts[hv_Fdx]));
    if (0 != ((hv_Indices.TupleLength())>0))
    {
      if (0 != (HTuple(hv_Indices[0])>=0))
      {
        hv_Font = HTuple(hv_Fonts[hv_Fdx]);
        break;
      }
    }
  }
  }
  if (0 != (hv_Font==HTuple("")))
  {
    throw HException("Wrong value of control parameter Font");
  }
  hv_Font = (((hv_Font+"-")+hv_Style)+"-")+hv_Size;
  SetFont(hv_WindowHandle, hv_Font);
  return;
}

#ifndef NO_EXPORT_MAIN
// Main procedure 
void action()
{

  // Local iconic variables
  HObject  ho_Image, ho_ImageRotate, ho_SymbolRegions;
  HObject  ho_Arrow;

  // Local control variables
  HTuple  hv_Width, hv_Height, hv_WindowHandle;
  HTuple  hv_BarCodeHandle, hv_Rot, hv_DecodedDataStrings;
  HTuple  hv_Orientation, hv_Area, hv_Row, hv_Col;

  //
  //Orientation with reading direction of a bar code
  //
  ReadImage(&ho_Image, "barcode/ean13/ean1305");
  GetImageSize(ho_Image, &hv_Width, &hv_Height);
  if (HDevWindowStack::IsOpen())
    CloseWindow(HDevWindowStack::Pop());
  SetWindowAttr("background_color","black");
  OpenWindow(0,0,hv_Width,hv_Height,0,"visible","",&hv_WindowHandle);
  HDevWindowStack::Push(hv_WindowHandle);
  if (HDevWindowStack::IsOpen())
    DispObj(ho_Image, HDevWindowStack::GetActive());
  if (HDevWindowStack::IsOpen())
    SetColor(HDevWindowStack::GetActive(),"green");
  if (HDevWindowStack::IsOpen())
    SetDraw(HDevWindowStack::GetActive(),"margin");
  if (HDevWindowStack::IsOpen())
    SetLineWidth(HDevWindowStack::GetActive(),3);
  set_display_font(hv_WindowHandle, 14, "mono", "true", "false");
  //
  CreateBarCodeModel("element_size_min", 1.5, &hv_BarCodeHandle);
  for (hv_Rot=0; hv_Rot<=360; hv_Rot+=30)
  {
    RotateImage(ho_Image, &ho_ImageRotate, hv_Rot, "weighted");
    if (HDevWindowStack::IsOpen())
      DispObj(ho_ImageRotate, HDevWindowStack::GetActive());
    GetImageSize(ho_ImageRotate, &hv_Width, &hv_Height);
    if (HDevWindowStack::IsOpen())
      SetWindowExtents(HDevWindowStack::GetActive(),0, 0, hv_Width, hv_Height);
    FindBarCode(ho_ImageRotate, &ho_SymbolRegions, hv_BarCodeHandle, "EAN-13", &hv_DecodedDataStrings);
    if (HDevWindowStack::IsOpen())
      DispObj(ho_SymbolRegions, HDevWindowStack::GetActive());
    GetBarCodeResult(hv_BarCodeHandle, "all", "orientation", &hv_Orientation);
    AreaCenter(ho_SymbolRegions, &hv_Area, &hv_Row, &hv_Col);
    gen_arrow_contour_xld(&ho_Arrow, hv_Row+(((hv_Orientation.TupleRad()).TupleSin())*70), 
        hv_Col-(((hv_Orientation.TupleRad()).TupleCos())*70), hv_Row-(((hv_Orientation.TupleRad()).TupleSin())*70), 
        hv_Col+(((hv_Orientation.TupleRad()).TupleCos())*70), 25, 25);
    if (HDevWindowStack::IsOpen())
      DispObj(ho_Arrow, HDevWindowStack::GetActive());
    disp_message(hv_WindowHandle, hv_DecodedDataStrings, "window", 12, 12, "black", 
        "true");
    if (0 != (hv_Rot<360))
    {
      disp_continue_message(hv_WindowHandle, "black", "true");
      // stop(...); only in hdevelop
    }
  }
}


#ifndef NO_EXPORT_APP_MAIN

#ifdef __APPLE__
// On OS X systems, we must have a CFRunLoop running on the main thread in
// order for the HALCON graphics operators to work correctly, and run the
// action function in a separate thread. A CFRunLoopTimer is used to make sure
// the action function is not called before the CFRunLoop is running.
// Note that starting with macOS 10.12, the run loop may be stopped when a
// window is closed, so we need to put the call to CFRunLoopRun() into a loop
// of its own.
HTuple      gStartMutex;
H_pthread_t gActionThread;
HBOOL       gTerminate = FALSE;

static void timer_callback(CFRunLoopTimerRef timer, void *info)
{
  UnlockMutex(gStartMutex);
}

static Herror apple_action(void **parameters)
{
  // Wait until the timer has fired to start processing.
  LockMutex(gStartMutex);
  UnlockMutex(gStartMutex);

  try
  {
    action();
  }
  catch (HException &exception)
  {
    fprintf(stderr,"  Error #%u in %s: %s\n", exception.ErrorCode(),
            (const char *)exception.ProcName(),
            (const char *)exception.ErrorMessage());
  }

  // Tell the main thread to terminate itself.
  LockMutex(gStartMutex);
  gTerminate = TRUE;
  UnlockMutex(gStartMutex);
  CFRunLoopStop(CFRunLoopGetMain());
  return H_MSG_OK;
}

static int apple_main(int argc, char *argv[])
{
  Herror                error;
  CFRunLoopTimerRef     Timer;
  CFRunLoopTimerContext TimerContext = { 0, 0, 0, 0, 0 };

  CreateMutex("type","sleep",&gStartMutex);
  LockMutex(gStartMutex);

  error = HpThreadHandleAlloc(&gActionThread);
  if (H_MSG_OK != error)
  {
    fprintf(stderr,"HpThreadHandleAlloc failed: %d\n", error);
    exit(1);
  }

  error = HpThreadCreate(gActionThread,0,apple_action);
  if (H_MSG_OK != error)
  {
    fprintf(stderr,"HpThreadCreate failed: %d\n", error);
    exit(1);
  }

  Timer = CFRunLoopTimerCreate(kCFAllocatorDefault,
                               CFAbsoluteTimeGetCurrent(),0,0,0,
                               timer_callback,&TimerContext);
  if (!Timer)
  {
    fprintf(stderr,"CFRunLoopTimerCreate failed\n");
    exit(1);
  }
  CFRunLoopAddTimer(CFRunLoopGetCurrent(),Timer,kCFRunLoopCommonModes);

  for (;;)
  {
    HBOOL terminate;

    CFRunLoopRun();

    LockMutex(gStartMutex);
    terminate = gTerminate;
    UnlockMutex(gStartMutex);

    if (terminate)
      break;
  }

  CFRunLoopRemoveTimer(CFRunLoopGetCurrent(),Timer,kCFRunLoopCommonModes);
  CFRelease(Timer);

  error = HpThreadHandleFree(gActionThread);
  if (H_MSG_OK != error)
  {
    fprintf(stderr,"HpThreadHandleFree failed: %d\n", error);
    exit(1);
  }

  ClearMutex(gStartMutex);
  return 0;
}
#endif

int main(int argc, char *argv[])
{
  int ret = 0;

  try
  {
#if defined(_WIN32)
    SetSystem("use_window_thread", "true");
#elif defined(__linux__) && !defined(__arm__)
    XInitThreads();
#endif

    // Default settings used in HDevelop (can be omitted) 
    SetSystem("width", 512);
    SetSystem("height", 512);

#ifndef __APPLE__
    action();
#else
    ret = apple_main(argc,argv);
#endif
  }
  catch (HException &exception)
  {
    fprintf(stderr,"  Error #%u in %s: %s\n", exception.ErrorCode(),
            (const char *)exception.ProcName(),
            (const char *)exception.ErrorMessage());
    ret = 1;
  }
  return ret;
}

#endif


#endif



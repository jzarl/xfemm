/*
   This code is a modified version of an algorithm
   forming part of the software program Finite
   Element Method Magnetics (FEMM), authored by
   David Meeker. The original software code is
   subject to the Aladdin Free Public Licence
   version 8, November 18, 1999. For more information
   on FEMM see www.femm.info. This modified version
   is not endorsed in any way by the original
   authors of FEMM.

   This software has been modified to use the C++
   standard template libraries and remove all Microsoft (TM)
   MFC dependent code to allow easier reuse across
   multiple operating system platforms.

   Date Modified: 2017 - 01 - 14
   By:  Emoke Szelitzky
        Tibor Szelitzky
        Richard Crozier
        Johannes Zarl-Zierl
   Contact:
        szelitzkye@gmail.com
        sztibi82@yahoo.com
        richard.crozier@yahoo.co.uk
        johannes@zarl-zierl.at

 Contributions by Johannes Zarl-Zierl were funded by Linz Center of
 Mechatronics GmbH (LCM)
*/
#include "CCommonPoint.h"

#include <utility>   //std::swap
using std::swap;

// CCommonPoint construction
femm::CCommonPoint::CCommonPoint()
	: x(0),y(0),t(0)
{
}

void femm::CCommonPoint::sortXY()
{
    if(x>y)
    {
        swap(x,y);
    }
}

void femm::CCommonPoint::setSortedValues(int v1, int v2)
{
    if (v1<v2)
    {
        x = v1;
        y = v2;
    } else {
        x = v2;
        y = v1;
    }
}

std::unique_ptr<femm::CCommonPoint> femm::CCommonPoint::clone() const
{
    return std::unique_ptr<femm::CCommonPoint>(new femm::CCommonPoint(*this));
}

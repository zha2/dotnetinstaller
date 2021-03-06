#include "StdAfx.h"
#include "WidgetPosition.h"

WidgetPosition::WidgetPosition()
: _left(0)
, _top(0)
, _width(0)
, _height(0)
{
}

WidgetPosition::WidgetPosition(const std::wstring& s)
: _left(0)
, _top(0)
, _width(0)
, _height(0)
{
    FromString(s);
}

WidgetPosition::WidgetPosition(const WidgetPosition& rhs)
{
    operator=(rhs);
}

WidgetPosition& WidgetPosition::operator =(const WidgetPosition& rhs)
{
    _left = rhs._left;
    _top = rhs._top;
    _width = rhs._width;
    _height = rhs._height;
    return * this;
}

bool WidgetPosition::FromString(const std::wstring& p_RectString)
{
    if (p_RectString.empty())
        return false;

    std::vector<std::wstring> l_RectCoordinates = DVLib::split(p_RectString, L",", 4);
    if (l_RectCoordinates.size() != 4) 
        return false;

    _left = _wtoi(l_RectCoordinates[0].c_str());
    _top = _wtoi(l_RectCoordinates[1].c_str());
    _width = _wtoi(l_RectCoordinates[2].c_str());
    _height = _wtoi(l_RectCoordinates[3].c_str());
    return true;
}

std::wstring WidgetPosition::ToString() const
{
    std::wstringstream ss;
    ss << L"left=" << _left << L", top=" << _top << L", width=" << _width << L", height=" << _height;
    return ss.str();
}

CRect WidgetPosition::ToRect() const 
{ 
    POINT p = { Left(), Top() };
    SIZE s = { Width(), Height() };
    return CRect(p, s);
}

void WidgetPosition::FromRect(const RECT& rect)
{
    CRect cr(rect);
    _left = cr.left;
    _top = cr.top;
    _height = cr.Height();
    _width = cr.Width();
}

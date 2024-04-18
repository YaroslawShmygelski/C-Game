#include "gameapi.h"

//----------------------------------------------------------------------
GameApi::GameApi() : Game()
{ }
//----------------------------------------------------------------------
void GameApi::View()
{
//   InvalidateRect(_hwnd, NULL, true);
   for(int i=0; i<row; i++) {
      for(int j=0; j<col; j++) {
         if(arr[i][j]) (HBRUSH)::SelectObject( _hdc, _BgBrush );
         else (HBRUSH)::SelectObject( _hdc, _MyBrush );

         Rectangle( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
//        Ellipse( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
      }
   }
}
//void GameApi::View()
//{
//   for(int i=0; i<nw; i++) {
//      for(int j=0; j<nk; j++) {
//         if(T[i][j])
//            Rectangle( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
//         else
//            Ellipse( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
//      }
//   }
//}
//----------------------------------------------------------------------
void GameApi::InitApi(HWND hwnd)
{
//   _hwnd = hwnd;
   _hdc = GetDC( hwnd );
   _MyBrush = ::CreateSolidBrush(0x00fff000);  // RGB(255,0,0)
   _BgBrush = ::CreateSolidBrush(0x00000fff);
}
//----------------------------------------------------------------------
GameApi::~GameApi()
{
   ::DeleteObject( _MyBrush );
   ::DeleteObject( _BgBrush );
}
//======================================================================

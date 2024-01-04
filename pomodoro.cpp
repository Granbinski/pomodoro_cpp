#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
 int focusTimeMin, breakTimeMin;

 cout << "Entre com o tempo de foco (minutos): ";
 cin >> focusTimeMin;

 cout << "Entre com o tempo de pausa (minutos): ";
 cin >> breakTimeMin;

 while (true)
 {
  int focusTimeSec = focusTimeMin * 60;
  auto start = chrono::high_resolution_clock::now();

  while (focusTimeSec > 0)
  {
   auto current = chrono::high_resolution_clock::now();
   chrono::duration<double, milli> elapsed = current - start;

   focusTimeSec--;
   int elapsedSec = elapsed.count() / 1000;

   int min = focusTimeSec / 60;
   int sec = focusTimeSec % 60;

   cout << min << ":" << sec << "." << elapsedSec % 1000 << "   \r";
   this_thread::sleep_for(chrono::milliseconds(100));
  }

  int breakTimeSec = breakTimeMin * 60;

  cout << "\nIniciando pausa...\n";

  start = chrono::high_resolution_clock::now();
  while (breakTimeSec > 0)
  {
   auto current = chrono::high_resolution_clock::now();
   chrono::duration<double, milli> elapsed = current - start;

   breakTimeSec--;
   int elapsedSec = elapsed.count() / 1000;

   int min = breakTimeSec / 60;
   int sec = breakTimeSec % 60;

   cout << min << ":" << sec << "." << elapsedSec % 1000 << "   \r";
   this_thread::sleep_for(chrono::milliseconds(100));
  }

  cout << "\nFoco novamente!\n";
 }

 return 0;
}
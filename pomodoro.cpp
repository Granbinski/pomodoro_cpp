#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void countdown(int &timeMin)
{
 int timeSec = timeMin * 60;
 auto start = chrono::high_resolution_clock::now();

 while (timeSec > 0)
 {
  auto current = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsed = current - start;

  timeSec--;
  int elapsedSec = elapsed.count() / 1000;

  int min = timeSec / 60;
  int sec = timeSec % 60;

  cout << min << ":" << sec << "." << elapsedSec % 1000 << "   \r";

  // Ajuste o valor abaixo para aumentar ou diminuir a velocidade
  this_thread::sleep_for(chrono::milliseconds(500)); // Delay de 500 milissegundos (0.5 segundos)
 }
}

int main()
{
 int focusTimeMin, breakTimeMin;

 cout << "Entre com o tempo de foco (minutos): ";
 cin >> focusTimeMin;

 cout << "Entre com o tempo de pausa (minutos): ";
 cin >> breakTimeMin;

 while (true)
 {
  cout << "\nFoco iniciado!" << endl;
  countdown(focusTimeMin);

  cout << "\nIniciando pausa...\n";
  countdown(breakTimeMin);

  cout << "\nFoco novamente!\n";
 }

 return 0;
}

#include <pch.h>
#include <omp.h>
#include <iostream>
#include <ctime>


using namespace std;

int contarpalabras(char[]);

int main()
{
	unsigned t0, t1;
	t0 = clock();

	char cadena[300];
	cout << "Ingresar el texto:";
	cin.getline(cadena, 300);
	cout << "El texto ingreso contiene: " << contarpalabras(cadena)<< "palabras" << endl;

	t1 = clock();
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "tiempo de ejecucion: " << time << endl;

	return 0;

}
// (isalpha) sirve para ver si la letra es seguido de un espacio y para que el contador no la cuente
int contarpalabras(char tex[])
{


	int palabras = 0;
	for (int i = 1; tex[i] != '\0'; ++i)
		if (tex[i - 1] == ' '&&isalpha(tex[i]))++palabras;


	if (isalpha(tex[0])) ++palabras;
	return palabras;

	int tid;
	int nth;

	#pragma omp parallel private(tid)
	{
		nth = omp_get_num_threads();
		tid = omp_get_thread_num();

		#pragma omp critical
		{
			cout << "Hilo" << tid << "de " << nth << endl;
		}

		#pragma omp for schedule(static)
		for (int i = 0; i < 15; ++i)
			cout << "hola" << endl;

	}
	return 0;

}

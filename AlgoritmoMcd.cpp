#include <iostream>
#include <iomanip>

using namespace std;

 const int COLS = 5;
 const int ROWS = 100; //Como máximo

 struct tTabla {
	 int matriz[ROWS][COLS];
	 int N;
 };

int mcd(int a, int b, int &inversoMultiplicativo,tTabla& tabla) {

	int r,i=1,j=0;

	do{
		tabla.matriz[i][0] = i;
		tabla.matriz[i][2] = a/b;

		r = a % b;
		a = b;
		b = r;

		i++;
		if (r != 0) {
			tabla.matriz[i][3] = tabla.matriz[i - 2][3] - tabla.matriz[i - 1][2] * tabla.matriz[i - 1][3];
			tabla.matriz[i][4] = tabla.matriz[i - 2][4] - tabla.matriz[i - 1][2] * tabla.matriz[i - 1][4];
		}
		tabla.matriz[i][1] = r;

	}while (r != 0 && i<ROWS);

	if (a == 1) inversoMultiplicativo = tabla.matriz[i - 1][4];
	else inversoMultiplicativo = -1;

	tabla.N = i+1;
	tabla.matriz[i][0] = i;

	return a;
}
void leerDatos(int &a,int &b) {
	int aux;
	cout << "\nIntroduzca a: "; cin >> a;
	cout << "Introduzca b: "; cin >> b;

	if (a < b) {
		aux = a;
		a = b;
		b = aux;
	}

}
void printTabla(tTabla tabla) {

	cout <<setw(10)<< "i"<< setw(10) << "ri"<< setw(10) << "qi" << setw(10) << "alfai" << setw(10) << "betai" << endl;
	for (int i = 0; i < tabla.N; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << setw(10) << tabla.matriz[i][j];
		}
		cout << "\n";
	}
}
void printInversoMultiplicativo(int a, int b, int inverso) {

	cout << "\n\nEl inverso multiplicativo de " << b;
	if (inverso != -1)cout << " es  [" << b << "]^-1  = [" << inverso << "]";
	else cout << " no existe";
	cout << " en mod " << a << endl;

}
void inicializarTabla(tTabla &tabla,int a,int b) {


	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			tabla.matriz[i][j] = 0;
		}
	}
	tabla.N = ROWS;
	tabla.matriz[0][1] = a;//r0
	tabla.matriz[1][1] = b;//r1
	tabla.matriz[0][3] = 1;//ALFA
	tabla.matriz[1][4] = 1;//beta
}
int main()
{
	
	tTabla tabla;
	int a, b, inversoMultiplicativo;

	cout << "\nALGORITMO DE EUCLIDES AVANZADO\n";
	leerDatos(a, b);
	inicializarTabla(tabla, a, b);
	cout << "\nEL m.c.d ("<<a<<"," <<b <<") =  " << mcd(a,b, inversoMultiplicativo,tabla) <<endl << endl;
	printTabla(tabla);
	printInversoMultiplicativo( a,  b, inversoMultiplicativo);

	

	return 0;

}
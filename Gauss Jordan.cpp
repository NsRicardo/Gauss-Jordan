// C++ Implementation for Gauss-Jordan
// Elimination Method
#include <bits/stdc++.h>
using namespace std;

#define M 10

// Funcao para imprimir a matriz
void PrintMatrix(float a[][M], int n)
{
 for (int i = 0; i < n; i++)
 {
		for (int j = 0; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
 }
}

// funcao para deixar matriz na froma reduzida
// formulário de escalão de linha.
int ExecutarOperacoes(float a[][M], int n)
{
 int i, j, k = 0, c, flag = 0, m = 0;
 float pro = 0;

 // Executando operacoes elementares
 for (i = 0; i < n; i++)
 {
		if (a[i][i] == 0)
		{
			c = 1;
			while (a[i + c][i] == 0 && (i + c) < n)
				c++;
			if ((i + c) == n)
			{
				flag = 1;
				break;
			}
			for (j = i, k = 0; k <= n; k++)
				swap(a[j][k], a[j + c][k]);
		}

		for (j = 0; j < n; j++)
		{

			// Excluindo todos i == j
			if (i != j)
			{

				// Convertendo matriz para forma reduzida
				// forma escalonada(matriz diagonal)
				float pro = a[j][i] / a[i][i];

				for (k = 0; k <= n; k++)
					a[j][k] = a[j][k] - (a[i][k]) * pro;
			}
		}
 }
 return flag;
}

// Função para imprimir o resultado desejado
// se existirem soluções exclusivas, caso contrário
// imprime nenhuma solução ou infinitas soluções
// dependendo da entrada fornecida.
void PrintResultado(float a[][M], int n, int flag)
{
 cout << "Assim o resultado e : ";

 if (flag == 2)
		cout << "Existem soluções infinitas" << endl;
 else if (flag == 3)
		cout << "Nao existe nenhuma solucao" << endl;

 // Imprimindo a solução dividindo constantes por
 // seus respectivos elementos diagonais
 else
 {
		for (int i = 0; i < n; i++)
			cout << a[i][n] / a[i][i] << " ";
 }
}

// Para verificar se infinitas soluções
// existe ou não existe solução
int VerificarConsistencia(float a[][M], int n, int flag)
{
 int i, j;
 float soma;

 // flag == 2 para solucoes infinitas
 // flag == 3 para nenhuma solucao
 flag = 3;
 for (i = 0; i < n; i++)
 {
		soma = 0;
		for (j = 0; j < n; j++)
			soma = soma + a[i][j];
		if (soma == a[i][j])
			flag = 2;
 }
 return flag;
}
//==================================================//
// Codigo Principal
int main()
{
 float a[M][M] = {{1, 3, 2, 5, 11},
																		{-1, 2, -2, 5, -6},
																		{2, 6, 4, 7, 19},
																		{0, 5, 2, 6, 5}};

 // Ordem da Matriz (n)
 int n = 4, flag = 0;

 // Realizando a transformacao da Matriz
 flag = ExecutarOperacoes(a, n);

 if (flag == 1)
		flag = VerificarConsistencia(a, n, flag);

 // Imprimindo a matriz final
 cout << "Matriz aumentada final é : " << endl;
 PrintMatrix(a, n);
 cout << endl;

 // Imprime solucoes(se existir)
 PrintResultado(a, n, flag);

 return 0;
}

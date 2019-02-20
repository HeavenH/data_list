#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main (){
	using namespace std;
	
	float vH, hT, sB, sL, desc, inss;
	
	cout << "Digite o valor da hora de aula: " << endl; scanf("%f", &vH);
	
	cout << "Numero de horas trabalhadas no mes " << endl; scanf("%f", &hT);
	
	cout << "Desconto INSS: " << endl; scanf("%f", &inss);
	
	sB = hT * vH;
	
	desc = sB * (inss / 100);
	
	sL = sB - desc;
	
	printf("\nSalario Bruto:   - R$:%2.f Reais\n",sB);
	printf("Salario Liquido: - R$:%2.f Reais\n", sL);
	printf("Desconto:        - R$:%2.f Reais\n", desc);
	
	return 0;

}

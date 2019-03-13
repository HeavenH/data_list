#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct question {
	void (*next)(struct question*);
};

void question_10(struct question *question) {

}

void question_9(struct question *question) {
	question->next = question_10;
}

void question_8(struct question *question) {
	
	float salario, bolsa;
	
	printf("\nQuestão 8\n");
	
	printf("Digite seu salário: ");
	scanf("%f", &salario);
	
	if(salario <= 500 ) {
		salario = salario + 0.05;
		printf("Seu salario com bonificação é: %f", salario);
	} else if ( salario >= 500 && salario <= 1200 ) {
		salario = salario + 0.12;
		salario = salario + (salario + 0.12);
		printf("Seu salario com bonificação é: %f", salario);
	} else {
		printf("sem bonificação :(");
	}
	
	question->next = question_9;
}

void question_7(struct question *question) {
	question->next = question_8;
}

void question_6(struct question *question) {
	question->next = question_7;
}

void question_5(struct question *question) {
	question->next = question_6;
}

void question_4(struct question *question) {
	question->next = question_5;
}

void question_3(struct question *question) {
	question->next = question_4;
}

void question_2(struct question *question) {
	
	float anoNascimento, anoAtual, idade;

	anoAtual = 2019;
	
	printf("\nQuestão 2\n");
	
	printf("Digite seu ano de nascimento: ");
	scanf("%f", &anoNascimento);
	
	idade = anoAtual - anoNascimento;
	
	if (idade <= 18) {
		printf("Vocé é jovem\n");
	} else if (idade >= 19 && idade <= 59) {
		printf("Vocé é adulta\n");
	} else {
		printf("Vocé é idosa\n");
	}
	
	question->next = question_3;
}

void question_1(struct question *question) {
	
	float num;
	
	printf("Questão 1: \n");
	
	printf("Digite um numero: ");
	scanf("%f", &num);
	
	if (num >= 100 && num <= 200 ) {
		printf("Dentro do intervalo\n");
	} else {
		printf("Fora do intervalo\n");
	}
	
	question->next = question_2;
}

int main(void) {
	setlocale(LC_ALL, "portuguese");
	setbuf(stdin, NULL);
    setbuf(stdout, NULL);
	
	struct question *question = (struct question*)malloc(sizeof(struct question));
	
	question->next = question_1;
	while(question->next) question->next(question);
	
	return 0;
}

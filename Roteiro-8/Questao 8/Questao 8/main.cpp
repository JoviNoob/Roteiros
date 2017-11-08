// Questao 8.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Imovel.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Terreno.h"

int main()
{
	Imovel *imoveis[5];
	
	imoveis[0] = new Casa(2, 3, 50, 30);
	imoveis[0]->setEndereco("Rua Neymar", "Centro", 50, "Netuna", "54502295");
	imoveis[1] = new Casa(5, 4, 100, 60);
	imoveis[1]->setEndereco("Rua Reus", "Centro", 51, "Netuna", "54502295");
	
	imoveis[2] = new Apartamento("Norte", 400, 2);
	
	imoveis[2]->setEndereco("Rua Griezman", "Centro", 52, "Netuna", "54502295");
	imoveis[3] = new Apartamento("Sul", 400, 2);
	
	imoveis[3]->setEndereco("Rua Messi", "Centro", 53, "Netuna", "54502295");
	imoveis[4] = new Terreno(320);
	imoveis[4]->setEndereco("Rua Ronaldo", "Centro", 54, "Netuna", "54502295");


	
	
	
	
	

	system("PAUSE");
    return 0;
}


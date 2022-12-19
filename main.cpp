#include "proj_dp_ordenada.h"

void menu()
{
	cout<<"Escolha uma das opções abaixo: "<<endl;
	cout<<"1 - Insere ordenado"<<endl;
	cout<<"2 - Remove inicio"<<endl;
	cout<<"3 - Remove fim"<<endl;
	cout<<"4 - Remove elemento"<<endl;
	cout<<"5 - Imprime normal"<<endl;
	cout<<"6 - Imprime reverso"<<endl;
	cout<<"7 - Buscar elemento"<<endl;
	cout<<"Escolha qualquer outro para encerrar o programa"<<endl;
	cout<<"Opção: ";
}

int numb()
{
	int n;
	cout<<"Digite o número que deseja usar: ";
	cin>>n;
	cout<<endl;
	return n;
}

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	Lista* l;
	int op, num;
	
	l = inicializa();
	
	do
	{
		menu();
		cin >> op;
		cout << endl;	
		switch(op)
		{
			case 1:
				num = numb();
				l = insere_ordenado(l, num);
				cout<<endl;
				break;
			
			case 2:
				l = remove_inicio(l);
				cout<<endl;
				break;
			
			case 3:
				l = remove_fim(l);
				cout<<endl;
				break;
			
			case 4:
				num = numb();
				busca_dado(l, num);
				l  = remove_valor(l, num);
				cout<<endl;
				break;
			
			case 5:
				imprime(l);
				cout<<endl;
				break;
			
			case 6:
				imprime_reverso(l);
				cout<<endl;
				break;
			
			case 7:
				num = numb();
				busca_dado(l, num);
				cout<<endl;
				break;
		}
		
	}while(op>=1 && op<=7);
	
	cout<< "Fim do programa\n";
	system("pause");
	return 0;
}

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        cout << "ERRO: Esperando os seguintes parâmetros: ./<nome_do_executável> <diretório_dos_datasets> <modo_de_execução>" << endl;
        cout << "0 - Modo de testes" << endl << "1 - Modo de Benchmark" << endl;
    }
    else
    {
        string directory = argv[1];
        /*
        if(directory.back() != '/')
        {
            directory += '/';
        }
        */

        cout << "Trabalho de Estrutura de Dados II - Parte II" << endl;
        cout << "Diretório: " << directory << endl;
        if(atoi(argv[2]) == 0)
        {
            bool run = true;
            while (run)
            {
                int option;
                int n;
                cout << "Menu:" << endl << "1 - Inserção de N cidades da Quad Tree" << endl << "2 - Inserção de N registros na tabela hash" <<
                endl << "3 - Inserção de N chaves na árvore AVL" << endl << "4 - Inserção de N chaves na árvore B" << endl;
                cout << "Selecione uma opção: ";
                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "Selecione o número de registros a ser inseridos na Quad Tree: ";
                    cin >> n;
                    if(n <= 20)
                    {

                    }
                    else
                    {

                    }
                    break;
                
                case 2:
                    cout << "Selecione o número de registros a ser inseridos na Tabela Hash: ";
                    cin >> n;
                    if(n <= 20)
                    {

                    }
                    else
                    {
                        
                    }
                    break;
                
                case 3:
                    cout << "Selecione o número de chaves a ser inseridos na Árvore AVL: ";
                    cin >> n;
                    if(n <= 20)
                    {

                    }
                    else
                    {
                        
                    }
                    break;
                
                case 4:
                    cout << "Selecione o número de chaves a ser inseridos na Árvore B: ";
                    cin >> n;
                    if(n <= 20)
                    {

                    }
                    else
                    {
                        
                    }
                    break;           
                
                default:
                    cout << "Encerrando execução..." << endl;
                    run = false;
                    break;
                }
            }
        }
        else if(atoi(argv[2]) == 1)
        {

        }
        else
        {
            cout << "Modo Inválido" << endl << "Encerrando execução..." << endl;
        }
    }
    return 0;
}
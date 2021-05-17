#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

struct celular
{
    int id;
    char marca[40];
    char modelo[40];
    int armazenamento;
    float preco;

};

void BuscaPorMarca (fstream &arquivo, char buscaMarca[],  int num_registros)
{
    int auxMensagem=0, cont=0;
    celular busca;
    while ((cont<num_registros))
    {
        arquivo.seekp(cont*sizeof(celular));
        arquivo.read((char*)&busca, sizeof(celular));
        if (strcmp(buscaMarca,busca.marca)==0)
        {
            auxMensagem++;
            if(auxMensagem==1)
            {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "CELULARES DA " << buscaMarca << " CADASTRADOS NO SISTEMA" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cout<<busca.id<<" "<<busca.marca<<" "<<busca.modelo<<" "<<busca.armazenamento<<" "<<busca.preco<<endl;

        }
        cont++;
    }
    if (auxMensagem==0)
    {
        cout<<endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "NENHUM CELULAR ENCONTRADO COM A MARCA INFORMADA" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout<<endl;
    }
}

void BuscaPorModelo (fstream &arquivo, char buscaModelo[],  int num_registros)
{
    int auxMensagem=0, cont=0;
    celular busca;
    while ((cont<num_registros))
    {
        arquivo.seekp(cont*sizeof(celular));
        arquivo.read((char*)&busca, sizeof(celular));
        if (strcmp(buscaModelo,busca.modelo)==0)
        {
            auxMensagem++;
            if(auxMensagem==1)
            {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "CELULARES DA " << buscaModelo << " CADASTRADOS NO SISTEMA" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                auxMensagem++;
            }
            cout<<busca.id<<" "<<busca.marca<<" "<<busca.modelo<<" "<<busca.armazenamento<<" "<<busca.preco<<endl;
            cout << "--------------------------------------------------------------------" << endl;
        }
        cont++;
    }
    if (auxMensagem==0)
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "       NENHUM CELULAR ENCONTRADO COM A ESSE MODELO INFORMADO        " << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }
}

void BuscaPorMemoriaArmz (fstream &arquivo, int buscaMemArmz,  int num_registros)
{
    int auxMensagem=0, cont=0;
    celular busca;
    while ((cont<num_registros))
    {
        arquivo.seekp(cont*sizeof(celular));
        arquivo.read((char*)&busca, sizeof(celular));
        if (busca.armazenamento == buscaMemArmz)
        {
            auxMensagem++;
            if(auxMensagem==1)
            {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "CELULARES DA " << buscaMemArmz << " CADASTRADOS NO SISTEMA" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cout<<busca.id<<" "<<busca.marca<<" "<<busca.modelo<<" "<<busca.armazenamento<<" "<<busca.preco<<endl;
            cout << "--------------------------------------------------------------------" << endl;
        }
        cont++;
    }
    if (auxMensagem==0)
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "NENHUM CELULAR ENCONTRADO COM ESSA MEMORIA INFORMADA" << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }
}


void BuscaPorPreco (fstream &arquivo, int opcao, int num_registros )
{
    celular busca;
    int auxMensagem=0;
    int cont =0;
    if (opcao == 1)
    {
        while ((cont<num_registros))
        {
            arquivo.seekp(cont*sizeof(celular));
            arquivo.read((char*)&busca, sizeof(celular));
            if (busca.preco<=1000)
            {
                auxMensagem++;
                if(auxMensagem==1)
                {
                    cout << "--------------------------------------------------------------------" << endl;
                    cout << "CELULARES DA FAIXA DE PRECO MENOR E IGUAL A 1000 REAIS CADASTRADOS NO SISTEMA" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                }
                cout<<busca.id<<" "<<busca.marca<<" "<<busca.modelo<<" "<<busca.armazenamento<<" "<<busca.preco<<endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cont++;
        }
        if(auxMensagem==0)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout<< "              NAO HA CELULARES NESSA FAIXA DE PRECO                   "<<endl;
            cout << "--------------------------------------------------------------------" << endl;
        }

    }
    if (opcao == 2)
    {
        while ((cont<num_registros))
        {
            arquivo.seekp(cont*sizeof(celular));
            arquivo.read((char*)&busca, sizeof(celular));
            if (busca.preco> 1000 and busca.preco<=3000)
            {
                auxMensagem++;
                if(auxMensagem==1)
                {
                    cout << "----------------------------------" << endl;
                    cout << "CELULARES DA FAIXA DE PRECO MAIOR QUE 1000 REAIS E MENOR E IGUAL A 3000 REAIS CADASTRADOS NO SISTEMA" << endl;
                    cout << "----------------------------------" << endl;
                }
                cout<<busca.id<<" "<<busca.marca<<" "<<busca.modelo<<" "<<busca.armazenamento<<" "<<busca.preco<<endl;
                cout << "----------------------------------" << endl;
            }
            cont++;
        }
        if(auxMensagem==0)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout<< "              NAO HA CELULARES NESSA FAIXA DE PRECO                   "<<endl;
            cout << "--------------------------------------------------------------------" << endl;
        }
    }
    if (opcao == 3)
    {
        while ((cont<num_registros))
        {
            arquivo.seekp(cont*sizeof(celular));
            arquivo.read((char*)&busca, sizeof(celular));
            if (busca.preco>3000)
            {
                auxMensagem++;
                if(auxMensagem==1)
                {
                    cout << "--------------------------------------------------------------------" << endl;
                    cout << "CELULARES DA FAIXA DE PRECO MAIOR QUE 3000 REAIS CADASTRADOS NO SISTEMA" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                }
                cout<<busca.id<<" "<<busca.marca<<" "<<busca.modelo<<" "<<busca.armazenamento<<" "<<busca.preco<<endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cont++;
        }
        if(auxMensagem==0)
        {
            cout << "--------------------------------------------------------------------" << endl;
            cout<< "              NAO HA CELULARES NESSA FAIXA DE PRECO                   "<<endl;
            cout << "--------------------------------------------------------------------" << endl;
        }
    }
}


void Busca(fstream &arquivo, int opcao, int num_registros )
{
    char buscaTipo[40];
    int buscaMemoria, buscaPreco;
    bool aux_preco=false;
    if (opcao==1)
    {
        cout << "DIGITE A MARCA DOS CELULARES QUE VOCE DESEJA VER:"<<endl;
        cin >> buscaTipo;
        BuscaPorMarca(arquivo, buscaTipo, num_registros);
    }
    if (opcao==2)
    {
        cout << "DIGITE O MODELO DOS CELULARES QUE VOCE DESEJA VER:"<<endl;
        cin >> buscaTipo;
        BuscaPorModelo(arquivo, buscaTipo, num_registros);
    }
    if (opcao==3)
    {
        cout << "DIGITE A QUANTIDADE DE MEMORIA DE ARMAZENAMNETO EM GB DOS CELULARES QUE VOCE DESEJA VER:"<<endl;
        cin >> buscaMemoria;
        BuscaPorMemoriaArmz(arquivo, buscaMemoria, num_registros);
    }
    if (opcao==4)
    {
        cout << "DIGITE A OPCAO DE FAIXAS DE PRECO DOS CELULARES QUE VOCE DESEJA VER:"<<endl;
        cout<<endl;
        cout << "1- Celulares ate 1000 reais"<<endl<<"2- Celulares acima de 1000 reais ate 3000"<<endl<<"3 - Celulares acima de 3000 reais"<<endl;
        cin >> buscaPreco;
        if (buscaPreco!=1 and buscaPreco!=2 and buscaPreco!=3)
        {
            while (aux_preco==false)
            {
                cout << "*VOCE DIGITOU UMA OPCAO INVALIDA, DIGITE NOVAMENTE!*"<<endl;
                cin >> buscaPreco;
                if (buscaPreco==1 or buscaPreco==2 or buscaPreco==3 )
                {
                    aux_preco = true;
                    BuscaPorPreco(arquivo, buscaPreco, num_registros);
                }
            }

        }
        else if (buscaPreco==1 or buscaPreco==2 or buscaPreco==3 )
        {
            aux_preco = true;
            BuscaPorPreco(arquivo, buscaPreco, num_registros);
        }

    }
}
void OpcoesDeBusca (fstream &arquivo, int num_registros)
{
    int opcao;
    bool aux_opcao = false;
    cout << "DIGITE O NUMERO DA OPCAO DESEJADA:"<<endl;
    cout << endl;
    cout << "1 - Buscar Celulares por Marca"<<endl;
    cout << "2 - Buscar Celulares por Modelo"<<endl;
    cout << "3 - Buscar Celulares por Armazenamento"<<endl;
    cout << "4 - Buscar Celulares por Faixa de Preco"<<endl;
    cin >> opcao;

    if (opcao!=1 and opcao!=2 and opcao!=3 and opcao!=4)
    {
        while (aux_opcao==false)
        {
            cout << "*VOCE DIGITOU UMA OPCAO INVALIDA, DIGITE NOVAMENTE!*"<<endl;
            cin >> opcao;
            if (opcao==1 or opcao==2 or opcao==3 or opcao==4)
            {
                aux_opcao = true;
                Busca(arquivo, opcao, num_registros);
            }
        }
    }
    else if (opcao==1 or opcao==2 or opcao==3 or opcao==4 )
    {
        aux_opcao = true;
        Busca(arquivo, opcao, num_registros);
    }

}
void Alterar (fstream &arquivo, int num_regs, int id_trocado)
{
    int cont = 0;
    celular novo_celular;
    novo_celular.id = id_trocado;
    cout << "DIGITE A NOVA MARCA, MODELO, ARMAZENAMENTO E PRECO DO CELULAR: "<<endl;
    cin >> novo_celular.marca >> novo_celular.modelo >> novo_celular.armazenamento >> novo_celular.preco;
    bool nao_achou=1;
    celular celular_antigo;
    while ((cont < num_regs)  and (nao_achou) )
    {
        arquivo.seekp(cont*sizeof(celular));
        arquivo.read((char*)(&celular_antigo), sizeof(celular));
        if (celular_antigo.id == id_trocado)
        {
            arquivo.seekp((cont)*sizeof(celular));
            arquivo.write((char*) &novo_celular, sizeof(celular));
            nao_achou=0;
        }
        cont++;

    }
}

void OpcoesdeAltercao (fstream &arquivo, int quantCelulares, int num_regs)
{
    bool aux_alterar = false;
    int opcao;
    cout << "DIGITE O NUMERO DA LISTA DE CELULARES QUE VOCE DESEJA ALTERAR:" << endl;
    cin >> opcao;
    if (opcao>quantCelulares or opcao<=0 )
    {
        while (aux_alterar==false)
        {
            cout << "CELULAR INEXISTENTE, DIGITE NOVAMENTE!"<<endl;
            cin >> opcao;
            if (opcao<=quantCelulares and opcao>0)
            {
                aux_alterar = true;
                Alterar(arquivo, num_regs, opcao);
            }
        }
    }
    else if ( opcao<=quantCelulares and opcao>0)
    {
        aux_alterar = true;
        Alterar(arquivo, num_regs, opcao);
    }
}

void Excluir(fstream& arquivo, int num_regs, int posicao)
{
    celular cel;
    posicao = posicao-1;
    if (posicao !=-1)
    {
        for (int i=posicao+1; i<num_regs; i++)
        {
            arquivo.seekp((i)*sizeof(celular));
            arquivo.read((char*) (&cel), sizeof(celular));
            arquivo.seekp((i-1)*sizeof(celular));
            arquivo.write((char*) (&cel), sizeof(celular));
        }
    }
}


void OpcoesdeExcluir(fstream &arquivo,int quantCelulares, int num_regs )
{
    bool aux_excluir = false;
    int opcao;
    cout << "DIGITE O NUMERO DA LISTA DE CELULARES QUE VOCE DESEJA EXCLUIR:" << endl;
    cin >> opcao;
    if (opcao>quantCelulares or opcao<=0 )
    {
        while (aux_excluir==false)
        {
            cout << "CELULAR INEXISTENTE, DIGITE NOVAMENTE!"<<endl;
            cin >> opcao;
            if (opcao<=quantCelulares and opcao>0)
            {
                aux_excluir = true;
                Excluir(arquivo, num_regs,opcao);
            }
        }
    }
    else if ( opcao<=quantCelulares and opcao>0)
    {
        aux_excluir = true;
        Excluir(arquivo, num_regs, opcao);
    }
}
void listar(fstream &arquivo, int num_regs)
{
    celular cel;
    int cont = 0;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "CELULARES CADASTRADOS NO ESTOQUE" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    while (cont < num_regs)
    {
        arquivo.seekg(cont*sizeof(celular));
        arquivo.read((char *) (&cel),sizeof(celular));
        cout<<cel.id<<" "<<cel.marca<<" "<<cel.modelo<<" "<<cel.armazenamento<<" "<<cel.preco<<endl;
        cont++;
    }
    cout << "--------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << endl;
}
int main()
{
    cout << "--------------------------------------------------------------------" << endl;
    cout << "                    CONTROLE DE ESTOQUE DE CELULARES                " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    int quantCelulares;
    cout << "DIGITE A QUANTIDADE DE CELULARES QUE DESEJA CADASTRAR NO ESTOQUE:" << endl;
    cin >> quantCelulares;
    celular *estoque;
    estoque = new celular[quantCelulares];
    int cont =0;
    cout << "--------------------------------------------------------------------" << endl;
    cout<<endl;
    cout<< "AGORA, PREENCHA AS DESCRICOES DOS CELULARES QUE FOR CADASTRAR COMO NO EXEMPLO, DESCONSIDERANDO OS PARENTESES : "<<endl<<endl;
    cout<< " APPLE(marca_sem_espacos) IPHONE8(modelo_sem_espacos) 128(memoria_em_inteiros) 2800(preco_em_real)"<<endl<<endl;
    for (int i=0; i < quantCelulares; i++)
    {
        cont++;
        cout << "CELULAR DE NUMERO " << cont  << ", DIGITE SUA MARCA, MODELO, TAMANHO DO ARMAZENAMENTO INTERNO e PRECO:"<<endl;
        estoque[i].id = cont;
        cin >> estoque[i].marca;
        cin >> estoque[i].modelo;
        cin >> estoque[i].armazenamento;
        cin >> estoque[i].preco;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "CELULARES CADASTRADOS NO ESTOQUE" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    for (int i=0; i < quantCelulares; i++)
    {
        cout << estoque[i].id << " ";
        cout << estoque[i].marca<<" ";
        cout << estoque[i].modelo<<" ";
        cout << estoque[i].armazenamento<<" ";
        cout << estoque[i].preco<<endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << endl;
    fstream arquivo1("EstoqueDeCelulares.bin", ios::out);
    arquivo1.write((const char *) (estoque), quantCelulares*sizeof(celular));
    arquivo1.close();
    fstream arquivo2("EstoqueDeCelulares.bin", ios::in|ios::out);
    arquivo2.write((const char *) (estoque), quantCelulares*sizeof(celular));

    long int tamanho_bytes = arquivo2.tellg();
    int num_regs = int (tamanho_bytes/sizeof(celular));
    cout << "TAMANHO DO NUM REGISTROS:"<< " "<< num_regs<<endl;
    cout << "--------------------------------------------------------------------" << endl;
    int menuopcao;
    do
    {
        cout << "---------------------------------MENU-------------------------------" << endl;
        cout << "SELECIONE A OPERACAO QUE VOCE DESEJA REALIZAR NO SISTEMA" <<endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "1 - Buscar" << endl;
        cout << "2 - Alterar" << endl;
        cout << "3 - Excluir" << endl;
        cout << "4 - Listar" << endl;
        cout << "5 - Sair" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cin >> menuopcao;
        if(menuopcao == 1)
        {
            OpcoesDeBusca(arquivo2, num_regs);
        }
        if(menuopcao == 2)
        {
            OpcoesdeAltercao(arquivo2, quantCelulares, num_regs);
        }
        if(menuopcao ==3)
        {
            OpcoesdeExcluir(arquivo2, quantCelulares, num_regs);
            quantCelulares -= 1;
            num_regs -= 1;
        }
        if(menuopcao == 4)
        {
            listar(arquivo2, num_regs);
        }
    }
    while(menuopcao!=5);
    cout << "--------------------------------------------------------------------" << endl;
    cout << "                 OBRIGADO POR UTILIZAR NOSSO SISTEMA!               " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout <<endl;
    return 0;
}

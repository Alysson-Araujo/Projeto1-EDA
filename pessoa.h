#ifndef PESSOA_H 
#define PESSOA_H

using std::string;

class Pessoa{
    private:

        long int cpf;

        string nome;
        string sobrenome;

        int nasc_dia;   //
        int nasc_mes;   //  data de nascimento
        int nasc_ano;   //

        string cidade_nasc;  // cidade onde nasceu

    public:

        Pessoa(long int cpf, string nome, string sobrenome, int nasc_dia, int nasc_mes, int nasc_ano, string cidade_nasc);  //construtor

        void imprime_csv(); //imprime todos os dados da pessoa separado por virgula
        int mais_velho_que(Pessoa x); //retorna 0 se a idade for igual, -1 se a pessoa do parâmetro for mais velha e 1 se for mais nova
        string formato_cpf();  // coloca os pontos e traço do cpf

        //gets
        long int get_cpf();
        string get_nome();
        string get_sobrenome();
        int get_nasc_dia();
        int get_nasc_mes();
        int get_nasc_ano();
        string get_cidade_nasc();

};

#endif

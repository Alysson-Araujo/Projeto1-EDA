#ifndef PESSOA_H 
#define PESSOA_H

using std::string;

class Pessoa{
    private:

        string cpf;

        string nome;
        string sobrenome;
        string dataNascimento;
        
        string cidade_nasc;  // cidade onde nasceu

    public:               
        Pessoa();           //
        Pessoa(string cpf, string nome, string sobrenome, string dataNascimento, string cidade_nasc);  //construtor

        void imprime_csv(); //imprime todos os dados da pessoa separado por virgula
        string formato_cpf();  // coloca os pontos e traço do cpf
        
        long int to_long_int(string cpf); //recebe string e retorna long int
        
        long int converte_dia(string x);
        long int converte_mes(string x);
        long int converte_ano(string x);

        //gets
        string get_cpf();
        string get_nome();
        string get_sobrenome();
        int get_nasc_dia();
        int get_nasc_mes();
        int get_nasc_ano();
        string get_cidade_nasc();


        //sets
        void set_cpf(string cpf);
        void set_nome(string nome); 
        void set_sobrenome(string sobrenome);
        void set_cidade_nasc(string cidade_nasc);
        void set_dataNascimento(string data);
        



};

#endif

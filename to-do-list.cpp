#include <iostream>
#include <string>

int main(){
    int i = 1;
    std::string tarefa;
    std::string descricao;
    std::string prioridade [3] {"Alta", "Média", "Baixa"};
    int prazo; //dias
    std::string resp;
    
    while (true)
    {
        tarefa = "Tarefa " + std::to_string(i); 
        std::cout << tarefa << std::endl; 

        std::cout << "Descreva a tarefa: ";
        std::cin >> descricao;

        // std::cin >> prioridade;

        std::cin >> prazo;


        
        // Opção de sair do programa
        std::cout << "Deseja sair do programa? 'Responda com 'SIM' ou 'NÃO" << std::endl;
        std::cin >> resp;
        
        for (auto &c : resp) c = toupper(c);

        if (resp == "SIM")
        {
            break;
        }
    }
        
}
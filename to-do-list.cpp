#include <iostream>
#include <string>
#include <sstream>

bool validaString(const std::string& mstring){ // OK -- Checa se a string está vazia
    if (mstring == ""){
        std::cout << "\nDigite um texto válido!" << std::endl;
        return false;
    }
    return true;
}

bool validaUmDigito(const std::string& mstring){ // OK -- Checa se a string tem mais de um digíto
    if (mstring.length() == 1) {
        return true;
    } else {
        std::cout << "\nDigite apenas um dígito!" << std::endl;
        return false;
    }
}

bool validaInt(const std::string& mstring){ // OK -- Valida se na string tem números
    if(std::isdigit(mstring[0]) == false){
        std::cout << "\nDigite um número!" << std::endl;
        return false;
    } else {
        return true;
    }    
}

bool validaPositivo(const int& minteger){ // OK -- Checa se o valor é positivo
    if (minteger < 0){
        std::cout << "\nDigite um valor positivo!" << std::endl;
        return true;
    } else{
        return false;
    }
}

class Lista {
    // Atributos
    std::string tarefa; // Nome da tarefa
    std::string descricao; //Descrição da tarefa
    std::string prioridade [3] {"Alta", "Média", "Baixa"}; //Opções de prioridade (1 alta, 2 média, 3 baixa)
    int ID_prioridade; // Responsável por armazenar o indice para a prioridade
    int prazo; // Tempo para concluir a tarefa
    bool status; // Status para saber se a atividade foi concluída ou ainda em andamento

    public://Métodos SET
        void setTarefa (std::string _tarefa){
            tarefa = _tarefa;
        }

        void setDescricao (std::string _desc){
            descricao = _desc;
        }

        void setPrioridade (int _prioridade){
            switch (_prioridade) {
            case 1: //ALTA
                ID_prioridade = _prioridade - 1; // prioridade[ID_prioridade];
                break;
            
            case 2: //MÉDIA
                ID_prioridade = _prioridade -1; // prioridade[ID_prioridade];
                break;
            
            case 3: //BAIXA
                ID_prioridade = _prioridade -1; // prioridade[ID_prioridade];
                break;
            
            default:
                break;
            }
        }

        void setPrazo (int _prazo){
            prazo = _prazo;
        }

        void setStatus (bool _status){
            status = _status;
        }
        // Métodos Get
        std::string getTarefa(){
            return tarefa;
        }

        std::string getDescricao(){
            return descricao;
        }

        std::string getPrioridade(){
            return prioridade[ID_prioridade];
        }

        int getPrazo(){
            return prazo;
        }

        std::string getStatus(){
            if (status){
                return "Tarefa em andamento";
            } else {
                return "Tarefa concluída";
            }
        }
        
        // Construtor
        Lista(){}

        bool validaVazio(){
            if (tarefa == "") {
                return false; }
            else if(descricao == "") {
                return false; } 
            else if(ID_prioridade == -1) {
                return false; } 
            else if(prazo == 0) { 
                return false;}
            return true;
        }
};

class ExcluirTarefa {
    public:
        void esvaziar(Lista& _lista){
            _lista.setTarefa("");
            _lista.setDescricao("");
            _lista.setPrioridade(-1);
            _lista.setPrazo(0);
            _lista.setStatus(true);
            std::cout << "Tarefa excluída!" << std::endl;
        }
};

class AtualizarTarefa {
    public: 
        void atualizar (Lista& _lista, int& op){
            std::string mstring;
            int minteger;
            bool condicao;
            switch (op){ // 1 - Nome da tarefa  2 - Descrição  3 - Prioridade  4 - Prazo  5 - Status  6 - Tudo
                case 1:
                    // Nome da tarefa
                    std::cout << "\nQual o nome da tarefa? " << std::endl;
                    std::getline(std::cin, mstring);
                    if (!validaString(mstring)){ // OK -- Checa se a string está vazia
                        break; }
                    _lista.setTarefa(mstring);
                    std::cout << "\nTarefa atualizada!" << std::endl;
                    break;

                case 2:
                    // Descrição da tarefa
                    std::cout << "\nDescreva a tarefa: " << std::endl;
                    std::getline(std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break;} 
                    _lista.setDescricao(mstring);
                    std::cout << "\nTarefa atualizada!" << std::endl;
                    break;

                case 3:
                    // Prioridade da tarefa
                    std::cout << "\nEscolha a prioridade da tarefa.\n1 para ALTA\t2 para MÉDIA\t3 para BAIXA" << std::endl;
                    std::getline (std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break; } 
                    if (!validaUmDigito(mstring)) { // OK -- Checa se a string tem mais de um digíto
                        break; } 
                    if (!validaInt(mstring)) { // OK -- Valida se na string tem números
                        break; }
                    std::stringstream(mstring) >> minteger; // OK -- Conversão de string 
                    if (validaPositivo(minteger)) { // OK -- Checa se o valor é positivo
                        break; }
                    if(0 > minteger > 4) { // OK -- Valida se a opção está dentro do alcance de opções
                        std::cout << "Digite uma opção válida!" << std::endl;
                        break;
                    }
                    _lista.setPrioridade(minteger); 
                    std::cout << "\nTarefa atualizada!" << std::endl;
                    break;

                case 4:
                    // Prazo da tarefa
                    std::cout << "\nDigite quanto tempo a tarefa levará (em dias):" << std::endl;
                    std::getline (std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break; }
                    if (!validaInt(mstring)) { // OK -- Valida se na string tem números
                        break; }
                    std::stringstream(mstring) >> minteger; // OK -- Conversão de string 
                    if (validaPositivo(minteger)) { // OK -- Checa se o valor é positivo
                        break; }
                    _lista.setPrazo(minteger);
                    std::cout << "\nTarefa atualizada!" << std::endl;
                    break;

                case 5:
                    // Status da tarefa
                    std::cout << "\nDigite 'C' para tarefa concluída e 'E' para tarefa em andamento" << std::endl;
                    std::getline (std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break; } 
                    if (!validaUmDigito(mstring)) { // OK -- Checa se a string tem mais de um digíto
                        break; }
                    for (auto &c : mstring) c = toupper(c);  // Transforma toda a string em caractere maiusculo
                    if (mstring == "C") {
                        condicao = false;
                    } else if (mstring == "E"){
                        condicao = true;
                    }
                    _lista.setStatus(condicao);
                    std::cout << "\nTarefa atualizada!" << std::endl;
                    break;

                case 6:
                    // Nome da tarefa
                    std::cout << "\nQual o nome da tarefa? " << std::endl;
                    std::getline(std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break; }
                    _lista.setTarefa(mstring);

                    // Descrição da tarefa
                    std::cout << "\nDescreva a tarefa: " << std::endl;
                    std::getline(std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break; }
                    _lista.setDescricao(mstring);

                    // Prioridade da tarefa
                    std::cout << "\nEscolha a prioridade da tarefa.\n1 para ALTA\t2 para MÉDIA\t3 para BAIXA" << std::endl;
                    std::getline (std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break; }
                    if (!validaUmDigito(mstring)) { // OK -- Checa se a string tem mais de um digíto
                        break; }
                    if (!validaInt(mstring)) { // OK -- Valida se na string tem números
                        break; }
                    std::stringstream(mstring) >> minteger; // OK -- Conversão de string 
                    if (validaPositivo(minteger)) { // OK -- Checa se o valor é positivo
                        break; }
                    if(0 > minteger > 4) { // OK -- Valida se a opção está dentro do alcance de opções
                        std::cout << "Digite uma opção válida!" << std::endl;
                        break;
                    }
                    _lista.setPrioridade(minteger); 

                    // Prazo da tarefa
                    std::cout << "\nDigite quanto tempo a tarefa levará (em dias):" << std::endl;
                    std::getline (std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break; }
                    if (!validaInt(mstring)) { // OK -- Valida se na string tem números
                        break; }
                    std::stringstream(mstring) >> minteger; // OK -- Conversão de string 
                    if (validaPositivo(minteger)) { // OK -- Checa se o valor é positivo
                        break; }
                    _lista.setPrazo(minteger);

                    // Status da tarefa
                    std::cout << "\nDigite 'C' para tarefa concluída e 'E' para tarefa em andamento" << std::endl;
                    std::getline (std::cin, mstring);
                    if (!validaString(mstring)) { // OK -- Checa se a string está vazia
                        break; } 
                    if (!validaUmDigito(mstring)) { // OK -- Checa se a string tem mais de um digíto
                        break; }
                    for (auto &c : mstring) c = toupper(c); // Transforma toda a string em caractere maiusculo
                    if (mstring == "C") {
                        condicao = false;
                    } else if (mstring == "E"){
                        condicao = true;
                    }
                    _lista.setStatus(condicao);

                    std::cout << "\nTarefa atualizada!" << std::endl;
                    break;

                default:
                    std::cout << "\nDigite um valor válido!!!" << std::endl;
                    break;
            }
        }
};

class VisualizadorTarefa {
    // A ideia é ter 3 modos de visualização das tarefas na lista: 
    // 1 para todas as tarefas -- 2 para todas as pendentes -- 3 para todas as concluídas
    public:
        const void display(Lista& _lista){
            std::cout << "\n\tTodas as tarefas:" << std::endl;
            std::cout << "Tarefa: " << _lista.getTarefa() << std::endl;
            std::cout << "Descrição: " << _lista.getDescricao() << std::endl;
            std::cout << "Prioridade: " << _lista.getPrioridade() << std::endl;
            std::cout << "Prazo: " << _lista.getPrazo() << std::endl;
            std::cout << "Status: " << _lista.getStatus() << std::endl;
        }
};

int main(){
    Lista listaTarefas;
    VisualizadorTarefa visualizador;
    ExcluirTarefa excluir;
    AtualizarTarefa atualizador;

    // int controleLista = 0;
    int op; // variável para armazenar o valores das opções
    std::string mstring; // variável utilizada para armazenar strings
    int minteger; // variável utilizada para armazenar valores de números inteiros
    bool condicao = true; // variável utilizada para armazenar valores booleanos

    std::cout << "\n\n\t\t\t\tTo do list - Lista de Tarefas" << std::endl;
    while (condicao)
    {
        std::cout << "\n********************************************************************************************************" << std::endl;
        std::cout << "\n1 - Criar tarefa\t2 - Visualizar tarefas\t3 - Atualizar tarefas\t4 - Excluir tarefa\t5 - Sair\n\nEscolha uma das opções: " << std::endl;
        std::getline (std::cin, mstring);
        if (!validaString(mstring)) // OK -- Checa se a string está vazia
            continue;
        if (!validaUmDigito(mstring)) // OK -- Checa se a string tem mais de um digíto
            continue;
        if (!validaInt(mstring)) // OK -- Valida se na string tem números
            continue;
        std::stringstream(mstring) >> op; // OK -- Conversão de string 
        if (validaPositivo(op)) // OK -- Checa se o valor é positivo
            continue;
        if(0 > op > 6) { // OK -- Valida se a opção está dentro do alcance de opções
            std::cout << "Digite uma opção válida!" << std::endl;
            continue;
        } 

        switch (op) {
        case 1: // Criação de tarefas

            // Nome da tarefa
            std::cout << "\nQual o nome da tarefa? " << std::endl;
            std::getline(std::cin, mstring);
            if (!validaString(mstring)) // OK -- Checa se a string está vazia
                break;
            listaTarefas.setTarefa(mstring);

            // Descrição da tarefa
            std::cout << "\nDescreva a tarefa: " << std::endl;
            std::getline(std::cin, mstring);
            if (!validaString(mstring)) // OK -- Checa se a string está vazia
                break;
            listaTarefas.setDescricao(mstring);

            // Prioridade da tarefa
            std::cout << "\nEscolha a prioridade da tarefa.\n1 para ALTA\t2 para MÉDIA\t3 para BAIXA" << std::endl;
            std::getline (std::cin, mstring);
            if (!validaString(mstring)) // OK -- Checa se a string está vazia
                break;
            if (!validaUmDigito(mstring)) // OK -- Checa se a string tem mais de um digíto
                break;
            if (!validaInt(mstring)) // OK -- Valida se na string tem números
                break;
            std::stringstream(mstring) >> minteger; // OK -- Conversão de string 
            if (validaPositivo(minteger)) // OK -- Checa se o valor é positivo
                break;
            if(0 > minteger > 4) { // OK -- Valida se a opção está dentro do alcance de opções
                std::cout << "Digite uma opção válida!" << std::endl;
                break;
            }
            listaTarefas.setPrioridade(minteger); 

            // Prazo da tarefa
            std::cout << "\nDigite quanto tempo a tarefa levará (em dias):" << std::endl;
            std::getline (std::cin, mstring);
            if (!validaString(mstring)) // OK -- Checa se a string está vazia
                break;
            if (!validaInt(mstring)){ // OK -- Valida se na string tem números
                break;
            }
            std::stringstream(mstring) >> minteger; // OK -- Conversão de string 
            if (validaPositivo(minteger)){ // OK -- Checa se o valor é positivo
                break;
            }
            listaTarefas.setPrazo(minteger);
          
            // Status da tarefa, no momento de criação. Padrão como true
            listaTarefas.setStatus(true);
            // controleLista++;
            break;

        case 2: // Visualizar tarefas
            if (listaTarefas.validaVazio()) { // OK -- Checa se a tarefa não está vazia
                visualizador.display(listaTarefas); // OK -- Mostra as informações da tarefa
            } else {
                std::cout << "\nNão existe nenhuma tarefa!" << std::endl;
                break;
            }
            break;

        case 3: // Atualizar tarefa
            if (listaTarefas.validaVazio()) { // OK -- Checa se a tarefa não está vazia
                std::cout << "\nEscolha o que deseja alterar:\n1 - Nome da tarefa\t2 - Descrição\t3 - Prioridade\t4 - Prazo\t5 - Status\t6 - Tudo" << std::endl;
                std::getline (std::cin, mstring);
                if (!validaString(mstring)) // OK -- Checa se a string está vazia
                    break;
                if (!validaUmDigito(mstring)) // OK -- Checa se a string tem mais de um digíto
                    break;
                if (!validaInt(mstring)) // OK -- Valida se na string tem números
                    break;
                std::stringstream(mstring) >> op; // OK -- Conversão de string 
                if (validaPositivo(op)) // OK -- Checa se o valor é positivo
                    break;
                if(0 > op > 7) {  // OK -- Valida se a opção está dentro do alcance de opções
                    std::cout << "Digite uma opção válida!" << std::endl;
                    break;
                }
                atualizador.atualizar(listaTarefas, op); // OK -- Atualiza as informações da tarefa, baseado na opção escolhida
            } else {
                std::cout << "\nNão existe nenhuma tarefa!" << std::endl;
                break;
            }
            break;

        case 4: // Excluir Tarefa
            if (listaTarefas.validaVazio()) { // OK -- Checa se a tarefa não está vazia
                std::cout << "\nTem certeza que deseja excluir a tarefa? 'S' para sim, 'N' para não.";
                std::getline (std::cin, mstring);
                if (!validaString(mstring)) // OK -- Checa se a string está vazia
                    break;
                if (!validaUmDigito(mstring)) // OK -- Checa se a string tem mais de um digíto
                    break;
                if (std::isdigit(mstring[0])){ // OK -- Valida se na string tem números
                    std::cout << "\nDigite um válor válido! Responda com 'S' ou 'N'!" << std::endl;
                    break; }
                for (auto &c : mstring) c = toupper(c); // Transforma toda a string em caractere maiusculo
                if (mstring == "S")
                    excluir.esvaziar(listaTarefas); // OK -- Exclui as informações da tarefa
            } else {
                std::cout << "\nNão existe nenhuma tarefa!" << std::endl;
                break;
            }
            break;

        case 5:// Opção de sair do programa
            std::cout << "\nDeseja sair do programa? Responda com 'S' para sim, 'N' para não. " << std::endl;
            std::getline (std::cin, mstring);
            if (!validaString(mstring)) // OK -- Checa se a string está vazia
                break;
            if (!validaUmDigito(mstring)) // OK -- Checa se a string tem mais de um digíto
                break;
            if (std::isdigit(mstring[0])){ // OK -- Valida se na string tem números
                std::cout << "\nDigite um válor válido! Responda com 'S' ou 'N'!" << std::endl;
                break; }
            for (auto &c : mstring) c = toupper(c); // Transforma toda a string em caractere maiusculo
            if (mstring == "S")
            {
                condicao = false;
            }
            break;

        default:
            std::cout << "\nDigite um valor válido!!!" << std::endl;
            break;
        }
    }
}
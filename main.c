#include "funcionario.c"
#define fun 10

int main(void)
{

    int op, documento, count_fun = 0;
    char nome[51], cargo[11];

    Funcionario * funcionario [fun];

    FILE *dados_fun = fopen("saida.txt", "r");
    if (dados_fun == NULL)
    {
        printf("Não foi possivel abrir o arquivo .\n");
        exit(-1);
    }
        lerarquivo(dados_fun,  funcionario,  &count_fun);

    do
    {

        printf("MENU DE OPÇÕES \n");
        printf("1 - CADASTRO DE FUNCIONARIOS \n");
        printf("2 - BUSCAR FUNCIONARIO POR NOME: \n");
        printf("3 - BUSCAR FUNCIONARIO POR DOCUMENTO:  \n");
        printf("4 - FINALIZAR O PROGRAMA \n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:

            printf("Digite o nome do funcionario ao qual deseja cadastrar: \n");
            scanf(" %[^\n]", nome);

            printf("Diite o cargo do funcionario ao qual deseja cadastrar: \n");
            scanf(" %[^\n]", cargo);

            printf("Digite o N° de um documento de identificação: \n");
            scanf(" %d", &documento);

            if (count_fun < fun)
            
            {
                funcionario[count_fun] = criarFuncionario(nome, cargo, documento);
                funcionario_salva (funcionario[count_fun]);
                count_fun++;
            }
            else
            {
                printf("Quantidade maxima de funcionario foi atingido! ");
            }
            break;

        case 2:

           printf("Digite o nome do funcionario ao qual deseja fazer uma busca \n");
           scanf(" %[^\n]", nome);
                       
          Funcionario * func = buscaLinearnome (count_fun , funcionario, nome );
          if (func != NULL){
                printf("/n Funcionario encontrado ! \n");
                printf("Nome: %s\n", func->nome);
                printf("Documento: %d\n", func->documento);
                printf("Cargo: %s\n", func->cargo);
            }
            else {
                printf("Funcionario não encontrado! \n");
            }
        break;

        case 3:

           printf("Digite o documento do funcionario ao qual deseja fazer uma busca \n");
           scanf(" %d", documento);
            
            funcionario  func = buscaLineardocumento(count_fun, funcionario, documento);
            if(func != NULL){
                printf("/n Funcionario encontrado ! \n");
                printf("Nome: %s\n", func->nome);
                printf("Documento: %d\n", func->documento);
                printf("Cargo: %s\n", func->cargo);
            }
            else{
                printf ("Funcionario nao encontrado ! \n");
            }
            
            

            break;

            case 4:

            printf("Finalizar programa");

            break;

        default:

            printf("Tente novamente, opcao fornecida está incorreta! \n");
        }
    } while (op !=4);
    return 0;
}

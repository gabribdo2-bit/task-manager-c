#include <stdio.h>

void adicionarTarefa(){
    char tarefa[100];
    printf("Digite uma tarefa: ");
    scanf(" %99[^\n]", tarefa);
    printf("A tarefa registrada: %s\n", tarefa);

    FILE *file;
    file = fopen("tarefas.txt", "a");
    if(file == NULL){
        printf("Erro ao abrir o arquivo.");

        return;
    }
    fprintf(file, "%s\n", tarefa);
    fclose(file);
}

void exibirTarefas(){
    FILE *file;
    file = fopen("tarefas.txt", "r");
    char linha[200];
    if (file == NULL){
        printf("Nao foram cadastradas tarefas!\n");
        return;
    }
   int cont = 1;
   while (fgets(linha, sizeof(linha), file) != NULL){
    printf("Tarefa %d: %s\n", cont, linha);
    cont++;
   }
   if (cont == 1){
    printf("Nenhuma tarefa foi cadastrada!\n");
   }
   
   fclose(file);
}

void removerTarefa(){
    FILE *arquivo, *newtarefa;
arquivo = fopen("tarefas.txt", "r");
if (arquivo == NULL){
    printf("Nao ha tarefas cadastradas!\n");
    return;
}

newtarefa = fopen("novoArquivo.txt", "w");
char linha2[200];
int cont = 1;
int remov;
printf("Digite o numero da tarefa que voce deseja remover: ");
scanf(" %d", &remov);
for(; fgets(linha2, sizeof(linha2), arquivo) != NULL; cont++){
    if (cont == remov){
        continue;
    }else{
        fprintf(newtarefa, "%s", linha2);
    }

    }
    fclose(arquivo);
    fclose(newtarefa);

    remove("tarefas.txt");
    rename("novoArquivo.txt", "tarefas.txt");
    printf("Tarefa removida com sucesso!");
}

void menu(){
    int escolha;
    while (1){
        printf("==== Escolha uma opcaoo ====\n" );
        printf("1. Adicionar tarefa\n");
        printf("2. Exibir tarefas\n");
        printf("3. Remover tarefas\n");
        printf("4. Sair do programa\n");

        printf("Escolha:");
        scanf(" %d", &escolha);
        if (escolha == 1){
                adicionarTarefa();
        }
        else if(escolha == 2){
            exibirTarefas();
        }
        else if (escolha == 3){
            removerTarefa();
        }
        else if (escolha == 4){
            break;    
        }else{
            printf("Numero invalido");
        }
    }
}

int main(){
    menu();

    return 0;
}
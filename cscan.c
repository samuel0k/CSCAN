#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strcspn

// Cores ANSI
#define RESET   "\033[0m"
#define VERDE   "\033[32m"   // Cor verde

void print_logo() {
    printf(VERDE "⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⣶⣶⣤⣤⣤⣤⣤⣤⣤⣶⣶⣶⣶⣶⣶⣦⣤⣤⡀\n" RESET);
    printf(VERDE "⢸⣿⣿⣿⣿⣿⣿⡿⢿⣿⡿⠟⢻⣿⣿⡟⠛⠛⠛⠉⠙⠛⠋⠀⠈⠉⠀⠈⠉⠁\n" RESET);
    printf(VERDE "⢸⣿⠿⠟⠋⠉⠀⢀⣾⡿⠉⠀⠈⠸⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" RESET);
    printf(VERDE "⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠹⣿⣷⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" RESET);
    printf(VERDE "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" RESET);
}

void scan_network(const char *interface) {
    printf(VERDE "[+] Escaneando a rede na interface: %s\n" RESET, interface);
    char command[100];
    snprintf(command, sizeof(command), "sudo arp-scan --interface=%s --localnet", interface);
    system(command);
}

void list_network_interfaces() {
    printf(VERDE "Listando interfaces de rede disponíveis:\n" RESET);
    system("ip -o link show | awk -F': ' '{print NR\": \"$2}'");
}

int main() {
    print_logo();
    printf(VERDE "Samuel Kusancke\n" RESET);
    printf(VERDE "Versão 1.0\n\n" RESET);

    // Listar todas as interfaces de rede dinamicamente
    list_network_interfaces();

    int choice;
    printf("Digite o número da interface de rede que deseja usar: ");
    scanf("%d", &choice);

    // Obtenha o nome da interface baseado na escolha do usuário
    char command[100];
    snprintf(command, sizeof(command), "ip -o link show | awk -F': ' '{if (NR==%d) print $2}'", choice);

    // Abrir o pipe para capturar a saída do comando
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf(VERDE "Erro ao obter a interface de rede.\n" RESET);
        return 1;
    }

    // Captura o nome da interface escolhida
    char interface[20];
    if (fgets(interface, sizeof(interface), fp) == NULL) {
        printf(VERDE "Escolha inválida!\n" RESET);
        pclose(fp);
        return 1;
    }
    pclose(fp);

    // Remover nova linha no final do nome da interface, se houver
    interface[strcspn(interface, "\n")] = 0;

    // Executar o escaneamento
    scan_network(interface);

    return 0;
}

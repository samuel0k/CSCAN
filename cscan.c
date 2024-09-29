#include <stdio.h>
#include <stdlib.h>

// Cores ANSI
#define RESET   "\033[0m"
#define ROXO    "\033[35m"  // Cor roxa
#define LARANJA "\033[38;5;214m" // Cor laranja
#define VERDE   "\033[32m"   // Cor verde
#define AZUL    "\033[34m"   // Cor azul

void print_logo() {
    printf(ROXO "⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⣶⣶⣤⣤⣤⣤⣤⣤⣤⣶⣶⣶⣶⣶⣶⣦⣤⣤⡀\033[38;5;214m⠀⣶⠀\n" RESET);
    printf(ROXO "⢸⣿⣿⣿⣿⣿⣿⡿⢿⣿⡿⠟⢻⣿⣿⡟⠛⠛⠛⠉⠙⠛⠋⠀⠈⠉⠀⠈⠉⠁\n" RESET);
    printf(ROXO "⢸⣿⠿⠟⠋⠉⠀⢀⣾⡿⠉⠀⠈⠸⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" RESET);
    printf(ROXO "⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠹⣿⣷⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" RESET);
    printf(ROXO "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" RESET);
}

void scan_network(const char *interface) {
    printf(VERDE "[+] Escaneando a rede na interface: %s\n" RESET, interface);
    char command[100];
    snprintf(command, sizeof(command), "sudo arp-scan --interface=%s --localnet", interface);
    system(command);
}

int main() {
    print_logo();
    printf(VERDE "Samuel Kusancke\n" RESET);
    printf(VERDE "Versão 1.0\n\n" RESET);

    // Listando interfaces de rede
    const char *interfaces[] = {"lo", "enp4s0", "wlp2s0", "wlx503eaad6d97d"};
    int num_interfaces = sizeof(interfaces) / sizeof(interfaces[0]);

    for (int i = 0; i < num_interfaces; i++) {
        printf(AZUL "%d: %s\n" RESET, i + 1, interfaces[i]);
    }

    int choice;
    printf("Digite o número da interface de rede que deseja usar: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > num_interfaces) {
        printf(VERDE "Escolha inválida!\n" RESET);
        return 1;
    }

    // Executar o escaneamento
    scan_network(interfaces[choice - 1]);

    return 0;
}

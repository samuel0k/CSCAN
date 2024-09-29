# 📡 cscan - Scanner de Rede

Bem-vindo ao **cscan**, um scanner de rede simples escrito em C que permite identificar dispositivos conectados à sua rede local. Este projeto é uma ferramenta útil para administradores de rede e entusiastas de segurança.

## ⚙️ Como Compilar

Para compilar o projeto, siga os passos abaixo:

1. Abra o terminal.
2. Navegue até o diretório do projeto:

   ```bash
   git clone https://github.com/samuel0k/CSCAN.git

    Compile o código-fonte usando o gcc:

    bash

    gcc -o cscan cscan.c

🚀 Como Executar

Após compilar, você pode executar o programa usando:

bash

sudo ./cscan

🛠️ Dependências

Certifique-se de ter as seguintes dependências instaladas:

    gcc (GNU Compiler Collection)
    arp-scan (para realizar o escaneamento ARP)

Para instalar o arp-scan, você pode usar:

bash

sudo apt-get install arp-scan

📜 Informações do Projeto

    Autor: Samuel Kusancke
    Versão: 1.0
    Licença: MIT

📞 Contribuições

Se você gostaria de contribuir com este projeto, sinta-se à vontade para abrir uma issue ou enviar um pull request! 😊
💻 Demonstração

Aqui está um exemplo de como o programa se parece ao ser executado:

kotlin

$ sudo ./cscan

⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⣶⣶⣤⣤⣤⣤⣤⣤⣤⣶⣶⣶⣶⣶⣶⣦⣤⣤⡀⠀⣶⠀
⢸⣿⣿⣿⣿⣿⣿⡿⢿⣿⡿⠟⢻⣿⣿⡟⠛⠛⠛⠉⠙⠛⠋⠀⠈⠉⠀⠈⠉⠁
⢸⣿⠿⠟⠋⠉⠀⢀⣾⡿⠉⠀⠈⠸⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠹⣿⣷⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ 
Samuel Kusancke
Versão 1.0

Interfaces de Rede Disponíveis:
Selecione uma interface pelo número:
1: lo
2: enp4s0
3: wlp2s0
4: wlx503eaad6d97d
Digite o número da interface de rede que deseja usar: 2
[+] Escaneando a rede na interface: enp4s0
Resultados do escaneamento:
Interface: enp4s0, type: EN10MB, MAC: 44:87:fc:2b:48:32, IPv4: 192.168.1.109
192.168.1.1	30:16:9d:0c:4c:b2	(Unknown)
192.168.1.101	b0:4e:26:e3:90:03	TP-LINK TECHNOLOGIES CO.,LTD.
192.168.1.105	ae:3f:f1:a2:ad:5e	(Unknown: locally administered)
192.168.1.102	48:8f:4c:38:40:c1	shenzhen trolink  Technology Co.,Ltd
192.168.1.100	60:fb:00:77:9e:43	SHENZHEN BILIAN ELECTRONIC CO.，LTD

🎉 Agradecimentos

Agradecemos a todos que contribuíram para o desenvolvimento deste projeto. Divirta-se usando o cscan! 🎈

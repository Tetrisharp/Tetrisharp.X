# Tetrisharp.X - Tetris em MPLAB para PIC Microcontroller

## Descrição

Este é um projeto de Tetris implementado para microcontroladores PIC usando o **MPLAB X IDE** e o **XC8 Compiler**. O jogo foi desenvolvido para rodar em dispositivos embarcados da Microchip, proporcionando uma experiência de jogo no estilo clássico de Tetris com controles simples.

## Tecnologias Utilizadas

- **MPLAB X IDE**: Ambiente de desenvolvimento integrado para microcontroladores PIC.
- **XC8 Compiler**: Compilador C da Microchip para desenvolvimento em PIC.
- **PIC16F877A** (ou microcontroladores similares): Microcontrolador utilizado para a execução do projeto.
- **LCD** (opcional): Display de 16x2 ou qualquer display LCD compatível para exibir o jogo.

## Pré-requisitos

Antes de começar, certifique-se de ter os seguintes softwares e ferramentas instalados:

- **MPLAB X IDE** (versão recomendada: 5.x ou superior) - [Link de Download](https://www.microchip.com/mplab/mplab-x-ide)
- **XC8 Compiler** (versão recomendada: 2.x ou superior) - [Link de Download](https://www.microchip.com/mplab/compilers)
- **Programador PIC** (ex: PICkit 3, PICkit 4 ou outro compatível) para gravar o código no microcontrolador.

## Estrutura do Repositório

O repositório contém a seguinte estrutura:

````
Tetrisharp.X/
├── README.md            # Este arquivo
├── Tetrisharp.X/        # Diretório do projeto MPLAB X
│   ├── Tetrisharp.X.mcp # Arquivo do projeto MPLAB
│   ├── source/          # Código-fonte do projeto
│   ├── header/          # Arquivos de cabeçalho
│   ├── libs/            # Bibliotecas e drivers
│   ├── assets/          # Recursos gráficos (se necessário)
│   └── makefile         # Arquivo de build (opcional)
└── docs/                # Documentação adicional (se houver)
````

## Instalação e Configuração

1. **Clone este repositório**:

``
git clone https://github.com/Tetrisharp/Tetrisharp.X.git
cd Tetrisharp.X
``
2. Abra o projeto no MPLAB X IDE:
- No MPLAB X, abra o arquivo Tetrisharp.X.mcp localizado na pasta do projeto.

3. Configure o microcontrolador:
- Certifique-se de que o microcontrolador correto está selecionado no projeto. Para isso, vá em Project Properties > PIC16F877A (ou o PIC que você está utilizando).

4. Compilação:
- Compile o projeto clicando no botão de "Build" (ícone de martelo) na interface do MPLAB X.

5. Gravação no microcontrolador:
- Conecte seu programador PIC (ex: PICkit 3) ao computador e ao microcontrolador.
- Gravar o firmware no microcontrolador com o MPLAB X IDE.

6. Conectar o display LCD (opcional):
- Caso esteja utilizando um display LCD para exibir o jogo, conecte-o ao microcontrolador conforme as especificações do projeto. O código foi projetado para funcionar com um display LCD de 16x2 padrão, mas pode ser adaptado para outros displays.

## Jogo
O jogo Tetris pode ser jogado diretamente no display LCD conectado ao microcontrolador. Utilize os botões conectados ao microcontrolador para controlar o movimento das peças:

- Setas para Cima: Rotacionar a peça.
- Setas para Direita/Esquerda: Mover a peça para a direita ou esquerda.
- Seta para Baixo: Acelerar o movimento da peça.
- Botão de Iniciar: Começar um novo jogo.

## Como Contribuir
Fork o repositório.
1. Crie uma nova branch para sua modificação (``git checkout -b feature/nova-funcionalidade``).
2. Faça suas alterações e commit (``git commit -am 'Adiciona nova funcionalidade'``).
3. Envie para o repositório remoto (``git push origin feature/nova-funcionalidade``).
4. Abra um Pull Request.

## Licença
Este projeto está licenciado sob a licença MIT - veja o arquivo LICENSE para mais detalhes.


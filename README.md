# ESP8266_RTOS_SDK
Exemplo de programas para o ESP8266 utilizando RTOS SDK

## Fontes

Fonte 1 [ESP8266 RTOS SDK - Get Started](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html)

Fonte 2 [Standard Setup of Toolchain for Linux](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/linux-setup.html)

## Install Prerequisites

$ sudo apt-get install gcc git wget make python3 libncurses-dev flex bison gperf

$ sudo ln -s /usr/bin/python3 /usr/bin/python

## Toolchain Setup

$ cd Downloads

$ wget https://dl.espressif.com/dl/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz

$ alias python=python3

$ cd ~

$ mkdir -p ~/esp

$ cd ~/esp

$ tar -xzf ~/Downloads/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz

$ sudo nano ~/.profile

Adicione a seguinte linha no final do arquivo:

export PATH="$PATH:$HOME/esp/xtensa-lx106-elf/bin"

Salve, saia do arquivo

$ alias get_lx106='export PATH="$PATH:$HOME/esp/xtensa-lx106-elf/bin"'

### Criando a variável de ambiente IDF_PATH

$ sudo nano ~/.bashrc

Adicione a seguinte linha no final do arquivo:

export IDF_PATH=$HOME/esp/ESP8266_RTOS_SDK

Salve, saia do arquivo e digite o seguinte comando:

$ source ~/.bashrc

Faça login

Para ver se os caminhos e a variável foram salvas, digite os seguintes comandos:

$ printenv PATH

$ printenv

Veja se o caminho foi adicionado

$ sudo usermod -a -G dialout $USER


## Get ESP8266_RTOS_SDK

$ cd ~/esp

$ git clone --recursive https://github.com/espressif/ESP8266_RTOS_SDK.git


## Install the Required Python Packages

$ python3 -m pip install --user -r $IDF_PATH/requirements.txt

## Criando um projeto

- Copie o conteúdo da pasta "base" para a pasta do projeto;
- Renomeie o nome da pasta "base" para o nome desejado;

### para configurar:

$ make menuconfig

Na tela que aparecer, salve o arquivo de configuração

### para compilar:

$ make

o binário será gerado na pasta build

### para copiar para o microcontrolador:

$ make flash

OBS: Caso ocorra algum erro, digite o seguinte comando:

$ sudo chmod -R 777 /dev/ttyUSB0

### serial monitor através do terminal:

$ make monitor

obs: para sair: Ctrl + ]

### para limpar os arquivos de compilação:

$ make clean

### para fazer tudo ao mesmo tempo:
$ make -j4 flash monitor

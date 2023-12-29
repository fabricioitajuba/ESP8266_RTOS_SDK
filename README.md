# ESP8266_RTOS_SDK
Exemplo de programas para o ESP8266 utilizando RTOS SDK

# Instalação
https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html
https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/linux-setup.html

### Install Prerequisites

$ sudo apt-get install gcc git wget make python3 libncurses-dev flex bison gperf

$ sudo ln -s /usr/bin/python3 /usr/bin/python

### Toolchain Setup

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

- Criando a variável de ambiente IDF_PATH

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


## Start a Project (Exemplo Hello-World)

$ cd ~/esp

$ cp -r $IDF_PATH/examples/get-started/hello_world .

## Configure

$ cd ~/esp/hello_world

$ make menuconfig

Conectar a placa

$ sudo chmod -R 777 /dev/ttyUSB0

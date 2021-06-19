# Projeto de SOCKETS
## _Atividade de Sala_

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

Projeto apresentado para o curso de Engenharia de Software na UniAmérica, para a disciplina de Socket de rede UDP/TCP usando cliente/servidor

## Features

- Estudar sobre como funciona sockets de redes;
- Implementar um socket em UDP e outro em TCP usando C ou C++
- Apresentar a didatica e funcinamento de um socket.

## Development

Para iniciar o desenvolvimento, é necessário clonar o projeto do GitHub num diretório de sua preferência:

```shell
cd "diretorio de sua preferencia"
git clone https://github.com/condessalovelace/mavenquickstart
```

## Installation

Requer [GCC](https://gcc.gnu.org/) v9.3.0+ para ser executado.

Gerando e executando o servidor...

```shell
gcc server.c -o server

./server PORT
```

Gerando e executando o client...

```shell
gcc client.c -o client

./client URL_SERVER PORT
```

## License

Não se aplica.
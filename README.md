# CPP Rest SDK Demo

Cómo implementar una API REST utilizando la SDK [cpprestsdk](https://github.com/microsoft/cpprestsdk) de Microsoft.

## Requerimientos

Paquetes de Ubuntu requeridos:
* build-essential
* git
* cmake
* autoconf
* libtool
* pkg-config
* libcpprest-dev
* libcpprest

La demo se ha creado mediante una imagen de Ubuntu en Docker.

El test de llamada se ha programado utilizando las bibliotecas *requests* y *unittest* de Python.

## Ficheros

Ficheros necesarios para la compilación, ejecución y testeo:
* CMakeLists.txt: Descripción de la compilación.
* Dockerfile: Descripción de la imagen Docker.
* main.cpp: Servidor API REST a ejecutar.
* tests/test.py: Llamada al servidor REST API.

## Instalación

Clonar el repositorio de github:
```bash
git clone https://github.com/rojo1997/cpprestapi.git
cd cpprestapi
```

Construir la imagen Docker:
```bash
docker build --pull --rm -f "Dockerfile" -t cpprestapi:latest
```

Para ejecutar la imagen Docker:
```bash
docker run --rm -d cpprestapi:latest
```
FROM ubuntu as cpprestapi
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    apt-get install -y \
        build-essential \
        git \
        cmake \
        autoconf \
        libtool \
        pkg-config \
        libcpprest-dev \
        libcpprest
COPY . /cpprestapi
WORKDIR /cpprestapi
RUN cmake . && make
CMD ["./main"]
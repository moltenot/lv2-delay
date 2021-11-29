FROM debian:stable

RUN apt update  && \
    apt install -y \
        build-essential \
        vim \
        libfftw3-dev \
        lv2-c++-tools \
        pkg-config


RUN mkdir code

WORKDIR /code/
CMD [ "/usr/bin/make", "bundle" ]
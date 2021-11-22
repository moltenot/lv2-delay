FROM debian:stable

RUN apt update  && \
    apt install -y \
        build-essential \
        vim


RUN mkdir code

CMD ["./bin/bash"]